package com.pluralsight.corejdbc.m4c2;

import java.sql.DriverManager;
import java.sql.Connection;
import java.sql.Statement;
import java.sql.ResultSet;

public class ProductsComponent_TwR2 {

	public void printProductList() throws Exception {

		try (Connection connection = DriverManager.getConnection(
				"jdbc:mysql://localhost:3306/classicmodels?user=root&password=pluralsight&serverTimezone=UTC");
				Statement statement = connection.createStatement();
				ResultSet resultSet = statement.executeQuery("SELECT * FROM products;");) {
			
			statement.executeQuery("SELECT * FROM Xproducts");

			while (resultSet.next()) {

				String name = resultSet.getString("productName");
				System.out.println(name);
			}
		}
	}
}
