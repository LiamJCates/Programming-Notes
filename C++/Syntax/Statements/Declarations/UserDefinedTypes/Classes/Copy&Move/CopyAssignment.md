## Copy Assignment
A copy constructor takes an object of the same class by reference as a parameter. This parameter is an alias of the source object and is the handle you have in writing your custom copy code.

The copy constructor has ensured deep copy in cases such as function calls:
ClassName sayHello("Hello from String Class");
UseMyString(sayHello);

However, what if you tried copying via assignment:
ClassName overwrite("who cares? ");
overwrite = sayHello;

This would still be a shallow copy if you have yet to supply a copy assignment operator=. In the absence of one, the compiler has supplied a default for you that does a shallow copy.


## Implementing Copy Assignment

Syntax:
ClassName::operator= (const ClassName& copySource)
{
//... copy assignment operator code
}



Creates a copy of an object and assigns it to another existing object

void dont_do_this() {
  SimpleString a{ 50 };
  a.append_line("We apologize for the");
  SimpleString b{ 50 };
  b.append_line("Last message");
  b = a;
}

Listing 4-28: Using the default copy assignment operator to create a copy of an object and assign it to another existing object

NOTE
The code in Listing 4-28 causes undefined behavior because it doesn’t have a userdefined copy assignment operator.

The last line at copy assigns a to b.
The major difference between copy assignment and copy construction is that in copy assignment, b might already have a value. You must clean up b’s resources before copying a.

WARNING
The default copy assignment operator for simple types just copies the members from the source object to the destination object. In this case of a full featured object, this is very dangerous for two reasons.
First, the original object gets rewritten without freeing the dynamically allocated char array.

Second, now two objects own the same buffer, which can cause dangling pointers and double frees. You must implement a copy assignment operator that performs a clean hand-off.

The copy assignment operator uses the operator= syntax, as demonstrated:

struct SimpleString {
--snip--
SimpleString& operator=(const SimpleString& other) {
if (this == &other) return *this; u
--snip--
return *this; v
}
}
A user-defined copy assignment operator


The copy assignment operator returns a reference to the result, which
is always *this. It’s also generally good practice to check whether other
refers to this.
You can implement copy assignment for SimpleString by following these
guidelines: free the current buffer of this and then copy other as you did in
copy construction, as shown in Listing 4-30.

SimpleString& operator=(const SimpleString& other) {
  if (this == &other) return *this;
const auto new_buffer = new char[other.max_size];
delete[] buffer;
buffer = new_buffer;
length = other.length;
max_size = other.max_size;
strcpy_s(buffer, max_size, other.buffer);
return *this;
}
Listing 4-30: A copy assignment operator for SimpleString

The copy assignment operator starts by allocating a new_buffer with the
appropriate size. Next, you clean up buffer. You copy buffer, length,
and max_size and then copy the contents from other.buffer into your own
buffer.
