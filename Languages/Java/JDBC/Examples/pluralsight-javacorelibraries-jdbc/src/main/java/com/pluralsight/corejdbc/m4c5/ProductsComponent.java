package com.pluralsight.corejdbc.m4c5;

import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.Connection;

import java.sql.ResultSet;

public class ProductsComponent {

	public void printProductList() throws Exception {

		try (Connection connection = DriverManager.getConnection(
				"jdbc:mysql://localhost:3306/classicmodels?user=root&password=pluralsight&serverTimezone=UTC");

				PreparedStatement preparedStatement = connection
						.prepareStatement("select productName, quantityInStock, buyPrice "
								        + "from products");
				ResultSet resultSet = preparedStatement.executeQuery();) {

			while (resultSet.next()) {

				String name = resultSet.getString("productName");
				int quantity = resultSet.getInt("quantityInStock");
				double price = resultSet.getDouble("buyPrice");

				System.out.format("%-45s %5d %10.2f%n", name, quantity, price);

			}

		}
	}

}
