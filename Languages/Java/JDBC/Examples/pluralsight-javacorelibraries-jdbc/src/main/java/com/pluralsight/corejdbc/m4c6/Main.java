package com.pluralsight.corejdbc.m4c6;

import java.sql.Connection;
import java.sql.Statement;
import java.sql.DriverManager;
import java.sql.ResultSet;

public class Main {

	public static void main(String[] args) throws Exception {

		int rowId = 2;
		int relativePos = 3;

		try (Connection connection = DriverManager.getConnection(
				"jdbc:mysql://localhost:3306/classicmodels?user=root&password=pluralsight&serverTimezone=UTC");
				Statement statement = connection.createStatement();
				ResultSet resultSet = statement
						.executeQuery("SELECT * FROM products " + "where productLine = 'Motorcycles'")) {

			ProductNavUtility comp = new ProductNavUtility(resultSet);
			
			System.out.println("All Products");
			comp.printForward();

			System.out.println("First row");
			comp.printFirst();

			System.out.println("Last row");
			comp.printLast();

			System.out.println("Row at position " + rowId);
			comp.printAt(rowId);

			System.out.println("Row " + (relativePos < 0 ? "Befor" : "After") + " row " + relativePos);
			comp.printRelative(relativePos);

			System.out.println("All products in reverse order");
			comp.printReverse();

		} catch (Exception exception) {
			util.ExceptionHandler.handleException(exception);
		}
	}
}
