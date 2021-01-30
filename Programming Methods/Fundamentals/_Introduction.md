## Introduction to Computer Programs
Modern computers are incredibly fast, and getting faster all the time. However, computers have some significant constraints: they only natively understand a limited set of commands, and must be told exactly what to do.

A computer program, commonly called an application, is a set of instructions that the computer can perform in order to perform some task. The process of creating a program is called programming. Programmers typically create programs by producing source code (commonly shortened to code), which is a list of commands typed into one or more text files.

The collection of physical computer parts that make up a computer and execute programs is called the hardware. When a computer program is loaded into memory and the hardware sequentially executes each instruction, this is called running or executing the program.

Thusly, a computer program is a set of instructions that the computer can execute.

While modern programming languages use characters that are common to the alphabet of human languages, these characters are translated into values that the computer can understand and execute using mathematic principles. This is because computers only understand values made of ones and zeros, called binary. The collection of binary values understood by a given computer is known as its machine language.

All computer languages are translated from something that tends
to be easy for a human to understand (source code) into something
that is executed on a computer (machine instructions).

### Why Binary
The computer only works with numbers in the binary form, that is why we often hear that a computer only understands zeros and ones.

Why is it that computers only work with zeros and ones? Why can't they work directly with text or images, for example? The answer is that it is rather easy to build circuits that can represent two states. If you have an electrical wire, you can easily represent two states by either running electricity through it or not. While differing levels of electrical activity could be detected, the stability and precision of such readings are often difficult to achieve quickly. It is much easier to detect a presence or lack of electrical activity.

The presence or absence of electricity could represent several things, such as on and off, true and false, or zero and one, respectively. If we can serve these two states, we could add more wires and, by doing so, represent a longer group of zeros and ones. Longer groups of ones and zeros allow us to representing values using the binary numeral system.



## Representing Bases
A "character set" assigns numeric values to characters of human language. By changing the base those numbers are represented in, we can express any group of characters, called a string of characters or "character string", in binary.

While computers only understand binary values, "binary strings", long groups of zeros and ones are cumbersome for human interpretation. Humans most often communicate numeric values using the "decimal system". The process of transforming decimal values to binary values is known as "changing base".

Example of the character string "hello", its character set values, and the resulting binary string after changing the base of the character set values:

     h       e         l        l       o
    104     101       108      108     111
  1101000 01100101 01101100 01101100 01101111

To make sense of the example above we must understand some definitions and explore the operations that take place when changing the base of a number.

A number's base is defined as the number of unique digits used to represent a number in a given numeric system. By changing a value's base, we may express the same numeric value in multiple ways; allowing us to turn the decimal numbers humans are familiar with into the binary values processed by computers.

The first set is understanding the difference between digits and numbers:
  digit: a single symbol representing a value.
  number: a sequence of one or more digits.

For example, we can talk about the digit 7, but not the digit 12 (a number made up of 2 digits).

The defining characteristic of a given bases is the variety of digits expressed by it. In our daily life, we use the decimal system, called base 10, because we have 10 digits, from 0 to 9.

Numbers in the decimal system are represented with two or more digits upon reaching a value greater than or equal to 10. This can be seen:

  9 + 1 = 10

Likewise, for each digital position, once the value of that digital position exceeds 9, another decimal digit is added to express a value higher that it can contain:

  99 + 1 = 100
  999 + 1 = 1000,
  ...
  9...9 + 1 = 10...0

Once the value achieved exceeds 9 we must use another decimal digit to represent that value. This can be seen when we need two decimal digits to represent 10 when the value of the first digital position is exceeded, and when we need three decimal digits to represent 100 when the value of the second digital position is exceeded. This pattern, of using one more digit when the highest value representable by a string of decimal digits is exceeded by one or more, continues indefinitely allowing us to express any numeric value in decimal.

We will now see how this property manifests in the binary system.


Binary Values
When we have a single binary digit, called a bit, we are able to represent two numeric values 0 and 1. Similar to the functionality of the decimal system, for each digital position, once the value of that digital position exceeds 1, another decimal digit is added to express a higher value:

  1 + 1 = 1     //Decimal representation: 1 + 0 = 1
  1 + 1 = 10    //Decimal representation: 1 + 1 = 2
  10 + 1 = 10   //Decimal representation: 2 + 1 = 3
  11 + 1 = 100  //Decimal representation: 3 + 1 = 4
  ...
  1...1 + 1 = 10...0

As seen above, the first addition operation looks the same as we would represent it in decimal. However, once the value achieved exceeds 1 we must use another binary digit to represent that value. This can be seen when we need two binary digits to represent 2 as the value of the first digital position is exceeded, and when we need three binary digits when the value of the second digital position is exceeded. The same pattern, of using one more digit when the highest value representable by a string of binary digits is exceeded by one or more, continues indefinitely allowing us to express any numeric value in binary.




A groups of 8 bits is called a byte. One byte can hold values between 0 and 255. This is because a 1 in all positions (11111111) will be 128 + 64 + 32 + 16 + 8 + 4 + 2 + 1= 255.


Hexadecimal
The base 16 hexadecimal system is also common in computing. We will first explore how to use it then given an example of why it is useful.

As it is a base 16 system, each hexadecimal digit can represent 16 values; therefore, we need 16 digits. Since we only have 10 digits in our decimal system, we must use some symbols in the hexadecimal system to represent the values between 10 and 15. By convention those symbols are the six letters A to F.

Similar to the decimal system of base 10, the hexadecimal system of base 16 uses larger digits once the value at that digital position exceeds 16.

  F + 1 = 10    //Decimal representation: 15 + 1 = 16

Todo: Show correspondence between a single hexadecimal digit and four binary digits.



Introduction to Character Encoding
By using a string of zeros and ones, the computer can represent any number in binary form, and if it can represent numbers, it can serve other things too, such as text by specifying a numeric value for each given symbol.

We mentioned the concept of a character set earlier.

The symbols representable by a computer are generally known as characters. If you give each letter of the English alphabet a numerical value, you could represent these textual characters with numbers. We could, for example, say that A=1, B=2, and so on. The method used to specify which values are associated with a given symbol is known as a character encoding scheme and a collection of these associations is called a character set.

Two common character encoding schemes are ASCII and Unicode. It is not important to know the associations given by these character sets; the only thing we need to understand is that a number can represent a character via some encoding scheme. This number can then be looked up using a character set that follows an encoding scheme.

The ASCII table uses one byte to represent different characters. The table starts with characters that are non-printable. Eventually, it reaches the characters in the English alphabet. So, A, for example, is 65, B is 66, and so on.

255 characters will not take us far as humans use many different alphabets as well as other symbols. That is why we also have Unicode. Its mapping to individual characters is not as direct as it is in the ASCII table, but all we need to know right now is that with it, we can use numbers to represent characters.



Representing Other Data
We've learned how to represent text in binary, but what about things other than text and numbers? What about images? And video? And sound?

Images are made up of pixels, and three values, RGB, represent each pixel. These values tell the computer how much red, green, and blue a pixel.


A video is nothing more than a composite of many images, so every frame is an image; therefore, it can be represented the same way.

A waveform can represent sound. Each peak and valley can be a number:

Now that we know how the computer can represent data, we have to find out how it processes it. To understand that, we must first dive into a corner of mathematics known as Boolean algebra.





Boolean algebra
Boolean logic or Boolean algebra, is a form of mathematics that is naturally suited to work with binary values. Boolean algebra works with only two values: true and false. It also defines operations that we can perform on these two values, the simplest of these is NOT, AND, OR, and XOR.

NOT is the simplest of these operations as all it does is just switch the value, so not true is false, and not false is true. For example, if I say, "It is raining today," this statement can be true or false. It is true if it rains and false if it is not. If I instead say, "It is NOT raining today," then the statement will be true if it doesn't rain and false if it does.

AND takes two statements that can be either true or false and evaluates them into a single value. The outcome will be true if both incoming values are true and false in all other situations. If I say, "It is raining today, AND I have a blue umbrella," the statement will only be true if both parts are true, that is, if it is actually raining and my umbrella is actually blue. However, if it is raining but my umbrella is pink, what I say will be false, even though half of it was true.

OR takes two statements that can be either true or false and evaluates them into a single value. The outcome will be true if either or both incoming values are true and false otherwise. If I say, "Today I will go to the beach OR I will go to town," then the statement will be true whether I either go to the beach or to town, and also if I manage to do both.

XOR takes two statements that can be either true or false and evaluates them into a single value. The outcome will be true if one or the other incoming values are true but not both. We can imagine an xor by considering whether you would look silly on a rainy day:
If you are inside while using an umbrella you look silly.
If you are inside while not using umbrella, it is ok.
If you are outside while using umbrella, it is ok.
If you are outside while not using an umbrella you look silly.

We can illustrate how these operations work in something called a truth table. A
truth table is a way to describe how an input of the true and false values is transformed by an operation. The input is often referred to as P if we only have one input value, or P and Q if we have two. The result is shown in the last column.



| P | NOT P|
|---|------|
| true | false |
| false | true |

| P | Q | P AND Q|
|---|---|--------|
| true | true | true |
| true | false | false |
| false | true | false |
| false | false | false |

| P | Q | P OR Q|
|---|---|--------|
| true | true | true |
| true | false | true |
| false | true | true |
| false | false | false |

| P | Q | P XOR Q|
|---|---|--------|
| true | true | false |
| true | false | true |
| false | true | true |
| false | false | false |



We can accomplish these operations with the help of transistors. There is no need for us to go into the details of how a transistor works – just knowing that it can be used to represent true/false, on/off, or 0/1 is enough. We can then connect several transistors into different configurations to accomplish operations such as AND, OR, and NOT. These combinations are called gates, so we will have a group of transistors called an a NOT gate, an AND gate, an OR gate, and a XOR gate.

These gates can then be connected further to construct circuits that can perform operations such as addition, subtraction, multiplication, division, etc..., on binary values with many digits.















Machine Code

Now that we have circuits that can perform some basic operations on numbers, and we have data in the form of numbers, we can start to write programs that will perform operations on the data. We can do that with the only thing the computer understands: machine code, the native language of the computer

A single instruction to a computer could look like this:

00000	10011110

machine code is a set of numerical values that the computer interprets as instructions.

A particular computer's machine language program that allows a user to input two numbers, adds the two numbers together, and displays the total could include these machine code instructions:

000001001111
000011111010
000101001111
000111101010
001001011111
001010000000

Each binary value above is an instruction, a single operation of a processor defined by the processor instruction set.

The size or length of an instruction varies widely, from as little as 4-bits in some microcontrollers to 512+ bits in some specialized processors. Most modern processors have instruction sizes between 16 and 64 bits.

On traditional architectures, an instruction includes an operation to be performed, and zero or more operands which are the values the operation is performed with.

Each operation, such as AND, OR, ADD, and so on, is designated by a unique number, called its opcode. For example, ADD could have an opcode value of 1 or 001, and OR could have an opcode value of 5 or 101.

To hold instructions, the input values they operate on, and their resulting output, the processor will use registers. A register is a small amount of fast storage located on the processor. Each register is assigned a number value that the processor can use to reference the data it holds.

A computer instruction that uses an ADD operation 001 to add the values in register one, 001, and register two 010 and stores them in register three 011 might look like this:

  001 001 010 011

In reality, things are a bit more complicated than this, but we do not need to go into all the details here.

As you can imagine, programming a computer directly in machine language using only ones and zeros is very tedious and error prone.

One way to write these instructions is to use something called assembly.
Assembly uses three-letter abbreviations for both the opcode values and as names for the register values. By doing this, it will be easier to read and understand the instructions we give.

The assembly language is the most basic programming language we encounter:
mov eax, 14
mov ebx, 10
add eax, ebx

Here, we are
moving (mov) the value of 14 into one of the registers, called eax
moving (mov) the value of 10 into another register, called ebx.
adding the contents of these two registers.

The result, 24, will be written back into the register eax.

We can then use a program that can translate the assembly code into machine code.

Now we have all that, we need to look at some machine code.

Example machine code

Remember that the instructions we give will be different depending on what processor and operating system we use. The following is an example of what machine code can look like for a program printing the text Hello, World! to the screen on a computer using the Linux operating system:

b8 21 0a 00 00
a3 0c 10 00 06
b8 6f 72 6c 64
a3 08 10 00 06
b8 6f 2c 20 57
a3 04 10 00 06
b8 48 65 6c 6c
a3 00 10 00 06
b9 00 10 00 06
ba 10 00 00 00
bb 01 00 00 00
b8 04 00 00 00
cd 80
b8 01 00 00 00
cd 80

Note:
To make machine code easier to read, we often use hexadecimal numbers as we can then use fewer digits. For example, 15 in the decimal format (two digits) is 1111 (four digits) in binary, but only F (one digit) in hexadecimal.

Don't worry if you don't understand the machine code program. It is not supposed to be readable for humans; however, for the computer, this all makes sense.

Writing machine code is error-prone. A number in the wrong place can be the difference between success and disaster. Assembly code is more comfortable for humans to read and write.

Here is the same program, written in the assembly language:
section .text
global _start
_start:
  mov edx,len
  mov ecx,msg
  mov ebx,1
  mov eax,4
  int 0x80
  mov eax,1
  int 0x80
section .data

msg db 'Hello, world!',0xa
len equ $ - msg

This code is then translated into machine code that the computer can understand.

However, this could be more user friendly still. There are many ways that the same program can be written using languages that resemble human language to a much higher degree.

Why do we have programming languages?
Machine code is very difficult for humans to write efficiently. It is perfect for computers, but we need something more comfortable to read, write, and understand. The time it takes to write a program, find errors and bugs in code, and update a program to add new features costs money. If the language we use can help us reduce the chance of introducing errors in code, it will reduce the costs. If it helps us understand the code when we read it, it will let us add new features faster, and so reduce costs.

One goal of a programming language is that it must help us be efficient when we write programs. It is at this point that the higher-level programming languages enter the scene. They enable us to write our code in something that often, at least to some degree, resembles English.

Look at the following code snippet:
.data
msgEqual db "Equal","$"
msgNotEqual db "Not Equal","$"
.code
main proc
mov bl,"Alice"
mov bh,"Bob"
cmp bh,bl
jne NotEqual
mov ax, seg msgEqual
mov ds, ax
mov ah, 09h
lea dx, msgEqual
int 21h
mov ah, 4Ch
int 21h
NotEqual:
mov ax, seg msgNotEqual
mov ds, ax
mov ah, 09h
lea dx, msgNotEqual
int 21h
mov ah, 4Ch
int 21h
main endp
end main

Now, compare it to the following code:

IF "Alice" == "Bob" THEN
  print "Equal"
ELSE
  print "Not Equal"
ENDIF

Believe it or not, they both do the same thing. The first one is in assembly language and the second one is something that resembles a high-level language. Even if you have never seen code before, it is not hard to understand what this program is doing. It compares two text strings, Alice and Bob, and if they are equal, prints this result to the screen, and if not, prints Not Equal.

What these two examples show is the leap that was taken to prove how easy code could be if we compare machine code and assembly code.

Earlier we saw a program that was first written in machine code and then in assembly that printed the text Hello, World to the screen. What would that program look like in some of the high-level languages that we use today?

Let's look at some modern examples.

Python:
print("Hello, World")

C:
#include <stdio.h>
int main(void)
{
  printf("Hello, World");
  return 0;
}

C++:
#include <iostream.h>
int main()
{
  std::cout << "Hello, World" << std::endl;
}

Java:
class HelloWorld {
  static public void main( String args[] ) {
    System.out.println("Hello, World");
  }
}

C#:
class HelloWorld
{
  static void Main()
  {
    System.Console.WriteLine("Hello, World");
  }
}

JavaScript:
console.log("Hello, World");


A programming language is nothing more than a tool that we use to create programs, and as with all tools, we want it to be as functional for the task as possible. Different types of applications have requirements that make one language better suited to program it in.

Some programming languages can give a programmer direct access to computer hardware. This means the programmer will have more control over how data is represented and stored in the computer's memory. The benefit of this is that programs written in this sort of language have the potential of being more efficient or running faster. However, this comes at the cost of complexity. When more control is given to the programmer, we also give the programmer more chances to make errors.

Some programming languages also have a structure that makes writing programs easier, which in turn reduces the time spent by the programmer in writing the software. These languages give us less control but are easier to use. The disadvantage here is that programs written in these languages tend to run slower. If we write some administrative software, the speed of the application will not be our focus; rather, we want a programming language that will help us write high-quality software with as few errors as possible.

Requirements like this can also be the motivation for creating a new programming language.




## Source Code Translation
The high level language modern programmers write is called source code. The many hello world examples above are each an example of their respective languages source code.

Source code must be translated into machine code so that the computer can understand it. This process is complicated and language dependent, when learning a specific language always pay attention to the method used to transform source code into machine code as it will be a necessary step in executing your program.

For now we can categorize programming languages into those that are interpreted languages and those that are compiled languages.
  Interpreted languages allow the user of a program to execute source code directly, translating them into machine code line by line as the program runs.
  Compiled languages use a compiler to transform the entirety of the source code into an machine code executable before it can be executed.





Tools for separate compilation

Separate compilation is particularly important when building large
projects. Separate compilation allows a program to be created in small,
manageable, independently tested pieces. The most fundamental
tool for breaking a program up into pieces is the ability to create
named subroutines or subprograms. A subprogram, subroutine, or function is the pieces of code that can be placed in different files, enabling separate compilation. Put another way, the function is the atomic unit of code, since you cannot have part of a function in one file and another part in a different file; the entire function must be placed in a single file (although files can
and do contain more than one function).
When you call a function, you typically pass it some arguments,
which are values you’d like the function to work with during its
execution. When the function is finished, you typically get back a
return value, a value that the function hands back to you as a result.
It’s also possible to write functions that take no arguments and
return no values.
To create a program with multiple files, functions in one file must
access functions and data in other files. When compiling a file, the compiler must know about the functions and data in the other files, in particular their names and proper usage. The compiler ensures that functions and data are used correctly. This process of “telling the compiler” the names of external functions and data and what they should look like is called declaration. Once
you declare a function or variable, the compiler knows how to
check to make sure it is used properly.



## Language Definition
A programming language is a formal language comprising a set of instructions that produce various kinds of output.

The description of a programming language is usually split into the two components of syntax and semantics:
  the syntax of a computer language is the set of rules that defines the combinations of symbols that are considered to be correctly structured statements or expressions in that language.
  the semantics of a computer language is the set of rules that defines the meaning of syntactically valid strings defined by a specific programming language

For now, remember that a languages syntax determines what form instructions take and a languages semantics determine what those instructions mean.


## Language Types
Thousands of different programming languages have been created, and more are being created every year. Many programming languages are written in either:
  an imperative form, which specifies the structure of a sequence of operations to perform to achieve the desired result
  a declarative form, which specifies the structure of the desired result, not how to achieve it

There are many other categorizations and sub-categorizations





Relations to mathematics
Programming is closely related to mathematics as programming has borrowed many concepts from it.

One of these concepts is the use of variables, which are essentially the same as they are in mathematics in the sense that we can use a name to represent a variable (a value that can change).

Another concept borrowed from mathematics is the use of operators. In mathematics, an operation takes zero or more input values (called operands) to produce a well-defined output value. Operators were mentioned above and the example of the arithmetic operators was given. Many things can represent an operation's operands, including variables as well as literals which represent values directly in source code like the number "1".

Another concept borrowed from mathematics is functions. In mathematics, a function is something that takes an input value and transforms it in some way to produce an output. This is close to how we can describe functions in programming as well.




One thing we must remember when approaching programming is that if we understand how these concepts work in mathematics, that does not mean that we can apply this knowledge directly to programming, even if they happen to share the same name. They will be related, but how things are done in programming will differ from how things work in math.
