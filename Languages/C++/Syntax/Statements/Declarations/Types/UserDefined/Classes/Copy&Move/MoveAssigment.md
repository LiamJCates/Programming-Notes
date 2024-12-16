Move Assignment
You can also create a move analogue to copy assignment via operator=.

The move assignment operator takes an rvalue reference rather than a const
lvalue reference, and you usually mark it noexcept.

Listing 4-36 implements such a move assignment operator for SimpleString.

SimpleString& operator=(SimpleString&& other) noexcept {
  if (this == &other) return *this;
  delete[] buffer;
  buffer = other.buffer;
  length = other.length;
  max_size = other.max_size;
  other.buffer = nullptr;
  other.length = 0;
  other.max_size = 0;
  return *this;
}

Listing 4-36: A move assignment operator for SimpleString

You declare the move assignment operator using the rvalue reference syntax and the noexcept qualifier, as with the move constructor. The self-reference check handles the move assignment of a SimpleString to itself.

You clean up buffer before assigning the fields of this to the fields of
other and zero out the fields of other y. Aside from the self-reference
check v and the cleanup w, the move assignment operator and the move
constructor are functionally identical.
Now that SimpleString is movable, you can complete the SimpleString constructor of SimpleStringOwner:
SimpleStringOwner(SimpleString&& x) : string{ std::move(x)u } { }
The x is an lvalue, so you must std::move x into the move constructor
of string u. You might find std::move odd, because x is an rvalue reference.
Recall that lvalue/rvalue and lvalue reference/rvalue reference are distinct
descriptors.
Consider if std::move weren’t required here: what if you moved from x
and then used it inside the constructor? This could lead to bugs that are
hard to diagnose. Remember that you cannot use moved-from objects
except to reassign or destruct them. Doing anything else is undefined
behavior.
Listing 4-37 illustrates the SimpleString move assignment.
--snip--
int main() {
SimpleString a{ 50 };
a.append_line("We apologize for the"); u
SimpleString b{ 50 };
b.append_line("Last message"); v
a.print("a"); w
b.print("b"); x
b = std::move(a); y
// a is "moved-from"
b.print("b"); z
}
a: We apologize for the w
b: Last message x
b: We apologize for the z
Listing 4-37: A program illustrating move assignment with the SimpleString class128 Chapter 4
As in Listing 4-31, you begin by declaring two SimpleString classes with
different messages: the string a contains We apologize for the u, and b contains Last message v. You print these strings to verify that they contain the
strings you’ve specified wx. Next, you move assign b equal to a y. Note that
you had to cast a to an rvalue using std::move. After the move assignment, a
is in a moved-from state, and you can’t use it unless you reassign it to a new
value. Now, b owns the message that a used to own, We apologize for the z.
