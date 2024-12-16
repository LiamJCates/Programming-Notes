Class Methods (Static):

Class methods are often called static methods as they use the static modifier

Static members are members of a class that aren’t associated with a particular
instance of the class. Like other static variables, static members have only a single instance.

Class methods are essentially similar to functions declared at global scope; however, you must refer to them by the containing class’s name, using the scope resolution operator ::.

Class methods can be invoked with the class name without the need of creating even a single instance of the class.

Some points regarding Class methods:
	Class methods can access other class methods and class variables directly.
	Class methods cannot access instance methods and instance variables directly.
	The special keyword “this” is invalid inside class methods as “this“ refers to a current instance.
