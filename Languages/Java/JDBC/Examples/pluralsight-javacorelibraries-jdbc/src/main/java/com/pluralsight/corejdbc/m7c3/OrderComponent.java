package com.pluralsight.corejdbc.m7c3;

import javax.sql.rowset.RowSetFactory;
import javax.sql.rowset.RowSetProvider;
import javax.sql.rowset.CachedRowSet;

public class OrderComponent {

	public CachedRowSet ordersByStatus(String status) throws Exception {

		String queryString = "SELECT * FROM orders WHERE status = ?";
		
		RowSetFactory rowSetProvider = RowSetProvider.newFactory();
		CachedRowSet rowSet = rowSetProvider.createCachedRowSet();
		
		rowSet.setUrl("jdbc:mysql://localhost:3306/classicmodels?user=root&password=pluralsight&serverTimezone=UTC");

		rowSet.setCommand(queryString);
		
		rowSet.setString(1, status);
		
		rowSet.execute();
		
		return rowSet;
	}
}
