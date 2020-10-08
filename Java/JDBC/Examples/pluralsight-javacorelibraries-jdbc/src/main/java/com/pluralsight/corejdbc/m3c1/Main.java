package com.pluralsight.corejdbc.m3c1;

public class Main {

	public static void main(String[] args) throws Exception {

		try {
			ProductsComponent comp = new ProductsComponent();

			if (comp.tryConnection()) {
				System.out.println("Demo m3c1: Try to Connect with DriverManager");
				System.out.println("SUCCESS");
			} else {
				System.out.println("Demo m3c1: Try to Connect with DriverManager");
				System.out.println("FAILED");
			}
		} catch (Exception exception) {
			util.ExceptionHandler.handleException(exception);
		}
	}
}