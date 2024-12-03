package com.pluralsight.corejdbc.m2c1;

import java.sql.Connection;
import java.sql.DriverManager;


public class ConnectComponent {
	
	public boolean tryConnection() throws Exception{	

		try (Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/classicmodels?user=root&password=pluralsight&serverTimezone=UTC")){
				
			return conn.isValid(2);
    				   
		}
    }

}
