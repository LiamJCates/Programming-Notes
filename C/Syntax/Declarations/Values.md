### Variables
A variable or scalar is a storage location paired with an associated symbolic name (an identifier), which contains some known or unknown quantity of information referred to as a value. Programs use the variable's identifier to reference and manipulate values during computation.


#### Variable Types
As C is a strongly typed language, each variable in C has a specific type, which determines the size and layout of the variable's memory; the range of values that can be stored within that memory; and the set of operations that can be applied to the variable.


#### Naming Variables
The name of a variable can be composed of letters, digits, and the underscore character. It must begin with either a letter or an underscore. Don't begin variable names with underscore, while the name would be legal, library routines often use such names. Upper and lowercase letters are distinct because C is case-sensitive. Traditional C practice is to use lower case for
variable names, and all upper case for symbolic constants.

There are 32 keywords in C, like "if, else, int, float", that are reserved words and cannot be used as variable names.

We tend to use short names for local variables, especially loops, and longer names for external variables.


#### Variable Definition
A variable definition tells the compiler where and how much storage to create for the variable. A variable definition specifies a data type and contains a list of one or more variables of that type:

type variable_list;

type must be a valid C data type
variable_list identifiers are separated by commas

int    i, j, k;

Variables can be initialized (assigned an initial value) in their declaration. The initializer consists of an equal sign followed by a constant expression. It is good practice to always initialize variables.

type variable_name = value;


Some examples are −

extern int d = 3, f = 5;    // declaration of d and f.
int d = 3, f = 5;           // definition and initializing d and f.
byte z = 22;                // definition and initializes z.
char x = 'x';               // the variable x has the value 'x'.

More rules on initialization can be found
[Initialization.md]



#### Variable Declaration
A variable declaration provides assurance to the compiler that there exists a variable with the given type and name so that the compiler can proceed for further compilation without requiring the complete detail about the variable. A variable definition has its meaning at the time of compilation only, the compiler needs actual variable definition at the time of linking the program.

Variable declaration is useful when the programmer uses multiple files and defines the variables in one of the files. They are available when linking the program. We use the “extern” keyword to declare a variable in any place. Even though it is possible to declare a variable multiple times in a C program, it is only possible to define it only once such as in a file or a function.

"Declaration" refers to places where the nature of the variable is stated but no storage is allocated.
"Definition" refers to the place where the variable is created or assigned storage;

More information on the extern keyword can be found here [extern.md]
