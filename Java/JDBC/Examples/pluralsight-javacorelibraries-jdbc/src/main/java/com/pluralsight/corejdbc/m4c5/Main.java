package com.pluralsight.corejdbc.m4c5;

public class Main {

	public static void main(String[] args) throws Exception {

		try {
			ProductsComponent comp = new ProductsComponent();
			comp.printProductList();
		} catch (Exception exception) {
			util.ExceptionHandler.handleException(exception);
		}
	}
}
