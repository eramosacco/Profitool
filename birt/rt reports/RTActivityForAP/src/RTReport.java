import com.f1j.ss.BookModel;
import com.f1j.ss.report.ReportCallback;
import com.f1j.data.query.DataQuery;
import com.f1j.data.query.DatabaseQuery;
import com.f1j.data.source.*;
import com.f1j.ss.report.*;
import com.f1j.ss.*;
import com.f1j.ss.Constants;
import com.f1j.ss.SelectionException;
import com.f1j.util.F1Exception;
import com.actuate.util.*;
import com.actuate.util.Logger;
import com.f1j.data.*;
import com.f1j.data.*;


public class RTReport implements ReportCallback {

	
	public void end(BookModel bk, Object obj) {
		try {
		bk.getLock();
		}
		catch(Exception ex) {
			ex.printStackTrace();
		}
		finally {
			bk.releaseLock();
		}
		
	}

	
	public void start(BookModel bk, Object obj) {
		try {
		bk.getLock();
		int position;
		DataSourceCollection dsc = bk.getDataSourceCollection();
		Source[] src = dsc.get();
        if(dsc.hasDataSetCache())
                position=1;
        else position = 0;
        DataQueryCollection dqc =
                src[position].getDataQueryCollection();
        DataQuery dq[] = dqc.get();
        int numqueries = dq.length;
        String techName = bk.getDefinedName("techName");
    	String startDate = bk.getDefinedName("startDate");
    	String endDate = bk.getDefinedName("endDate");
    	System.out.println("Tech name is " + techName);
    	System.out.println("Start date is " + startDate);
    	System.out.println("End date is " + endDate);
        for(int j=0; j<numqueries; j++) {
        	DatabaseQuery dbq = (DatabaseQuery) dq[j];
        	String sql = dbq.getQuery();
        	if(sql.contains("param")) {
        		sql = sql.replace("param1", techName);
        		sql = sql.replace("param2", startDate);
        		sql = sql.replace("param3", endDate);
        		dbq.setQuery(sql, false);
        		System.out.println("Executing query: " + dbq.getQuery());
        	}
        	
        	
		}
		}
		catch(Exception ex) {
			ex.printStackTrace();
		}
		finally {
			bk.releaseLock();
		}
		
	}

}
