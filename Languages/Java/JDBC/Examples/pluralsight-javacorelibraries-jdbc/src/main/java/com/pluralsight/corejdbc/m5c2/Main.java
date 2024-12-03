package com.pluralsight.corejdbc.m5c2;

public class Main {

	public static void main(String[] args) throws Exception {
		try {
			String fromManager = "1143";
			String toManager = "1621";

			HrComponent comp = new HrComponent();

			int count = comp.replaceSalesManager(fromManager, toManager);
			System.out.println(count + " Employees have been reassigned");
			
		} catch (Exception exception) {
			util.ExceptionHandler.handleException(exception);
		}
	}
}
