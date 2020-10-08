package com.pluralsight.corejdbc.m4c3;

import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.Connection;
import java.sql.ResultSet;

public class ProductsComponent {

	public void printProductList() throws Exception {

		try (Connection connection = DriverManager.getConnection(
				"jdbc:mysql://localhost:3306/classicmodels?user=root&password=pluralsight&serverTimezone=UTC");

				PreparedStatement preparedStatement = connection
						.prepareStatement("SELECT * FROM products");
				ResultSet resultSet = preparedStatement.executeQuery();) {

			while (resultSet.next()) {

				String name = resultSet.getString("productName");
				System.out.println(name);
			}

		}
	}

}
