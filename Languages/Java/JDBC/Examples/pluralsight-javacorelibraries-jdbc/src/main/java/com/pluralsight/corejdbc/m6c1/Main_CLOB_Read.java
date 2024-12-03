package com.pluralsight.corejdbc.m6c1;

import java.io.Reader;

public class Main_CLOB_Read {

	public static void main(String[] args) throws Exception {
		try {
			ProductComponent comp = new ProductComponent();

			String prodLine = "Planes";

			Reader reader = comp.readCLOB(prodLine);

			int chr = 0;
			while ((chr = reader.read()) > 0) {
				System.out.write(chr);
			}

			reader.close();

		} catch (Exception exception) {
			util.ExceptionHandler.handleException(exception);
		}
	}
}
