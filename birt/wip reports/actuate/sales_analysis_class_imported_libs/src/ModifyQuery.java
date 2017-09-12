/*************************************************************
* The ModifyQuery class
*************************************************************/
/*************************************************************
* The com.f1j.data package contains the DataSourceCollection
* and DataQueryCollection classes.
*************************************************************/
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.Date;

import javax.swing.JOptionPane;
import com.f1j.data.*;
/*************************************************************
* The following import is necessasry for the DataQuery and
* DatabaseQuery classes.
*************************************************************/
import com.f1j.data.query.*;
/*************************************************************
* The com.f1j.data.source package contains the Source class.
*************************************************************/
import com.f1j.data.source.*;
import com.f1j.ss.report.*;
import com.f1j.ss.*;
import com.f1j.ss.Constants;
import com.f1j.ss.SelectionException;
import com.f1j.util.F1Exception;
import com.actuate.util.*;
import com.actuate.util.Logger;
//import messages.*;
public class ModifyQuery implements ReportCallback {
        boolean pmListEmpty = false;
        boolean deptListEmpty = false;
        String debugMsgs = "Debug Messages";
        String errMsgs = "Error Messages";
        String startDateConcat = "";
        String endDateConcat = "";
        Date startDateDisplay;
        String startDateDisplayString = "";
        String start;
        String displayedStart;
        String end;
        String headercell;
        int numsheets;
        int numqueries;
        int adjustmentSheet = -1;
        int regionMonthly = 0;
        static private Logger logger = Logger.getPackageLogger( ModifyQuery.class.getName() );
    public void end(BookModel bk, Object obj) {
        try {
        bk.getLock();
    	bk.setPrintTitles("$A$1:$A$" + Constants.kMaxRow);
    	//test class change

        numsheets = bk.getNumSheets();
                for(int i=0; i<numsheets; i++) {
                        headercell = bk.getText(i, 0, 0);
                        if(bk.getSheetName(i).contains("RegionMonthly") || bk.getSheetName(i).contains("PMMonthly"))
                        	addYearToRows(bk, i);
                        if(bk.getSheetName(i).contains("DeptAdjDetail"))
                            departmentAdjustment(bk, i);
                        	regionMonthly = i;
                        	
                        	
                        	
                        }
                for(int i=0; i<numsheets; i++) {
                	bk.setSheet(i);
                	bk.setPrintTitles("$1:$2");
                	if(bk.getSheetName(i).contains("RegionMonthly")) {
                		this.calculateMonthlyAverage(bk, i);
                	}
                	
                	if(bk.getSheetName(i).contains("DepartmentalAdj")) {
                		this.deptAdjVariance(bk, i);
                	}
                }
                
                
                        
                        
                
                bk.setSheet(regionMonthly); 
        }
        catch(Exception e) {
                e.printStackTrace();
        }
        finally{
        	
                bk.releaseLock();
        }
    }
private void departmentAdjustment(BookModel bk, int sheet) {
		try {
			bk.setSheet(sheet);
			int numRows = bk.getLastRow();
			ArrayList<Integer> rowsIn = new ArrayList();
			for(int i=2; i<numRows; i++) {
				/*if(bk.getEntry(i, 7).equals("XITCO")) {
					System.out.println("!!!!!error found!!!!");
					System.out.println("+4:" +  bk.getEntry(i+4,1));
					System.out.println("+3:" +  bk.getEntry(i+3,1));
					System.out.println("+2:" +  bk.getEntry(i+2,1));
					System.out.println("+1:" +  bk.getEntry(i+1,1));
				}*/
				
				if(i!=0 && bk.getEntry(i,1).equals("") && bk.getEntry((i+1),1).equals("-->") && bk.getEntry((i-1),7).equals("Net Allocation")) {
					System.out.println("No Total in row here.  Insert an empty one." + (i+1));
					RowObject totalInRow = new RowObject("","","","","","","","Total In","","0","0","0","0");
					this.addRowToSheet(bk, sheet, i+1, totalInRow);
				}
				if(i!=0 && bk.getEntry(i,1).equals("") && bk.getEntry((i-1), 1).equals("<--")) {
					System.out.print("\nEnd <-- at " + (i+1));
					rowsIn.add((i+1));
					if(bk.getEntry((i+1),1).equals("")) {
						System.out.print(". No entries out.  Insert empty row and net allocation at " + (i+2));
						RowObject totalInRow = new RowObject("","","","","","","","Total In","",bk.getEntry(i,9),bk.getEntry(i,10),bk.getEntry(i,11),bk.getEntry(i,12));
						this.addRowToSheet(bk, sheet, i, totalInRow);
						RowObject totalOutRow = new RowObject("","","","","","","","Total Out","","0","0","0","0");
						this.addRowToSheet(bk, sheet, i+2, totalOutRow);
						String bookingsAlloc = new String("=J"+(i+1)+"- J"+(i+3));
						String backlogAlloc = new String("=K"+(i+1)+"- K"+(i+3));
						String revenueAlloc = new String("=L"+(i+1)+"- L"+(i+3));
						String profitAlloc = new String("=M"+(i+1)+"- M"+(i+3));
						RowObject netAllocationRow = new RowObject("","","","","","","","Net Allocation","",bookingsAlloc,backlogAlloc,revenueAlloc,profitAlloc);
						this.addRowToSheet(bk, sheet, i+3, netAllocationRow);
						
						
					}
					if(bk.getEntry(i+1,1).equals("-->") && bk.getEntry(i-1,1).equals("<--")) {
						
						RowObject totalInRow = new RowObject("","","","","","","","Total In","",bk.getEntry(i,9),bk.getEntry(i,10),bk.getEntry(i,11), bk.getEntry(i,12));
						this.addRowToSheet(bk, sheet, i, totalInRow);
					}
				}
				if(i!=0 && bk.getEntry(i,1).equals("") && bk.getEntry((i-1), 1).equals("-->")) {
					RowObject totalOutRow = new RowObject("","","","","","","","Total Out","",bk.getEntry(i,9),bk.getEntry(i,10),bk.getEntry(i,11),bk.getEntry(i,12));
					this.addRowToSheet(bk, sheet, i, totalOutRow);
					int totalRowInIndex = 0;
					int totalRowOutIndex = 0;
					for(int j=i; j>0; j--) {
						if(bk.getEntry(j,7).equals("Total Out"))
							totalRowOutIndex = (j+1);
						if(bk.getEntry(j,7).equals("Total In")) {
							totalRowInIndex = (j+1);
							break;
						}
					}
					String bookingsAlloc = new String("=J" + totalRowInIndex + "- J" + totalRowOutIndex );
					String backlogAlloc = new String("=K" + totalRowInIndex + "- K" + totalRowOutIndex );
					String revenueAlloc = new String("=L" + totalRowInIndex + "- L" + totalRowOutIndex );
					String profitAlloc = new String("=M" + totalRowInIndex + "- M" + totalRowOutIndex );
					RowObject netAllocationRow = new RowObject("","","","","","","","Net Allocation","",bookingsAlloc,backlogAlloc,revenueAlloc,profitAlloc);
					this.addRowToSheet(bk, sheet, (i+2), netAllocationRow);
				}
			}
		} catch (F1Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
	}
/*************************************************************
* Use the start( ) method for code that modifies the query that
* populates the workbook.
*************************************************************/
        public void start(BookModel bk, Object obj) {
        try {
            bk.getLock();
/*************************************************************
*               To get a SQL statement for a query, perform the following
*               steps:
*               1. Get the data source collection from the BookModel
*                       object.
*               2. Get an array of Source objects representing the data
*                       sources from the data source collection.  If there
*                       exists a data cache, the first data source is the second
*                       element in the array.  If there is no cache, the first
*                       data source element is the zeroth element.
*               3. Get a collection of Data Queries from one of the Source
*                       objects (the zeroth one in this case).
*               4. Get an array of data queries from the
*                               DataQueryCollection object.
*               5. Cast one of the data queries (the zeroth on in this
*                       case) as a DatabaseQuery object.
*               6. Get the SQL statement from the DataBaseQuery object.
*************************************************************/
                DataSourceCollection dsc = bk.getDataSourceCollection();
                numsheets = bk.getNumSheets();
               
                        Source[] src = dsc.get();
                       
                       
                        int position;
                        if(dsc.hasDataSetCache())
                                position=1;
                        else position = 0;
                        DataQueryCollection dqc =
                                src[position].getDataQueryCollection();
                        DataQuery dq[] = dqc.get();
                        numqueries = dq.length;
                        for(int j=0; j<numqueries; j++) {
                        	DatabaseQuery dbq = (DatabaseQuery) dq[j];
                        	String sql = dbq.getQuery();
                        	String coid = bk.getDefinedName("COID");
                        	if(!coid.equals("ACCO")) {
                        		sql = sql.replace("ACCO", coid);
                        	}
                       // System.out.println("query is: " + sql);
/*************************************************************
* Get the value of a defined name
*************************************************************/
                        start = bk.getDefinedName("startDate");
                        end = bk.getDefinedName("endDate");
                        Calendar calendar = Calendar.getInstance();
                        
                        SimpleDateFormat sdf = new SimpleDateFormat("MM/dd/yyyy");
                        Date startDateParam = sdf.parse(start);
                        calendar.setTime(startDateParam);
                        calendar.add(Calendar.DAY_OF_YEAR, 1);
                        startDateDisplay = calendar.getTime(); 
                        startDateDisplayString = sdf.format(startDateDisplay);
                       
                        try {
                        String[] dates = parseDates(start, end);
                        startDateConcat = dates[0];
                        endDateConcat = dates[1];
                        }
                        catch(Exception e) {
                                JOptionPane.showMessageDialog(null, "Error: Invalid date syntax.");
                                System.exit(-1);
                        }
                        
                       
                       
                        //JOptionPane.showMessageDialog(null, sql);
/*************************************************************
* Test userName for a specific value, and conditionally add a
* new WHERE clause to the SQL statement.
*************************************************************/
                        /*if (userName.equalsIgnoreCase("Pierre")) {
*//*************************************************************
* Find the WHERE clause in the SQL statement. Assume that the
* WHERE clause comes at the end of the statement, if at all,
* and truncate the SQL statement in preparation for appending a
* new WHERE clause.
*************************************************************//*
                                int lastIndex = sql.toLowerCase().lastIndexOf(
                                                "where");
                                if(lastIndex != -1){
                                        sql = sql.substring(0, lastIndex);
                                }
                                sql = sql + " WHERE state = 'MA'";
                        }
*//*************************************************************
* Make the new SQL statement active by setting the SQL
* statement as the query in the DataBaseQuery object.
*************************************************************//*
                       
                       
                        dbq.setQuery(sql,false);*/
                        //int startDate = Integer.parseInt(start);
                        //int endDate = Integer.parseInt(end);
                        //sql = new String("CALL pqs.socj_DetailACCO(\"" + startDateConcat +"\",\"" + endDateConcat +"\")");
                        sql = sql.replace("param1", startDateConcat);
                        sql = sql.replace("param2", endDateConcat);
                       // System.out.println(sql);
                        dbq.setQuery(sql, false);
                       System.out.println("Executing query: " + dbq.getQuery());
                        }
                       
                numsheets = bk.getNumSheets();
                        for(int i=0; i<numsheets; i++) {
                        	if(!bk.getSheetName(i).contains("PMMonthly") && !bk.getSheetName(i).contains("RegionMonthly")) {
                                String headercell = bk.getText(i, 0, 0);
                                headercell +="\nFor the period of " + startDateDisplayString + " through " + end;
                                bk.setText(i, 0, 0, headercell);
                        	}
                        	
                        }
                       
        } catch (Exception ex) {
            System.out.println("Exception in callback: "+ex);
            }
          finally{
                        bk.releaseLock();
                        }
    }
        private void calculateMonthlyAverage(BookModel bk, int sheet) {
        try {
        	bk.setSheet(sheet);
        	int numrows = bk.getLastRow();
        	int numcolumns = bk.getLastCol();
        	for(int i =2; i<numrows; i++) {
        		//System.out.println("row " + i + ":");
        		int rowCount = 0;
        		double runningSum = 0;
        		double averageForRow = 0;
        		for (int j=4; j<16; j++) {
        			String entry = bk.getEntry(i,j);
        			if(!this.isANumber(entry) && !this.isAFormula(bk, i, j)) {        				
        				//System.out.println(entry + " is neither a number nor formula");        				
        					break;
        				
        				
        			}
        			else {
        				if(this.isAFormula(bk, i, j)) {
        					entry = new String("" + bk.getNumber(i,j));
        				}
        				
        				//System.out.println("number found: " + entry);
        				runningSum += Double.parseDouble(entry);
        				rowCount++;
        			}
        			if(rowCount !=0) {
        				averageForRow = runningSum/rowCount;
        				String average = new String(""+averageForRow);
        				if(!bk.getEntry(i,numcolumns).contains("SUBTOTAL"))
        					bk.setEntry(i,numcolumns,average);
        			}
        		}
        	}
        	
        }
        catch(Exception e) {
        	e.printStackTrace();
        }
        }
        
        private void deptAdjVariance(BookModel bk, int sheet) {
        	try {
				bk.setSheet(sheet);
				int numcols = bk.getLastCol();
				int numrows = bk.getLastRow();
				int projGroupRow = 0;
				int buildGroupRow = 0;
				for(int i = 0; i<numrows; i++) {
					String rowEntry = bk.getEntry(i,0);
					if(rowEntry.equals("Project Group Total")) {
						projGroupRow = i;
					}
					if(rowEntry.equals("Building Services Group Total")) {
						buildGroupRow = i;
					}
						
				}
				
				 projGroupRow += 1;
				 buildGroupRow +=1;
				 
				 bk.setEntry(numrows, 3, "=SUM(D"+projGroupRow+",D"+buildGroupRow+")");
				 bk.setEntry(numrows, 4, "=SUM(E"+projGroupRow+",E"+buildGroupRow+")");
				 bk.setEntry(numrows, 5, "=SUM(F"+projGroupRow+",F"+buildGroupRow+")");
				 bk.setEntry(numrows, 6, "=SUM(G"+projGroupRow+",G"+buildGroupRow+")");
			} catch (F1Exception e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
        	
        }
        
        private boolean isAFormula(BookModel bk, int row, int col) {
        	
			try{
				if(bk.getEntry(row,col).equals("")) {
	        		return false;
	        	}
				bk.getNumber(row, col);
				return true;
			}
			catch(Exception e) {
				return false;
			}
		}
		private boolean isANumber(String regex) {
			if(regex == "")
				return false;
        	try {
        		double num = Double.parseDouble(regex);
        		return true;
        	}
        	catch(NumberFormatException e) {
        		return false;
        	}
        }
		private void addYearToRows(BookModel bk, int i) {
        	try {
        		bk.setSheet(i);
			} catch (SelectionException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			} catch (F1Exception e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
        	
        	try{
        		String endDate = bk.getDefinedName("endDate");
        		if(bk.getSheetName(i).contains("RegionMonthly")) {
    			String sheetHeader = bk.getEntry(0,4);
    			sheetHeader += "\n As of " + endDate;
    			bk.setEntry(0, 4, sheetHeader);
        		}
        		if(bk.getSheetName(i).contains("PMMonthly")) {
        			String sheetHeader = bk.getEntry(0,3);
        			sheetHeader += "\n As of " + endDate;
        			bk.setEntry(0, 3, sheetHeader);
            		}
        		}
        		catch (Exception e) {
        			e.printStackTrace();
        		}
        	
        		
        		try {
        			String startDate = bk.getDefinedName("startDate");
        			String[] startDateArray = startDate.split("/");
        			String startYear = startDateArray[2];
        			String endDate = bk.getDefinedName("endDate");
        			String[] endDateArray = endDate.split("/");
        			String endYear = endDateArray[2];
        			//String endDate = bk.getDefinedName(arg0)
        			if(bk.getSheetName(i).contains("RegionMonthly")) {
        				
        				
        				for (int j=4;j<16;j++) {
        				String colHeader = bk.getEntry(i, 1, j);
        				if(colHeader.contains("Oct") || colHeader.contains("Nov") || colHeader.contains("Dec"))
        					bk.setEntry(i, 1, j, (colHeader + (Integer.parseInt(startYear)) ));
        				else
        					bk.setEntry(i,1,j,(colHeader+(Integer.parseInt(startYear)+1)));
        				}
        			}
        			
        			if(bk.getSheetName(i).contains("PMMonthly")) {
        				for (int j=3;j<15;j++) {
        				String colHeader = bk.getEntry(i, 1, j);
        				if(colHeader.contains("Oct") || colHeader.contains("Nov") || colHeader.contains("Dec"))
        					bk.setEntry(i, 1, j, (colHeader + (Integer.parseInt(startYear)) ));
        				else
        					bk.setEntry(i,1,j,(colHeader+(Integer.parseInt(startYear)+1)));
        				}
        			}
					
				} catch (SelectionException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				} catch (F1Exception e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
        	
        	
}
        public String[] parseDates(String start, String end) {
        	String startDateArray[] = start.split("/");
            String endDateArray[] = end.split("/");
            String sMonth = startDateArray[0];
            String sDay = startDateArray[1];
            String sYear = startDateArray[2];
           
            if(sMonth.length() <2)
                    sMonth = "0" + sMonth;
            if(sDay.length()<2)
                    sDay = "0"+sDay;
           
           
            String eMonth = endDateArray[0];
            String eDay = endDateArray[1];
            String eYear = endDateArray[2];
            
           
            if(eMonth.length() <2)
                    eMonth = "0" + eMonth;
            if(eDay.length()<2)
                    eDay = "0"+eDay;
            startDateConcat = new String(sYear+sMonth+sDay);
            endDateConcat = new String(eYear+eMonth+eDay);
            String[] dates = new String[2];
            dates[0] = startDateConcat;
            dates[1] = endDateConcat;
            return dates;
        }
		public void addRowToSheet(BookModel book, int sheet, int row, RowObject passedRow) {
                try {
                        book.setSheet(sheet);
                        book.setEntry(row, 0, passedRow.dept1.toString());
                        book.setEntry(row, 1, passedRow.direction.toString());
                        book.setEntry(row, 2, passedRow.dept2.toString());
                        book.setEntry(row, 3, passedRow.job.toString());
                        book.setEntry(row, 4, passedRow.phase.toString());
                        book.setEntry(row, 5, passedRow.jobName.toString());
                        book.setEntry(row, 6, passedRow.pmNumber.toString());
                        book.setEntry(row, 7, passedRow.pmName.toString());
                        book.setEntry(row, 8, passedRow.pmPercent.toString());
                        book.setEntry(row, 9, passedRow.bookings.toString());
                        book.setEntry(row, 10, passedRow.backlog.toString());
                        book.setEntry(row, 11, passedRow.revenue.toString());
                        book.setEntry(row, 12, passedRow.profit.toString());
                        //book.insertRange(row, 0, 11, row+2, (short)32);
                } catch (F1Exception e) {
                        // TODO Auto-generated catch block
                        e.printStackTrace();
                }
               
               
        }
}
class RowObject {
        String dept1;
        String direction;
        String dept2;
        String job;
        String phase;
        String jobName;
        String pmNumber;
        String pmName;
        String pmPercent;
        String bookings, backlog, revenue, profit;
        public RowObject(String dept1, String direction, String dept2, String job, String phase,String jobName, String pmNumber, String pmName, String pmPercent, String bookings, String backlog, String revenue, String profit) {
                this.dept1 = dept1;
                this.direction = direction;
                this.dept2 = dept2;
                this.job = job;
                this.phase = phase;
                this.jobName = jobName;
                this.pmNumber = pmNumber;
                this.pmName = pmName;
                this.pmPercent = pmPercent;
                this.bookings = bookings;
                this.backlog= backlog;
                this.revenue = revenue;
                this.profit = profit;
        }
       
       
       
       
}