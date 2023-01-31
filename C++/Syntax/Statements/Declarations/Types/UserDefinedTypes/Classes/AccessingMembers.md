The compiler is smart enough to know when you use a member name, so the use of this-> is optional.
If a name has no local definition, and it is the name of a member, the compiler assumes you want to use the
member. Some programmers prefer to always include this-> for the sake of clarity—in a large program,
you can easily lose track of which names are member names. Other programmers find the extra this-> to
be clutter and use it only when necessary.


A number of programmers employ a more subtle technique, which involves using a special prefix or
suffix to denote data member names. For example, a common technique is to use the prefix m_ for all data
members (“m” is short for member). Another common technique is a little less intrusive: using a plain
underscore (_) suffix. I prefer a suffix to a prefix, because suffixes interfere less than prefixes, so they don’t
obscure the important part of a name.

if you want to use only an underscore to denote members, use it as a suffix, not a prefix. the C++
standard sets aside certain names and prohibits you from using them. the actual rules are somewhat
lengthy, because C++ inherits a number of restrictions from the C standard library. For example, you
should not use any name that begins with E and is followed by a digit or an uppercase letter. (that
rule seems arcane, but the C standard library defines several error code names, such as ERANGE, for a
range error in a math function. this rule lets the library add new names in the future and lets those who
implement libraries add vendor-specific names.)
i like simplicity, so i follow three basic rules. these rules are slightly more restrictive than the official
C++ rules, but not in any burdensome way:
• Do not use any name that contains two consecutive underscores (like__this).
• Do not use any name that starts with an underscore (_like_this).
• Do not use any name that is all uppercase (LIKE_THIS).
Using a reserved name results in undefined behavior. the compiler may not complain, but the results
are unpredictable. typically, a standard library implementation must invent many additional names
for its internal use. By defining certain names that the application programmer cannot use, C++
ensures the library writer can use these names within the library. if you accidentally use a name that
conflicts with an internal library name, the result could be chaos or merely a subtle shift in a function’s
implementation.

//Say we have the class

class MyObject
{
  //MyObject has a member variable
public:
	int aNumber;
};


int main()
{
  //And we make an instance of the MyObject class
  MyObject obj1();

  //When we have a object of a given class,
  //and we want to access a member of that class we use the dot operator
  cout << MyObject.aNumber << endl;

  //Say we have a pointer of the class type
  MyObject* objPointer;

  //And we set the pointer equal to the address of the previously created object
  objPointer = &obj1;

  //In this case, to access the member we use the arrow operator
  cout << objPointer->aNumber << endl;


  //This is the same as if we had done
  cout << (*objPointer).aNumber << endl;

  //dereferenced the pointer first, then used the dot operator to access the member from the now dereferenced object value

  //This is not the same as
  cout << *objPointer.aNumber << endl;

  //This would try to dereference the aNumber value as the dot operator, "."
  // has a higher precedence than the dereference operator, "*"
  // becuae of the difference in precedence, we have to surround the (* ) dereference with paranthesis
  // in this way, the dereference happens before the member access done by the dot operator "."

}


/*
More formally the arrow operator, "->", is called the member-of-pointer operator


The member-of-pointer operator, or arrow operator (->), performs two simultaneous operations:
•	 It dereferences a pointer.
•	 It accesses a member of the pointed-to object.

You can use this operator to reduce notational friction, the resistance a programmer feels in expressing their intent in code, when you’re handling pointers to classes.

You’ll need to handle pointers to classes in a variety of design patterns. For example, you might want to pass a pointer to a class as a function parameter. If the receiving function needs to interact with a member of that class, the member-of-pointer operator is the tool for the job.


*/
