package com.pluralsight.corejdbc.m6c1;

import java.io.File;
import java.io.FileInputStream;


public class Main_BLOB_Store {

	public static void main(String[] args) throws Exception {
		try {
			ProductComponent comp = new ProductComponent();

			String prodLine = "Planes";
			String fileName = "bi-plane.png";

			File file = new File(fileName);
			FileInputStream fileInputStream = new FileInputStream(file);

			boolean success = comp.storeBLOB(prodLine, fileInputStream);
			fileInputStream.close();
			
			if(success) {
				System.out.println("Success: The image " + fileName + " has been stored");
			}else {
				System.out.println("Fail: The image " + fileName + " has NOT been stored");
			}

		} catch (Exception exception) {
			util.ExceptionHandler.handleException(exception);
		}
	}
}
