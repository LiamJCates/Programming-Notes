import java.awt.Color;
import java.sql.SQLException;

import util.PrintUtil;

public class Demo {

	public static void main (String[] args) throws Exception {
		if (args.length == 0) {
			Demo.inValidMessage();
			return;
		}

		try {
			switch (args[0]) {
			case "m2c1":
				com.pluralsight.corejdbc.m2c1.Main.main(null);
				break;
			case "m3c1":
				com.pluralsight.corejdbc.m3c1.Main.main(null);
				break;
			case "m3c2":
				com.pluralsight.corejdbc.m3c2.Main.main(null);
				break;
			case "m3c3":
				String mainToRun = args[1];
				if (mainToRun.equalsIgnoreCase("JEE")) {
					com.pluralsight.corejdbc.m3c3.Main_JEE.main(null);
				} else if (mainToRun.equalsIgnoreCase("CDI")) {
					com.pluralsight.corejdbc.m3c3.Main_CDI.main(null);
				} else {
					System.out.println("You must secify either JEE or CDI as an imput paramters");
					System.out.println("For example: java -cp target/corejdbc.jar Demo m3c3 JEE");
				}
				break;
			case "m4c1":
				com.pluralsight.corejdbc.m4c1.Main.main(null);
				break;
			case "m4c2":
				if (args.length == 2) {
					if (args[1].equalsIgnoreCase("TCF")) {
						com.pluralsight.corejdbc.m4c2.Main_TCF.main(null);
						break;
					} else if (args[1].equalsIgnoreCase("TwR")) {
						com.pluralsight.corejdbc.m4c2.Main_TwR.main(null);
						break;
					} else if (args[1].equalsIgnoreCase("TwR2")) {
						com.pluralsight.corejdbc.m4c2.Main_TwR2.main(null);
						break;
					}
				}
				System.out.println("You must secify which main you wish to run: TCF, TwR, or TwR2");
				System.out.println("For example: java -cp target/corejdbc.jar Demo m4c2 TwR");

				break;
			case "m4c3":
				com.pluralsight.corejdbc.m4c3.Main.main(null);
				break;
			case "m4c4":
				com.pluralsight.corejdbc.m4c4.Main.main(null);
				break;
			case "m4c5":
				com.pluralsight.corejdbc.m4c5.Main.main(null);
				break;
			case "m4c6":
				com.pluralsight.corejdbc.m4c6.Main.main(null);
				break;
			case "m5c1":
				com.pluralsight.corejdbc.m5c1.Main.main(null);
				break;
			case "m5c2":
				com.pluralsight.corejdbc.m5c2.Main.main(null);
				break;
			case "m5c3":
				com.pluralsight.corejdbc.m5c3.Main.main(null);
				break;
			case "m5c4":
				com.pluralsight.corejdbc.m5c4.Main.main(null);
				break;
			case "m6c1":
				if (args.length == 3) {
					if(args[1].equalsIgnoreCase("CLOB") && args[2].equalsIgnoreCase("STORE")) {
						com.pluralsight.corejdbc.m6c1.Main_CLOB_Store.main(null);
					}else if(args[1].equalsIgnoreCase("CLOB") && args[2].equalsIgnoreCase("READ")) {
						com.pluralsight.corejdbc.m6c1.Main_CLOB_Read.main(null);
					}else if(args[1].equalsIgnoreCase("BLOB") && args[2].equalsIgnoreCase("STORE")) {
						com.pluralsight.corejdbc.m6c1.Main_BLOB_Store.main(null);
					}else if(args[1].equalsIgnoreCase("BLOB") && args[2].equalsIgnoreCase("READ")) {
						com.pluralsight.corejdbc.m6c1.Main_BLOB_Read.main(null);
					}
				} else {
					System.out.println("You must secify which main you wish to run:");
					System.out.println("Syntax: java -cp target/corejdbc.jar Demo m6c2 [CLOB,BLOB] [STORE,READ]");
				}
				break;
			case "m6c2":
				if (args.length <= 1) {
					com.pluralsight.corejdbc.m6c2.Main.main(null);
				} else if (args[1].equalsIgnoreCase("INOUT")) {
					com.pluralsight.corejdbc.m6c2.Main_INOUT.main(null);

				} else {
					System.out.println("You must secify which main you wish to run:");
					System.out.println("Either: java -cp target/corejdbc.jar Demo m6c2");
					System.out.println("    Or: java -cp target/corejdbc.jar Demo m6c2 INOUT");
				}
				break;
			case "m7c1":
				com.pluralsight.corejdbc.m7c1.Main.main(null);
				break;
			case "m7c2":
				if (args.length == 2) {
					if (args[1].equalsIgnoreCase("AC")) {
						com.pluralsight.corejdbc.m7c2.Main_AutoCommit.main(null);
						break;
					} else if (args[1].equalsIgnoreCase("MC")) {
						com.pluralsight.corejdbc.m7c2.Main_ManualCommit.main(null);
						break;
					}
				}
				System.out.println("You must secify which main you wish to run: AC or MC");
				System.out.println("For example: java -cp target/corejdbc.jar Demo m4c2 MC");

				break;
			case "m7c3":
				com.pluralsight.corejdbc.m7c3.Main.main(null);
				break;
			default:
				inValidMessage();

			}
		} catch (Exception ex) {
			System.out.println(ex.getMessage());
			if (ex instanceof SQLException || ex.getCause() instanceof SQLException) {
				printSQLException((SQLException) ex);
			} else {
				PrintUtil.colorPrint("An exception was thrown:", Color.orange, true);
				PrintUtil.colorPrint(ex.getMessage(), Color.orange, true);
			}
		}
	}

	public static void printSQLException(SQLException sqlEx) {
		PrintUtil.colorPrint("A SQLException was thrown:", Color.orange, true);
		PrintUtil.colorPrint(sqlEx.getMessage(), Color.orange, true);
		PrintUtil.colorPrint("SQLState: " + sqlEx.getSQLState(), Color.orange, true);
		PrintUtil.colorPrint("VendorError: " + sqlEx.getErrorCode(), Color.orange, true);

	}

	public static void inValidMessage() {
		System.out.println("You must specifiy which a valid demo to run. For example:");
		PrintUtil.colorPrint("java -cp target/corejdbc.jar Main ", Color.blue, false);
		PrintUtil.colorPrint("m2c1", Color.orange, true);
	}

}
