package com.pluralsight.corejdbc.m7c2;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.Statement;

public class OrderComponent_MC {

	public int createOrder(int customerNumber,LineItem lineItem) throws  Exception {

		
		try(Connection connection = 
		DriverManager.getConnection("jdbc:mysql://localhost:3306/classicmodels?"
				+ "user=root&password=pluralsight&serverTimezone=UTC");	
				
		PreparedStatement orderStmnt = 
				connection.prepareStatement(
				"INSERT INTO orders " + 
				"(orderDate, requiredDate, status, customerNumber ) " + 
				"VALUES (now(),now(),'In Process',?)",
				
				Statement.RETURN_GENERATED_KEYS );){
			
		connection.setAutoCommit(false);
			
		orderStmnt.setInt(1,customerNumber);
		
		orderStmnt.executeUpdate();

		try ( ResultSet result = orderStmnt.getGeneratedKeys(); ){
			if(!result.next()){ 
				connection.rollback();
				return 0;
			}
			
			int orderNumber = result.getInt(1);

			String sqlStr = 
					"INSERT INTO orderdetails "
					+ "(orderNumber, productCode_x, quantityOrdered, "
					+  "priceEach, orderLineNumber) "
					+ "VALUES (?,?,?,?,?)";
			
			try( PreparedStatement detailsPS = 
				 connection.prepareStatement(sqlStr);){
				
				detailsPS.setInt(1,orderNumber);
				detailsPS.setString(2,lineItem.productCode);
				detailsPS.setInt(3,lineItem.quantityOrdered);
				detailsPS.setDouble(4,lineItem.priceEach);
				detailsPS.setDouble(5,1);
				
				int count = detailsPS.executeUpdate();
	
				if(count == 1){
					connection.commit();
					return orderNumber;
				}else{
					connection.rollback();
					return 0;
				}
			}
		}catch(Exception e) {
			connection.rollback();
			throw e;
		}
    }
	}
}

