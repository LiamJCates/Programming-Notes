package com.pluralsight.corejdbc.m4c2;

import java.sql.DriverManager;
import java.sql.Connection;
import java.sql.Statement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class ProductsComponent_TCF {
	
	public void printProductList() throws Exception {
		
		Connection connection = null;
		Statement statement = null;
		ResultSet resultSet = null;

		try {

			connection = DriverManager.getConnection(
					"jdbc:mysql://localhost:3306/classicmodels?user=root&password=pluralsight&serverTimezone=UTC");
			statement = connection.createStatement();
			resultSet = statement.executeQuery("SELECT * FROM xproducts;");


			while (resultSet.next()) {

				String name = resultSet.getString("productName");
				int quantity = resultSet.getInt("quantityInStock");
				double price = resultSet.getDouble("buyPrice");

				System.out.format("%-45s %5d %10.2f%n", name, quantity, price);

			}

			
		} catch (Exception exception) {				
			if(exception instanceof SQLException) {
				SQLException sqlException = (SQLException)exception;
				System.out.println("Error Code: " 			+ sqlException.getErrorCode());
				System.out.println("SQL State: " 			+ sqlException.getSQLState());
			}
			System.out.println("SQLException message: " + exception.getMessage());
			System.out.print("Stacktrace: "); 			  exception.printStackTrace();
			
		} finally {
			
			try { resultSet.close(); }
			catch(Exception ex) {
					System.out.println("ResultSet.close(): " + ex.getMessage());
			}
			
			try { statement.close(); }
			catch(Exception ex) {
					System.out.println("Statement.close(): " + ex.getMessage());
			}
			
			try { connection.close(); }
			catch(Exception ex) {
					System.out.println("Connection.close(): " + ex.getMessage());
			}
			
			
		}
	}

}
