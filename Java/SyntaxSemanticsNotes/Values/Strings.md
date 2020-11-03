Strings
Unlike the primitive types, a String is an object of the String class.

The String class is so core to the Java language, and is so widely used, that although it is simply a defined class in a Java library, the JVM and the compiler treats Strings in special ways under certain circumstances. String can almost be treated as a primitive type. When creating a String literal, it is not necessary, or even advisable, to call new. At compile time, String literals—that is, any characters between a pair of quotations—will be created as a String.

You can construct a String just like any other object type, using new and the String constructor.
A String type variable can be initialized with characters enclosed in double quotes, called a string literal.

String str = new String("Hello")
String str = "World"

Q: Is a string consisting of a single character the same as a character literal? For example, is "k" the same as 'k'?
A: No, a string containing only one letter is still a string.
Although strings consist of characters, they are not the same type.


Like an array a string is zero indexed, the empty string "" of length 0
the empty string is different from null - a reference to no string at all.
You can test whether a string is empty by calling
if (str.length() == 0)
or
if (str.equals(""))

The plus sign (+) is overloaded (has two meanings): one for addition, and the other for concatenating (combining) strings. String concatenation combines two strings into one. If a string is concatenated with a primitive type, the primitive is converted into a string and concatenated with the other string.

Caution
A string cannot cross lines in the source code, the following statement would result in a compile error:

System.out.println("This is an
example of an invalid expression");

To fix the error, break the string into separate substrings, and concatenate them:
System.out.println("This is an" +
"example of a valid expression");






Escape Character
Several characters, such as a newline ' \n ' , are represented as two-characters, called escape sequences.

escape sequence, consists of a backslash (\) followed by a character or a combination of digits. For example, \t is an escape sequence for the Tab character, and an escape sequence such as \u03b1 is used to represent a Unicode. The symbols in an escape sequence are interpreted as a whole rather than individually. An escape sequence is considered as a single character.

The backslash \ is called an escape character. It is a special character. To display this character, you have to use an escape sequence \\.


\t - tab.
\b - backspace (a step backward in the text or deletion of a single character).
\n - new line.
\r - carriage return. ()
\f - form feed.
\' single quote.
\" double quote.
\\ backslash.
\un1n2n3n4 Unicode Encoding
\ddd Octal constant




Unicode
Arbitrary Unicode characters are denoted by a \u, followed by four hexadecimal digits enclosed in single quotes. For example, ' \u2122 ' is the trademark symbol (TM).

Characters are encoded in Unicode, a uniform encoding scheme for characters in many languages around the world.

You can find the encodings in many alphabets at http://www.unicode.org

Q: Why does Java use Unicode?
A: Java was designed for worldwide use. Thus, it needs to use a character set that can represent all the world’s languages. Unicode is the standard character set designed expressly for this purpose. Of course, the use of Unicode is inefficient for languages such as English, German, Spanish, or French, whose characters can be contained within 8 bits. But such is the price that must be paid for global portability.

If you want to join two or more strings together, you can use the concatenate sign (+).

Strings are Immutable
Java strings are immutable. Once created, a string cannot be changed. Whenever we update a String variable, we are actually creating a new string and assigning the memory address to the String variable. The old string is garbage collected. String reference variables may, of course, change the object to which they refer. It is just that the contents of a specific String object cannot be changed after it is created. This restriction allows Java to implement strings more efficiently.

The String class gives no methods that let you change a character in an existing string. If you want to turn "Hello" into "Help!", you cannot directly change the last positions of greeting into 'p' and '!'. To
modify a string concatenate the substring that you want to keep with the characters that you want to replace.

str = "Hello".substring(0, 3) + "p!"     //= "Help!"

Isn’t that a lot less efficient? It would seem simpler to change the code units than to build up a whole new string from scratch. Well, yes and no. Indeed, it isn’t efficient to generate a new string that holds the concatenation of "Hel" and "p!".

But immutable strings have one great advantage: The compiler can arrange that strings are shared.

To understand how this works, think of the various strings as sitting in a common pool. String variables then point to locations in the pool. If you copy a common pool. String variables then point to locations in the pool. If you copy a string variable, both the original and the copy share the same characters. Overall, the designers of Java decided that the efficiency of sharing outweighs the inefficiency of string editing by extracting substrings and concatenating. Look at your own programs; we suspect that most of the time, you don’t change strings—you just compare them.

Q: You say that once created, String objects are immutable. I understand that, from a practical point of view, this is not a serious restriction, but what if I want to create a string that can be changed? A: You’re in luck. Java offers a class called StringBuffer, which creates string objects that can be changed. For example, in addition to the charAt( ) method, which obtains the character at a specific location, StringBuffer defines setCharAt( ), which sets a character within the string. Java also supplies StringBuilder, which is related to StringBuffer, and also supports strings that can be changed. However, for most purposes you will want to use String, not StringBuffer or StringBuilder.

Suppose we have
String message = "Hello";

We learned earlier that the compiler will create the string “Hello” and store it somewhere in the computer’s memory. The variable message stores the address of that location.

Now, if we update the value of message
message = "World";

the compiler actually does not go to the location where “Hello” is stored to change its value to “World”. Instead, it creates a new string “World” and stores it somewhere else in the computer’s memory. This new address is then assigned to message. In other words, there are two strings now: “Hello” and “World”. message stores the address of “World”. If “Hello” is no longer needed in the program, it is eventually destroyed so as to free up that memory location. This process is known as garbage collection and is handled automatically by Java.


Converting primitives to strings

Java automatically converts primitive values to string values whenever you use a primitive value in a concatenation. The toString method is implicitly called by the concatenation operation.

You can explicitly convert a primitive value to a string by using the toString method of the primitive type’s wrapper class. To convert the int variable x to a string, for example, you use this statement:
String s = Integer.toString(x);

String.valueOf(primitiveType)         //Returns a string representation of any primitive type

Converting strings to primitives

To convert a string to a primitive type, you use a parse method of the appropriate wrapper class

Wrapper     parse Method         Example
Integer        parseInt(String)     int x = Integer.parseInt("100");
Short         parseShort(String)     short x = Short.parseShort("100");
Long         parseLong(String)     long x = Long.parseLong("100");
Byte         parseByte(String)     byte x = Byte.parseByte("100");
Float        parseByte(String)     float x = Float.parseFloat("19.95");
Double         parseByte(String)     double x = Double.parseDouble("19.95");
Character     (none)
Boolean     parseBoolean         boolean x = Boolean.parseBoolean

you can use the parse methods to convert string values entered by the user to primitive types. That way, you can write programs that let the user enter numeric data via the console window

Conversion between Strings and Arrays
Strings are not arrays, but a string can be converted into an array and vice versa. To convert a string into an array of characters, use the toCharArray method.

You can also use the getChars(int srcBegin, int srcEnd, char[] dst, int dstBegin) method to copy a substring of the string from index srcBegin to index srcEnd–1 into a character array dst starting from index dstBegin.


To convert an array of characters into a string, use the String(char[]) constructor or the
valueOf(char[]) method. For example, the following statement constructs a string from an
array using the String constructor:
String str = new String(new char[]{'J', 'a', 'v', 'a'});
The next statement constructs a string from an array using the valueOf method.
String str = String.valueOf(new char[]{'J', 'a', 'v', 'a'});
Code Points and Code Units

Java strings are sequences of char values, the char data type is a code unit for representing Unicode code points in the UTF-16 encoding. The most commonly used Unicode characters can be represented with a single code unit. The supplementary characters require a pair of code units.

The length() method yields the number of code units required for a given string in the UTF-16 encoding. String greeting = "Hello";
int n = greeting.length(); // is 5

To get the true length—that is, the number of code points—call
int cpCount = greeting.codePointCount(0, greeting.length());

The call s.charAt(n) returns the code unit at position n, where n is between 0 and s.length() – 1.
To get at the ith code point, use the statements:
int index = greeting.offsetByCodePoints(0, i);
int cp = greeting.codePointAt(index);
Why are we making a fuss about code units? Consider the sentence
𝕆 is the set of octonions.
The character (U+1D546) requires two code units in the UTF-16 encoding.

char ch = sentence.charAt(1)
doesn’t return a space but the second code unit of 𝕆. To avoid this problem, you should not use the char type. It is too low-level. Don’t think that you can ignore exotic characters with code units above U+FFFF. Your emoji-loving users may put characters such as (U+1F37A, beer mug) into strings.

If your code traverses a string, and you want to look at each code point in turn, use these statements:

int cp = sentence.codePointAt(i);
if (Character.isSupplementaryCodePoint(cp)) i += 2;
else i++;

You can move backwards with the following statements:
i--;
if (Character.isSurrogate(sentence.charAt(i))) i--;
int cp = sentence.codePointAt(i);

Obviously, that is quite painful. An easier way is to use the codePoints method that yields a “stream” of int values, one for each code point. You can just turn the stream into an array and traverse that.
int[] codePoints = str.codePoints().toArray();

Conversely, to turn an array of code points to a string, use a constructor.
String str = new String(codePoints, 0, codePoints.length);


String Equality
Q: Why does String define the equals( ) method? Can’t I just use ==?
A: The equals( ) method compares the character sequences of two String objects for equality. Applying the == to two String references simply determines whether the two references refer to the same object.

To test whether two strings are identical except for the upper/lowercase letter distinction, use the equalsIgnoreCase method.
"Hello".equalsIgnoreCase("hello")


Since strings are objects, you need to use the equals method to compare whether two strings have the same contents.

If either argument of the + operator is a string, then the other is converted to a string.

int n = 7;
String greeting = "Hello, " + n;         //" Hello, 7"

If a string and an object are concatenated, then the object is converted to a string by invoking its toString method.
Sometimes, you have a string that contains a number, for example the string "7". To convert the string to its number value, use the Integer.parseInt and Double.parseDouble methods.
If the string doesn't contain a number, or contains additional characters besides a number, the unchecked NumberFormatException is thrown.


String interning

String is not the only immutable class in the standard Java library. All of the number classes, such
as Integer, Double, Character, and BigInteger, are immutable.

What is interning?

Following the String literal and immutable discussions, literals get even more help and special
treatment from the JVM at run time. When the class is loaded by the JVM, it holds all the literals in
a constants pool. Any repetition of a String literal can be referenced from the same constant in the
pool. This is known as String interning.

Naturally, because the constants in this pool can be referenced from any running class in the JVM,
which could easily run into the thousands, the immutable nature of Strings is an absolute necessity.
The String intern pool is not just open to compile-time String literals; any String instance can
be added to this pool with the intern() method. One valid use for String interning could be when
parsing a large amount of data from a file or a network connection, and that data could contain
many duplicates. Imagine something like a large banking statement, which could contain many
credits or debits from a single party, or many similar actions such as multiple purchases of the same
product over time. If these entities are interned when they are read, there will only be one unique
instance taking up memory inside the JVM. The equals method on the String class also checks if
the two compared instances are the same reference in memory, which makes the comparison much
faster if they are the same.
Be aware that the intern() method does not come for free: Although the Strings are not stored on
the heap, they do need to be stored somewhere, and that’s the PermGen space (covered in Chapter 10).
Understanding Generics ❘ 101
Also, liberal use of intern(), if the constant pool had, say, several million entries, can affect the runtime performance of the application due to the cost of lookups for each entry.
The String constant pool is an implementation of the Flyweight Pattern, and similar occurrences
of this pattern exist within the standard Java libraries. For instance, Listing 8-18 illustrates that the
method Integer.valueOf(String) will return the same instance of the Integer object for values
between –128 and 127.
Listing 8-18: The Flyweight Pattern in the Java libraries
@Test
public void intEquality() {
 // Explicitly calling new String so the instances
 // are in different memory locations
 final Integer int1 = Integer.valueOf(new String("100"));
 final Integer int2 = Integer.valueOf(new String("100"));
 assertTrue(int1 == int2);
}
By using an equality check, this code makes sure these objects refer to the same instance in memory.
(JUnit’s Assert.assertSame() could do that here, but assertTrue() with == makes this absolutely explicit.)


java.lang.String
The String class in Java contains more than 50 methods. A surprisingly large number of them are sufficiently useful that we can imagine using them frequently.

stringName.charAt(int stringIndex)             //return char at string index
stringName.length()                     //returns the int length of stringName
stringName.substring(int startIndex)             //substring from string index to end inclusive
stringName.substring(int startIndex, int endIndex)     //substring [start, end)
stringName.toUpperCase()
stringName.toLowerCase()
stringName.split()                    //split string on delimiter, returns array
string1.equals(string2)                    // returns boolean indicating if str==str2
stringName.equalsIgnoreCase(String)            //Similar to equals but ignores case.
str.compareTo(str2)                    //ret 0 if str == str2, -1 is str < str2, 1 if str > str2
str.compareToIgnoreCase(String)             //Similar to compareTo but ignores case.
contains(s1)                     //Returns true if s1 is a substring in this string
str.codePointAt(int index)     //returns the code point that starts at the specified location.

str.offsetByCodePoints(int startIndex, int cpCount)
//returns the index of the code point cpCount code points away from the code point at startIndex.

IntStream codePoints() 8
returns the code points of this string as a stream. Call toArray to put them in an array.

new String(int[] codePoints, int offset, int count) 5
constructs a string with the count code points in the array starting at offset.

boolean empty()
returns true if the string is empty

boolean blank()
returns true if the string is empty or consists of whitespace.

boolean startsWith(String prefix)
boolean endsWith(String suffix)

index Of (ch) Returns the index of the first occurrence of ch in the string. Returns −1 if not matched. indexOf(ch, fromIndex) Returns the index of the first occurrence of ch after fromIndex in the string. Returns −1 if not matched.
int indexOf(String str)
int indexOf(String str, int fromIndex)
int indexOf(int cp)
int indexOf(int cp, int fromIndex)
returns the start index of the first substring equal to the string str or the code point cp, starting at index 0 or at fromIndex, or -1 if str does not occur in this string. or -1 on failure

lastIndexOf(ch) Returns the index of the last occurrence of ch in the string. Returns −1 if not matched. lastIndexOf(ch, fromIndex) Returns the index of the last occurrence of ch before fromIndex in this string. Returns −1 if not matched.
int lastIndexOf(String str)
int lastIndexOf(String str, int fromIndex)
int lastindexOf(int cp)
int lastindexOf(int cp, int fromIndex)
returns  the start index of the last substring equal to the string str or the code point cp, starting at the end of the string or at fromIndex. or -1 on failure

String replace(CharSequence oldString, CharSequence newString)
returns a new string that is obtained by replacing all substrings matching oldString in the string with the string newString. You can supply String or StringBuilder objects for the CharSequence parameters.

String replaceAll(String old, String new)

String replaceFirst(String old, String new)
//Returns a new string that’s based on the original string, but with the first occurrence of the first string replaced by the second parameter. Note that the first parameter can be a regular expression.

String trim()
String strip()
returns a new string by eliminating all leading and trailing characters that are ≤ U+0020 (trim) or whitespace (strip) in the original string.

String join(CharSequence delimiter, CharSequence... elements)
returns a new string joining all elements with the given delimiter.

String repeat(int count)
returns a string that repeats this string count times.

Matching, Replacing, and Splitting by Patterns
Often you will need to write code that validates user input, such as to check whether the input is a number, a string with all lowercase letters, or a Social Security number. How do you write this type of code? A simple and effective way to accomplish this task is to use the regular expression. A regular expression (abbreviated regex) is a string that describes a pattern for matching a set of strings. You can match, replace, or split a string by specifying a pattern. This is an extremely useful and powerful feature.

See regular expressions section






Building Strings

The String class is powerful, but it’s not very efficient for programs that require heavy-duty string manipulation. Occasionally, you need to build up strings from shorter strings, such as keystrokes or words from a file. It would be inefficient to use string concatenation for this purpose. Every time you concatenate strings, a new String object is constructed. This is time consuming and wastes memory. Using the StringBuilder class avoids this problem.

construct an empty string builder:
StringBuilder builder = new StringBuilder();

Each time you need to add another part, call the append method.
builder.append(ch); // appends a single character
builder.append(str); // appends a string

When you are done building the string, call the toString method. You will get a String object with the character sequence contained in the builder.

String completedString = builder.toString();

The StringBuilder class was introduced in Java 5. Its predecessor, StringBuffer, is slightly less efficient, but it allows multithreading. The APIs of both classes are identical.

Internally, a StringBuilder object maintains a fixed area of memory where it stores a string value. This area of memory is called the buffer. The string held in this buffer doesn’t have to use the entire buffer. As a result, a StringBuilder object has both a length and a capacity. The length represents the current length of the string maintained by the StringBuilder, and the capacity represents the size of the buffer itself. Note that the length can’t exceed the capacity.

When you create a StringBuilder object, initially the capacity is set to the length of the string plus 16. The StringBuilder class automatically increases its capacity whenever necessary, so you don’t have to worry about exceeding the capacity

java.lang.StringBuilder

StringBuilder()        //constructs an empty string builder.

int length()        //returns the number of code units of the builder or buffer.

StringBuilder append(String str)        //appends a string and returns this.



StringBuilder appendCodePoint(int cp)    
//appends a code point, converting it into one or two code units, and returns this.

void setCharAt(int i, char c)            //sets the ith code unit to c.

StringBuilder insert(int offset, String str)        //inserts a string at position offset and returns this.

StringBuilder insert(int offset, char c)        //inserts a code unit at position offset and returns this.

StringBuilder delete(int startIndex, int endIndex)
//deletes the code units with offsets startIndex to endIndex – 1 and returns this.

String toString()
returns a string with the same data as the builder or buffer contents.

append(primitiveType)
Appends the string representation of the primitive type to the end of the string.
append(Object)
Calls the object’s toString method and appends the result to the end of the string.
append(CharSequence)
Appends the string to the end of the StringBuilder’s string value. The parameter can be a String, StringBuilder, or StringBuffer.

char charAt(int)
Returns the character at the specified position in the string.

delete(int, int)
Deletes characters starting with the first int and ending with the character before the second int.

deleteCharAt(int)
Deletes the character at the specified position.

ensureCapacity(int)
Ensures that the capacity of String-Builder is at least equal to the int value; increases the capacity if necessary.

int capacity()
Returns the capacity of this StringBuilder.

int indexOf(String)
Returns the index of the first occurrence of the specified string. If the string doesn’t appear, returns -1.

int indexOf(String, int)
Returns the index of the first occurrence of the specified string, starting the search at the specified index position. If the string doesn’t appear, returns -1.

insert(int, primitiveType)
Inserts the string representation of the primitive type at the point specified by the int argument.

insert(int, Object) Calls the toString method of the Object parameter and then inserts the resulting string at the point specified by the int argument.

insert(int, CharSequence)
Inserts the string at the point specified by the int argument. The second parameter can be a String, StringBuilder, or StringBuffer.

int lastIndexOf(String)
Returns the index of the last occurrence of the specified string. If the string doesn’t appear, returns -1.

int lastIndexOf(String, int)
Returns the index of the last occurrence of the specified string, starting the search at the specified index position. If the string doesn’t appear, returns -1.

int length() Returns the length of this string.

replace(int, int, String)
Replaces the substring indicated by the first two parameters with the string provided by the third parameter.

reverse()
Reverses the order of characters.

setCharAt(int, char)
Sets the character at the specified position to the specified character.

setLength(int)
Sets the length of the string. If that length is less than the current length, the string is truncated; if it’s greater than the current length, new characters — hexadecimal zeros — are added.

String substring(int)
Extracts a substring, beginning at the position indicated by the int parameter and continuing to the end of the string.

String substring(int, int)
Extracts a substring, beginning at the position indicated by the first parameter and ending at the position one character before the value of the second parameter.

String toString()
Returns the current value as a String.

String trimToSize()
Reduces the capacity of the StringBuffer to match the size of the string


CharSequence Interface

The Java API includes a useful interface called CharSequence. All three of the classes discussed in this chapter  — String, StringBuilder, and String Buffer — implement this interface. This method exists primarily to let you use String, StringBuilder, and StringBuffer interchangeably.

Several of the methods of the String, StringBuilder, and StringBuffer classes use CharSequence as a parameter type. For those methods, you can pass a String, StringBuilder, or StringBuffer object. Note that a string literal is treated as a String object, so you can use a string literal anywhere a CharSequence is called for.

The CharSequence interface defines four methods:
» char charAt(int): Returns the character at the specified position.
» int length(): Returns the length of the sequence.
» subSequence(int start, int end): Returns the substring indicated by the start and end parameters.
» toString(): Returns a String representation of the sequence.
