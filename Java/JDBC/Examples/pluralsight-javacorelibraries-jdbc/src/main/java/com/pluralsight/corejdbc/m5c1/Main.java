package com.pluralsight.corejdbc.m5c1;

public class Main {

	public static void main(String[] args) throws Exception {

		try {
			int orderNumber = 10138;
			String productNumber = "S24_2022";
			int newQuantity = 88;
			
			OrderComponent comp = new OrderComponent();
			comp.updateOrderQuantity(orderNumber, productNumber, newQuantity);

			System.out.println("Quantity changed to " + newQuantity);
		} catch (Exception exception) {
			util.ExceptionHandler.handleException(exception);
		}
	}
}
