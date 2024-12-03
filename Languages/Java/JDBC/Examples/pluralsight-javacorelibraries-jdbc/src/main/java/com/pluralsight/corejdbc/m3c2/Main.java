package com.pluralsight.corejdbc.m3c2;

public class Main {
	public static void main(String[] args) throws Exception {

		try {
			ProductsComponent comp = new ProductsComponent();

			if (comp.tryConnection()) {
				System.out.println("Demo m3c2: Try to Connect with Class.forName()");
				System.out.println("SUCCESS");
			} else {
				System.out.println("Demo m3c2: Try to Connect with Class.forName()");
				System.out.println("FAILED");
			}
		} catch (Exception exception) {
			util.ExceptionHandler.handleException(exception);
		}
	}
}
