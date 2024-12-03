package util;

import javax.sql.rowset.RowSetFactory;
import javax.sql.rowset.RowSetProvider;
import javax.sql.rowset.JdbcRowSet;

public class OrderComponent {

	public boolean updateOrdersStatus(int orderNum, String newStatus) throws Exception {

		String queryString = "SELECT * FROM orders WHERE orderNumber = ?";

		RowSetFactory rowSetProvider = RowSetProvider.newFactory();
		JdbcRowSet rowSet = rowSetProvider.createJdbcRowSet();

		rowSet.setUrl("jdbc:mysql://localhost:3306/classicmodels?user=root&password=pluralsight&serverTimezone=UTC");

		rowSet.setCommand(queryString);

		rowSet.setInt(1, orderNum);

		rowSet.execute();
		
		boolean outcome = false;

		while (rowSet.next()){
			int orderNumber = rowSet.getInt("orderNumber");
			if (orderNumber == orderNum) {
				
				rowSet.updateString("status", newStatus);
				
				rowSet.updateRow();
				
				if (rowSet.rowUpdated()) {
					outcome = true;
					break;
				} else {
					outcome = false;
					break;
				}
			}
		} 

		rowSet.close();
		return outcome;
	}
}
