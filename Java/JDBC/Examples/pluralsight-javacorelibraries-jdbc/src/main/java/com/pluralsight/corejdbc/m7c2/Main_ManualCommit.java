package com.pluralsight.corejdbc.m7c2;

public class Main_ManualCommit {
	
	public static void main(String[] args) throws Exception {
		int customerNumber = 112;
		LineItem lineItem = new LineItem("S10_1949", 10, 100.00);
		
		try {
			OrderComponent_MC comp = new OrderComponent_MC();
			int orderNumber = comp.createOrder(customerNumber, lineItem);
			System.out.println("New Order Number = "+ orderNumber);

		} catch (Exception exception) {
			util.ExceptionHandler.handleException(exception);
		}
	}
}
