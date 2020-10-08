package com.pluralsight.corejdbc.m6c2;

import java.sql.DriverManager;
import java.sql.CallableStatement;
import java.sql.Connection;


public class HrComponent {

	public String updateEmail(int employeeNumber, String newEmail) throws Exception {

		try(Connection connection = DriverManager.getConnection(
				"jdbc:mysql://localhost:3306/classicmodels?user=root&password=pluralsight&serverTimezone=UTC");

		CallableStatement callableStatement = 
				connection.prepareCall("{call updateEmail(?,?)}");){

		callableStatement.setInt(1, employeeNumber);

		callableStatement.registerOutParameter(2, java.sql.Types.VARCHAR);
		
		callableStatement.setString(2, newEmail);
		
		callableStatement.execute();
		
		String oldEmail = callableStatement.getString(2);
		
		return oldEmail;

	}
	}

}
