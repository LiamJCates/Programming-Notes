package com.pluralsight.corejdbc.m7c3;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;

import javax.sql.rowset.CachedRowSet;

public class Main {

	public static void main(String[] args) throws Exception {

		String status = "In Process";
		OrderComponent comp = new OrderComponent();
		
		try(CachedRowSet rowSet1 = comp.ordersByStatus(status);
		FileOutputStream fout = new FileOutputStream("row_set_serialized.ser");
		ObjectOutputStream oos = new ObjectOutputStream(fout);){
		
		oos.writeObject(rowSet1);
		fout.close();
		oos.close();
		
		// Read CachedRowSet from file
		try(FileInputStream fin = new FileInputStream("row_set_serialized.ser");
			ObjectInputStream ois = new ObjectInputStream(fin);
			CachedRowSet rowSet2 = (CachedRowSet)ois.readObject();){
			
			// Print out CachedRowSet
			while (rowSet2.next()) {
				int customerNumber = rowSet2.getInt("customerNumber");
				int orderNumber = rowSet2.getInt("orderNumber");
				System.out.println(customerNumber + " " + orderNumber + " " + status);
			}
			
		}} catch (Exception exception) {
			util.ExceptionHandler.handleException(exception);
		}
	}
}
