package util;

import java.sql.SQLException;

public class ExceptionHandler {
	
	public static void handleException(Exception exception) {
		if (exception instanceof SQLException) {
			SQLException sqlException = (SQLException) exception;
			System.out.println("Error Code: " + sqlException.getErrorCode());
			System.out.println("SQL State: " + sqlException.getSQLState());
		}
		System.out.println("SQLException message: " + exception.getMessage());
		System.out.print("Stacktrace: ");
		exception.printStackTrace();
	}
}
