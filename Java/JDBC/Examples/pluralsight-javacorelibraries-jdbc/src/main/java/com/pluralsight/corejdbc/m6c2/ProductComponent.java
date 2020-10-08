package com.pluralsight.corejdbc.m6c2;

import java.sql.DriverManager;
import java.sql.CallableStatement;
import java.sql.Connection;

import java.sql.ResultSet;

public class ProductComponent {

	public void listProductsBy(String productLine) throws Exception {

		try(Connection connection = DriverManager.getConnection(
				"jdbc:mysql://localhost:3306/classicmodels?user=root&password=pluralsight&serverTimezone=UTC");

		CallableStatement callableStatement = 
				connection.prepareCall("{call listProductsFor(?)}");){

		callableStatement.setString(1, productLine);

		boolean success = callableStatement.execute();
		
		if (success) {
			
			try(ResultSet resultSet = callableStatement.getResultSet();){		

				while (resultSet.next()) {
					String name = resultSet.getString("productName");
					System.out.println(name);
				}
			}
		}
		}
	}
}
