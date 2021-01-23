Nested Class
A class within another class is called a nested class.
Compelling reasons for using nested classes include the following:
1. It is a way of logically grouping classes that are only used in one
place: If a class is useful to only one other class, then it is logical to
embed it in that class and keep the two together. Nesting such "helper
classes" makes their package more streamlined.
2. It increases encapsulation: Consider two top-level classes, A and B,
where B needs access to members of A that would otherwise be
declared private. By hiding class B within class A, A's members can be
declared private and B can access them. In addition, B itself can be
hidden from the outside world.
3. It can lead to more readable and maintainable code: Nesting small
classes within top-level classes places the code closer to where it is used.
A nested class has an independent set of modifiers from the outer class.
Visibility modifiers (public, private and protected) effect whether the nested
class definition is accessible beyond the outer class definition. For example,
a private nested class can be used by the outer class, but by no other classes.
