package com.pluralsight.corejdbc.m7c1;

import java.sql.Connection;
import java.sql.PreparedStatement;

public class OrdersComponent {

	public void tryConnection() throws Exception {

		try(Connection con = ConnectionPool.getConnection();) {

		PreparedStatement preparedStatement 
			= con.prepareStatement("select * from orderDetails");
		
		preparedStatement.execute();

		String msg = Thread.currentThread().getName() + " --> " + this.getConnectionId(con);
		System.out.println(msg);

		}
	}

	public String getConnectionId(Connection con) {
		String conId = con.toString();
		int lastPos = conId.length() - 2;
		conId = conId.substring(lastPos);
		return conId;

	}

}
