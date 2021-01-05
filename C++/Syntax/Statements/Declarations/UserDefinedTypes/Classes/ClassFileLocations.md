### Class File Locations
When you divide the class, you put part in the header file and part in the
source code file:

Header file:
Put the class definition in the header file. You can include the function code inside the class definition itself if it’s a short function. Most people prefer not to put any function code longer than a line or two in the header — in fact, many don’t put any function code at all in the header. You may want to name the header file the same as the class but with an .h or .hpp extension. Thus, the class Pen, for instance, might be in the file Pen.h.

Source file:
If your class has member functions, and you did not put the code in the class definition, you need to put the code in a source file.

When you do, precede the function name with the class name and two colons. (Do not put any spaces between the two colons, but you can put spaces on either side of the pair of colons.) If you named the header file the same as the class, you probably want to name the source file the same as the class as well but with a .cpp or .cc extension.
