package com.pluralsight.corejdbc.m4c3;

public class Main {

	public static void main(String[] args) throws Exception {
		
		final String msg = "You must specify price range as arguments (e.g. 50.0 100.0).";

		try {
			ProductsComponent comp = new ProductsComponent();
			comp.printProductList();	
		} catch (Exception exception) {
			System.out.println("\n"+msg);
			util.ExceptionHandler.handleException(exception);
		}
	}
}
