package util;
import java.awt.Color;
import java.util.Arrays;

public class PrintUtil {
	
	public static String repeatChars(char chr, int count) {
		char[] chars = new char[count];
		Arrays.fill(chars, chr);
		return String.valueOf(chars);
	}
	
    public static void colorPrint(String txt, Color color, boolean line) {
    	

		
		String defaultColor = (char)27 + "[0m";
		String txtColor = defaultColor;
		if(color == Color.orange) {
			txtColor = (char)27 + "[33m";
		}else if (color == Color.green) {
			txtColor = (char)27 + "[32m";
		}else if (color == Color.blue) {
			txtColor = (char)27 + "[34m";
		}

		// Change this to the desired output (e.g. JUL)
    	System.out.print(txtColor + txt + "" + defaultColor);
    	if(line) {
    		System.out.println("");
    	}


    }

}
