package com.pluralsight.corejdbc.m6c2;

public class Main_INOUT {

	public static void main(String[] args) throws Exception {
		try {
			
			int empNum = 1002;
			String newEmail = "diane@classicmodelcars.com";
			
			HrComponent component = new HrComponent();
			
			
			String oldEmail = component.updateEmail(empNum, newEmail);
			
			if(oldEmail != null) {
				System.out.println("email changed from "+oldEmail+" to "+newEmail);
			}

		} catch (Exception exception) {
			util.ExceptionHandler.handleException(exception);
		}
	}
}
