package com.pluralsight.corejdbc.m4c2;

import java.sql.DriverManager;
import java.sql.Connection;
import java.sql.Statement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class ProductsComponent_TwR {

	public void printProductList() throws Exception {

		try (Connection connection = DriverManager.getConnection(
				"jdbc:mysql://localhost:3306/classicmodels?user=root&password=pluralsight&serverTimezone=UTC");
				Statement statement = connection.createStatement();
				ResultSet resultSet = statement.executeQuery("SELECT * FROM products;");) {
			
			statement.executeQuery("SELECT * FROM products");

			while (resultSet.next()) {

				String name = resultSet.getString("productName");
				System.out.println(name);
			}

		} catch (Exception exception) {
			handleException(exception);
		}
	}

	private void handleException(Exception exception) {
		if (exception instanceof SQLException) {
			SQLException sqlException = (SQLException) exception;
			System.out.println("Error Code: " + sqlException.getErrorCode());
			System.out.println("SQL State: " + sqlException.getSQLState());
		}
		System.out.println("SQLException message: " + exception.getMessage());
		System.out.print("Stacktrace: ");
		exception.printStackTrace();
	}
}
