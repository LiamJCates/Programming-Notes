## Pointers Are Dangerous
It’s not possible to convert a pointer to an array, which is a good thing. You
shouldn’t need to, and besides it wouldn’t be possible in general for a compiler to recover the size of the array from a pointer. But the compiler can’t save you from all the dangerous things you might try to do.



Buffer Overflows
For arrays and pointers, you can access arbitrary array elements with the
bracket operator ([]) or with pointer arithmetic. These are very powerful
tools for low-level programming because you can interact with memory
more or less without abstraction. This gives you exquisite control over the
system, which you need in some environments (for example, in system programming contexts like implementing network protocols or with embedded controllers). With great power comes great responsibility, however, and you
must be very careful.
Simple mistakes with pointers can have catastrophic and mysterious consequences.

By accessing the element at an index greater than the length of the pointer, we can try to interact with memory locations past the storage allotted, potentially writing out-of-bounds memory.

As no bounds checking occurs in C++ code that does this compiles without warning.

At runtime, you get undefined behavior. Undefined behavior means the
C++ language specification doesn’t prescribe what happens, so your program might crash or open a security vulnerability.

To understand the ramifications of out-of-bounds access, you must understand the connection between subscript operators and pointer arithmetic.

  #include <cstdio>

  int main() {
    char lower[] = "abc?e";
    char upper[] = "ABC?E";
    char* upper_ptr = upper; // Equivalent: &upper[0]
    lower[3] = 'd'; // lower now contains a b c d e \0
    upper_ptr[3] = 'D'; // upper now contains A B C D E \0
    char letter_d = lower[3]; // letter_d equals 'd'
    char letter_D = upper_ptr[3]; // letter_D equals 'D'
    printf("lower: %s\nupper: %s", lower, upper);
    lower[7] = 'g';     //Super bad. You must never do this.
  }
Output
lower: abcde
upper: ABCDE


Consider the previous source code with pointer arithmetic and dereference operators rather than subscript operators:

  #include <cstdio>

  int main() {
    char lower[] = "abc?e";
    char upper[] = "ABC?E";

    char* upper_ptr = &upper[0];

    *(lower + 3) = 'd';
    *(upper_ptr + 3) = 'D';

    char letter_d = *(lower + 4); // lower decays into a pointer when we add
    char letter_D = *(upper_ptr + 4);

    printf("lower: %s\nupper: %s", lower, upper);
    *(lower + 7) = 'g';
  }

The lower array has length 6 (the letters a–e plus a null terminator).
It should now be clear why assigning lower[7] is perilous. In this case,
you’re writing to some memory that doesn’t belong to lower. This can result
in access violations, program crashes, security vulnerabilities, and corrupted
data. These kinds of errors can be very insidious, because the point at which
the bad write occurs might be far removed from the point at which the bug
manifests.
