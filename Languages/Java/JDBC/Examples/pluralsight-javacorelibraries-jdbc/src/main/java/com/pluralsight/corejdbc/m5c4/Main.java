package com.pluralsight.corejdbc.m5c4;

public class Main {

	public static void main(String[] args) throws Exception {
		try {
			String employeeNumber = "1703";

			HrComponent comp = new HrComponent();

			boolean success = comp.deleteEmployee(employeeNumber);
			System.out.println(	" Employee " 
							   	+ employeeNumber 
								+ " has "
								+ (success ? "been deleted" : "not been deleted"));
			
		} catch (Exception exception) {
			util.ExceptionHandler.handleException(exception);
		}
	}
}
