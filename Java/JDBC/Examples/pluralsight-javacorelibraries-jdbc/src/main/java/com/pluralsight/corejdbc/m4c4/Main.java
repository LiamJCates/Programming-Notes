package com.pluralsight.corejdbc.m4c4;

import com.pluralsight.corejdbc.m4c4.ProductsComponent;

public class Main {

	public static void main(String[] args) throws Exception {

		try {
			ProductsComponent comp = new ProductsComponent();
			comp.printProductList(50.0, 100.0);
		} catch (Exception exception) {
			util.ExceptionHandler.handleException(exception);
		}

	}
}
