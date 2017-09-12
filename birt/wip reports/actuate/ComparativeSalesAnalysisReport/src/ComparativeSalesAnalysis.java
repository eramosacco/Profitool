import java.util.ArrayList;
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
public class ComparativeSalesAnalysis implements ReportCallback{

	

	@Override
	public void start(BookModel bk, Object obj) {
		try {
			bk.getLock();
			this.modifyQuery(bk);
		}
		catch(Exception e) {
            e.printStackTrace();
    }
    finally{
    	
            bk.releaseLock();
    }
	}
	
	@Override
	public void end(BookModel bk, Object obj) {
		try {
			bk.getLock();
			this.dateColumns(bk);
				
		}
		catch(Exception e) {
			e.printStackTrace();
		}
		finally {
			bk.releaseLock();
		}
	}
	
	
	private void dateColumns(BookModel bk) {
		try {
		for(int i=0; i<bk.getLastCol(); i++) {
			if(bk.getEntry(1,i).contains("Actual")) {
				String actual = bk.getEntry(1,i);
				actual = actual + " for the Period of " + bk.getDefinedName("startDateAct") + " through " + bk.getDefinedName("endDateAct");
				bk.setEntry(1,i, actual);
			}
			
			if(bk.getEntry(1,i).contains("Budget")) {
				String budget = bk.getEntry(1,i);
				budget = budget + " for the Period of " + bk.getDefinedName("startDateAct") + " through " + bk.getDefinedName("endDateAct");
				bk.setEntry(1,i, budget);
			}
			
			if(bk.getEntry(1,i).contains("Prior Year Results")) {
				String prior = bk.getEntry(1,i);
				prior = prior + " (" + bk.getDefinedName("startDatePre") + " through " + bk.getDefinedName("endDatePre") + ")";
				bk.setEntry(1,i, prior);
			}
		}
		}
		catch (Exception e) {
			e.printStackTrace();
		}
	}

	private void modifyQuery(BookModel bk) {
		 try {
		 DataSourceCollection dsc = bk.getDataSourceCollection();
		 int numqueries = 0;
       
                Source[] src = dsc.get();
               
               
                int position;
                if(dsc.hasDataSetCache())
                        position=1;
                else position = 0;
                DataQueryCollection dqc =
                        src[position].getDataQueryCollection();
                DataQuery dq[] = dqc.get();
                numqueries = dq.length;
                String coid = bk.getDefinedName("COID");
                for(int j=0; j<numqueries; j++) {
               	 
                       
               
               	 DatabaseQuery dbq = (DatabaseQuery) dq[j];
               	 String sql = dbq.getQuery();
               	 System.out.println("good here.");
               	 String param1 = bk.getDefinedName("startDateAct");
               	 System.out.println("startDateAct here");
               	 String param2 = bk.getDefinedName("endDateAct");
               	 System.out.println("endDateAct here");
               	 String param3 = bk.getDefinedName("startDatePre");
               	 System.out.println("startDatePre here");
               	 String param4 = bk.getDefinedName("endDatePre");
               	 System.out.println("endDatePre here");
               	 System.out.println("sql is " + sql);
               	 System.out.println("coid is " + coid);
               	 if(!coid.equals("ACCO")) {
               		 sql = sql.replace("ACCO", coid);
               	 }
               	 
               	 

               	 String[] dateArrayAct = this.parseDates(param1, param2);
               	 String[] dateArrayPre = this.parseDates(param3, param4);
               	 if(sql.contains("param1") && sql.contains("param2") && sql.contains("param3") && sql.contains("param4")) {
               		 sql = sql.replace("param1", dateArrayAct[0]);
               		 sql = sql.replace("param2", dateArrayAct[1]);
               		 sql = sql.replace("param3", dateArrayPre[0]);
               		 sql = sql.replace("param4", dateArrayPre[1]);
               		                 	 
               	 	 System.out.println(sql);
               	 	 dbq.setQuery(sql, false);
               	 }

                }
		 }
		 catch (Exception e) {
			 e.printStackTrace();
		 }
		
	}

	public String[] parseDates(String start, String end) {
		System.out.println("parse dates here");
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
         String startDateConcat = new String(sYear+sMonth+sDay);
         String endDateConcat = new String(eYear+eMonth+eDay);
         String[] dates = new String[2];
         dates[0] = startDateConcat;
         dates[1] = endDateConcat;
         return dates;
     }

}
