Programming Style

Java is a free-form language, meaning that it does not matter where you place statements relative to each other on a line. However, over the years, a common and accepted indentation style has developed that allows for very readable programs. This book follows that style, and it is recommended that you do so as well. Using this style, you indent one level after each opening brace, and move back out one level after each closing brace.

Java is case sensitive

Begin variable, field, and method names with a lowercase letter, and then capitalize the first letter of each subsequent word that makes up the name.
Capitalize the first letter of a class name, as well as the first letter of each subsequent word it contains.
Package names should always be lowercase
Underscores are not commonly used in class or method names.
Constants should be in all uppercase with an occasional underscore, such as PI or MAX_VALUE.

There are two common brace styles:
The "Allmann" style in which braces line up
public static void main()
{
}
The compact but less clear "Kernighan and Ritchie" style.
public static void main() {
}


Except for public static final fields, all fields should be declared private.
If you omit the access specifier, the field has package visibility-all methods of classes in the same package can access it--an unsafe practice that you should avoid.

int[] numbers That style clearly shows the type int[] of the variable.
All classes, methods, parameters, and return values should have documentation comments.
You should put spaces around binary operators and after keywords, but not after method names.





You should not use magic numbers. Use named constants (final variables) instead.
