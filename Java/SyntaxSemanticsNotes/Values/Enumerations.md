Enumerations define a data type with a fixed number of valid values.

An enum type is a special data type that enables a variable to be a set of predefined constants. The variable must be equal to one of the values that have been predefined for it.

An object of an enumeration type can hold only the values it defines.
Syntax:
access-modifier enum enum-type{
  constant1, constant2, ..., constantN
}

Example
access-modifier enum DaysOfTheWeek {
    MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY
}

The identifiers MONDAY, TUESDAY, and so on, are called enumeration constants and, as constants, are capitalized by convention. Each is implicitly declared as a public, static member of DaysOfTheWeek. An enumeration constants’ type is the type of the enumeration in which the constants are declared.

DaysOfTheWeek day = DaysOfTheWeek.MONDAY;

Java, calls these constants self-typed, where “self” refers to the enclosing enumeration.








Basic Use
When coding your own enumerations, it's common to make them public and store them in a separate class file. The enumeration is then available to all classes within the application.

Though enumerations define a class type, you do not instantiate an enum using new.
Instead, you declare an enumeration variable and assign only the constants defined by the enumeration qualified by the enumeration type.

DaysOfTheWeek day;
day = DaysOfTheWeek.MONDAY;


An enumeration value can also be used to control a switch statement.
All case statements must use constants from the same enum as that used by the switch expression.

switch(day){
    case MONDAY:
        //…
    case TUESDAY:
        //…
    case …
}

The enumeration constants are used without being qualified by their enumeration type name.
This is because the type of the enumeration in the switch expression implicitly specifies the enum type of the case constants.
Qualifying the constants in the case statements would cause a compilation error.



### Static Import
Java 5 introduced static imports which simplify references to the constants in an enumeration.

import static com.example.DaysOfTheWeek.*;
DaysOfTheWeek day;
day = TUESDAY;

This is possible because a static import allows you to import the static  class members of the specified package, which enumeration constants are implicitly. Although you can save some typing by using static imports, they often result in code that's more difficult to read and potentially lead to name collisions.




## Java Enumerations Are Class Types
It is important to understand that each enumeration constant is an object of its enumeration type.
Although you don’t instantiate an enum using new, it otherwise acts much like other classes.
The fact that enum defines a class enables the Java enumeration to have powers that enumerations in some other languages do not.
enums may define constructors, fields, methods, and even implement interfaces.

When you define a constructor for an enum, the constructor is called when each enumeration constant is created.

Each enum constant is declared with values that are passed to the constructor when the constant is created.
Constructor arguments are specified by putting them inside parentheses after each constant.
When an enumeration contains other members, the comma delimited enumeration list must end in a semicolon.
The constructor for an enum type must be package-private or private access. It automatically creates the constants that are defined at the beginning of the enum body.

Java requires that the constants be defined first, prior to any fields or methods.

Each enumeration constant has its own copy of any instance variables defined by the enumeration.

Each enumeration constant can call any method defined by the enumeration.


enum Transport {
    CAR(65), TRUCK (55), AIRPLANE(600), TRAIN (70), BOAT(22) ;

    private int speed; // typical speed of each transport

    / / Constructor
    private Transport (int s) {speed s;}

    //Method
    int getSpeed() { return speed;}
}

When a Transport variable is declared, the constructor for Transport is called once for each constant that is specified.













Enumeration classes can’t inherit a superclass as all enumerations implicitly extend: java.lang.Enum which in turn inherits from java.lang.Object



## Inherited Enumeration Methods
These classes define several methods that are available for use by all enumerations.

ordinal( ) returns the int value of an enumeration constant’s list position, called its ordinal value.

compareTo() allows the comparison of the ordinal value of two constants of the same enumeration:
final int compareTo(enum-type e)

All enumerations inherit the methods: values( ) and valueOf( ):
public static enum-type[ ] values( )
public static enum-type valueOf(String str)

In both cases, enum-type is the type of the enumeration.
values( ) returns an array that contains a list of the enumeration constants.
valueOf( ) returns the enumeration constant whose value corresponds to the parameter string.

DaysOfTheWeek[] day = DaysOfTheWeek.values();
//day = [MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY];

DaysOfTheWeek day = DaysOfTheWeek.valueOf("MONDAY");

for(DaysOfTheWeek d : DaysOfTheWeek.values())
  System.out.println(d);

Two Important Restrictions There are two restrictions that apply to enumerations. First, an enumeration can’t inherit another class. Second, an enum cannot be a superclass. This means that an enum can’t be extended. Otherwise, enum acts much like any other class type. The key is to remember that each of the enumeration constants is an object of the class in which it is defined.









Q: Since enumerations have been added to Java, should I avoid the use of final variables? In other words, have enumerations rendered final variables obsolete?
A: No. Enumerations are appropriate when you are working with lists of items that must be represented by identifiers. A final variable is appropriate when you have a constant value, such as an array size, that will be used in many places. Thus, each has its own use. The advantage of enumerations is that final variables don’t have to be pressed into service for a job for which they are not ideally suited.
