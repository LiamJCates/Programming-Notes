package com.pluralsight.corejdbc.m5c1;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;

public class OrderComponent {

	public void updateOrderQuantity(int orderNumber, String productCode, int newQuantity) throws Exception {

		String query = "UPDATE orderdetails "
					 + "SET quantityOrdered=? " 
					 + "WHERE orderNumber = ? "
					 + "  AND productCode = ?";

		try (Connection connection = DriverManager.getConnection(
				"jdbc:mysql://localhost:3306/classicmodels?user=root&password=pluralsight&serverTimezone=UTC");

				PreparedStatement preparedStatement = connection.prepareStatement(query);) {

			preparedStatement.setInt(1, newQuantity);
			preparedStatement.setInt(2, orderNumber);
			preparedStatement.setString(3, productCode);
			preparedStatement.executeUpdate();

		}
	}

}
