package com.pluralsight.corejdbc.m6c1;

import java.io.File;
import java.io.FileReader;

public class Main_CLOB_Store {

	public static void main(String[] args) throws Exception {
		try {
			ProductComponent comp = new ProductComponent();

			String prodLine = "Planes";
			String fileName = "JanesAllWorldAircraft1913_704482.txt";

			File file = new File(fileName);
			FileReader fileReader = new FileReader(file);

			boolean success = comp.storeCLOB(prodLine, fileReader);
			fileReader.close();
			
			if(success) {
				System.out.println("Success: The text contents of " + fileName + " has been stored");
			}else {
				System.out.println("Fail: The text contents of " + fileName + " has NOT been stored");
			}

		} catch (Exception exception) {
			util.ExceptionHandler.handleException(exception);
		}
	}
}
