import javax.swing.JOptionPane;

import com.f1j.data.DataQueryCollection;
import com.f1j.data.DataSourceCollection;
import com.f1j.data.query.DataQuery;
import com.f1j.data.query.DatabaseQuery;
import com.f1j.data.source.Source;
import com.f1j.ss.BookModel;
import com.f1j.ss.report.ReportCallback;


public class SummaryOfContracts implements ReportCallback {
	String start = "";
	String end = "";
	int numsheets = 0;
	int numqueries = 0;


	@Override
	public void end(BookModel bk, Object arg1) {
		
	}

	@Override
	public void start(BookModel bk, Object arg1) {
		try {
			bk.getLock();
			System.out.println("test the callback class");
			String periodDate = bk.getDefinedName("period_date");
			String companyId = bk.getDefinedName("company_id");
			System.out.println("period date is " + periodDate);
			System.out.println("coid is " + companyId);
			DataSourceCollection dsc = bk.getDataSourceCollection();
           
            Source[] src = dsc.get();
			
			int position;
            if(dsc.hasDataSetCache())
                    position=1;
            else position = 0;
            DataQueryCollection dqc =
                    src[position].getDataQueryCollection();
            DataQuery dq[] = dqc.get();
            System.out.println(dqc.get());
            numqueries = dq.length;
            for(int j=0; j<numqueries; j++) {
                   
           
            DatabaseQuery dbq = (DatabaseQuery) dq[j];
            String sql = dbq.getQuery();
            System.out.println("query is: " + sql);
/*************************************************************
* Get the value of a defined name
*************************************************************/

            sql = sql.replace("param1", periodDate);
            sql = sql.replace("param2", companyId);
            System.out.println(sql);
            dbq.setQuery(sql, false);
            System.out.println("this is the new query: " + dbq.getQuery());
			

		}
		}
		catch(Exception e) {
			e.printStackTrace();
		}
	}

}
