package com.pluralsight.corejdbc.m6c1;

import java.io.File;
import java.io.FileOutputStream;
import java.io.InputStream;

public class Main_BLOB_Read {

	public static void main(String[] args) throws Exception {
		try {
			ProductComponent comp = new ProductComponent();

			String fileName = "Planes_Image.png";
			String prodLine = "Planes";

			InputStream inStream = comp.readBLOB(prodLine);

			if(inStream == null) {
				System.out.println("Could not read image data from database");
				return;
			}
			File file = new File(fileName);
			FileOutputStream output = new FileOutputStream(file);
			 
			System.out.println("Writing image to file " + fileName);

		    byte[] buffer = new byte[1024];
		    while (inStream.read(buffer) > 0) {
		        output.write(buffer);
		    }

		    inStream.close();
			output.close();

		} catch (Exception exception) {
			util.ExceptionHandler.handleException(exception);
		}
	}
}
