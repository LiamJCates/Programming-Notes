A computer program is a set of instructions that the computer can execute

programmers write these programs using one or more programming languages.


Execution Environment
Most end user applications that we run, such as a web browser, word processor, or mail client, can't communicate with the computer hardware directly. They require a layer in between that takes care of this. This layer is called the operating system. Windows and Linux are two examples of well-known operating systems. The main purpose of an operating system is to take care of the direct communication between the applications that we use and the hardware, such as the processor, memory, hard drives, keyboards, and printers. To be able to perform this communication, the operating system requires special programs that are designed to communicate with a particular device. These programs are called device drivers.

Programmers will write the end user applications, the operating system, and the device drivers, but the end user applications category is by far the most common. The programs we write will communicate with the system kernel, which is the core of the operating system. The operating system will take care of the direct communication with the underlying hardware. The good thing about this layered structure is that we only need to talk to the operating system, so we don't need to think about what kind of mouse the user has or how to send a line of text to a particular printer model. The operating system will talk to the device drivers for the mouse and the printer, and the driver will know precisely how to communicate with that device.

If we write a program and that program wants to print the text Hi there computer! to the screen, then this request will be sent to the operating system. The operating system will pass this on to the device driver for the monitor, and this driver will know how to send this to the monitor connected to this computer.

The text entered will not magically appear on the screen, though. It will pass through several layers inside the computer.

These layers are modeled by a design today known as the Von Neumann Architecture, and it defines four different components that can be used to construct a computer. These components are as follows:

• A processing unit that has an arithmetic logic unit and registers for the processing unit to use.

• A control unit that contains an instruction register and a program counter. These are used to execute programs.

• Memory that stores data and instructions. This memory is volatile, meaning that its content will be erased when the power is turned off or the computer is restarted.

• External mass storage. This is long-time storage for programs and data that can also be preserved after a computer restarts.

• Input and output mechanisms. Today, this is typically a keyboard, a mouse, and a monitor.

All of these components, except external mass storage, come into play when text is entered on the keyboard and displayed on the screen.




Computers perform four basic tasks:

take input
We can provide input to the computer in many ways, such as a file, a network download, a keyboard, a mouse, voice commands, touch screens, etc...

store data
The input is translated into meaningful computer data that is sent to the computer's internal memory storage

process data
The central and graphical processing unit retrieves the data from storage and performs operations on it, the results of which are then sent back to be stored in memory.

output results
Data processing results are retrieved from memory and sent to an output device like a printer, speakers, a monitor, a network upload, etc...

















Why Binary
The computer only works with numbers in the binary form, also known as base 2, and that is why we often hear that a computer only understands zeros and ones.

Why is it that computers only work with zeros and ones? Why can't they work directly with text or images, for example? The answer is that it is rather easy to build circuits that can represent two states. If you have an electrical wire, you can either run electricity through it or not. While differing levels of electrical activity could be detected, the stability and precision of such readings are often difficult to achieve quickly. It is much easier to detect either the presence or lack of electrical activity.

The flow or no flow of electricity could represent several things, such as on or off, true or false, or zero or one. These two states are often zero representing no electricity flowing and one symbolizing that we do have
flow. If we can serve these two states, we could add more wires and, by doing so, represent a longer group of ones and zeros and ones. Longer groups of ones and zeros allow us to representing values using the base two binary numeral system.

Representing Bases

While computers only understand binary values, long strings of zeros and ones are cumbersome for human interpretation. Often we would like to specify numeric values using a wider range of digits by using a different base. Using a different base, we can express the same numeric value in multiple ways.

However, we first must understand the difference between digits and numbers: a digit is a single symbol representing a value, whereas a number is a sequence of one or more digits. So, for example, we can talk about the digit 7, but not the digit 12 (as it is a number made up of 2 digits).

To understand the different bases, let's consider how many digits they have. In our daily life, we use the decimal system, called base 10, because we have 10 digits, from 0 to 9.

Other bases include:
base 2 binary system, with two digits, 0 and 1.
base 16 hexadecimal system, with 16 digits, 0 to 9 and A to F.



Hexadecimal

While a number with one digit in the decimal system must use two digits upon reaching a value greater than or equal to 10, the base 16 hexadecimal system must only do so after reaching a value greater than or equal to 16.

As it is a base 16 system, each hexadecimal digit can represent 16 values; therefore, we need 16 digits. Since we only have 10 digits in our decimal system, we must use some symbols in the hexadecimal system to represent the values between 10 and 15. By convention those symbols are the six letters A to F.


Binary Values

When we have one single binary digit, we call it a bit, and if we place them in groups of 8 bits, we call them a byte. One byte can hold values between 0 and 255. This is because a 1 in all positions (11111111) will be 128 + 64 + 32 + 16 + 8 + 4 + 2 + 1= 255.

By using lots of zeros and ones, the computer can represent any number in binary form, and if it can represent numbers, it can serve other things too, such as text by specifying a numeric value for each given symbol.



Understanding ASCII and Unicode
The symbols representable by a computer a generally known as characters. If you give each letter of the English alphabet a numerical value, you could represent these textual characters with numbers. We could, for example, say that A=1, B=2, and so on. The specification of which values are associated with a given symbol is known as a character encoding scheme.

Two common character encoding schemes are ASCII and Unicode. It is not important to understand exactly how they work; the only thing we need to understand is that a number can represent every character. This number can then be looked up using a given encoding scheme.

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

machine code is a set of numerical values that the computer interprets as instructions. The instructions we give to the computer will be designated by unique numbers, called opcodes. Each processor type has a specific set of instructions. That is why a program written for a Mac can't run on a PC running Windows, for example. The operations can be things such as AND, OR, ADD, and so on. For example, AND could have an opcode value of 1, and OR could have an opcode value of 9.

The processor will also have several registers. A register is an area, where the processor can store data it is currently working with. Before executing an operation, we will need to move the data we want as input to the operation, from memory, into some of these registers. The result of the operation, the output, is also stored in a register.

In reality, things are a bit more complicated than this, but we do not need to go into all the details here. We can now recall the image of the four operations that were common for all computers: input, storage, process, and output. We first get some input, and it will go to the computer's memory for storage. The processor will then retrieve it from its registers and perform operations on it, which is the process part. When we have the result of the operations, it will go back into the memory so that it can later be sent to the output.

One way to write these instructions is to use something called an assembly. This is a way of writing a program where we use three-letter abbreviations for the opcodes and have names for the registers which are also internally represented by their own numbers. By doing this, it will be easier to read and understand the instructions we give. We can then use a program that can translate the assembly code into machine code.

The assembly language is the first programming language we encounter. The assembly language can look like this:
mov eax, 14
mov ebx, 10
add eax, ebx

Here, we are moving (mov) the value of 14 into one of the registers, called eax, and then we are moving the value of 10 into another register, called ebx. We are then performing the add operation on the contents of these two registers. The result, 24, will be written back into the register eax.

If the move operation has an opcode of 136 and the add operation has an opcode of 1, we can use these values together with the numerical representations of the registers to have all of this in only numerical format. And, as we know, everything that is numerical can be represented in binary form, that is, with zeros and ones.

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

When looking at this program, we can write the numbers in binary or decimal format if we want to. However, to make it easier to read, we often use hexadecimal numbers as we can then use fewer digits. For example, 15 in the decimal format (two digits) is 1111 (four digits) in binary, but only F (one digit) in hexadecimal. It is just more compact – that is the only reason we do this. Don't worry if you don't understand anything about the machine code program. It is not supposed to be readable for humans; however, for the computer, this all makes sense. Writing code in machine code is error-prone. A number in the wrong place can be the difference between success and disaster. The natural next step, therefore, has been to create something more comfortable for humans to read and write, which the computer can then translate into machine code. One such measure has been the creation of the assembly language that we talked about earlier.

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

As you can see, this is still not that easy to understand. In the next chapter, we will learn how to write the same program using languages that resemble human language to a much higher degree.

Why do we have programming languages?
Machine code is very difficult for humans to write efficiently. It is perfect for computers, but we need something more comfortable to read, write, and understand. The time it takes to write a program, find errors and bugs in code, and update a program to add new features costs money. If the language we use can help us reduce the chance of introducing errors in code, it will reduce the costs. If it helps us understand the code when we read it, it will let us add new features faster, and so reduce costs. One goal of a programming language is that it must help us be efficient when we write programs. It is at this point that the higher-level programming languages enter the scene. They enable us to write our code in something that often, at least to some degree, resembles English.

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
int 21hWhy do we have programming languages? 25
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

Believe it or not, they both do the same thing. The first one is in assembly language and the second one is something that resembles a high-level language. Even if you have never seen code before, it is not hard to understand what this program is doing. It compares two text strings, Alice and Bob, and if they are equal, prints this result to the screen, and if not, prints Not Equal. Of course, they are not equal, so the output here is Not Equal. What these two examples show is the leap that was taken to prove how easy code could be if we compare machine code and assembly code. In Chapter 1, Introduction to Computer Programs we saw a program that was first written in machine code and then in assembly that printed the text Hello, World to the screen. What would that program look like in some of the high-level languages that we use today?

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


A programming language is nothing more than a tool that we use to create programs, and as with all tools, we want it to be as functional for the task as possible. Different types of applications have requirements that make one language better suited to meet them than other language will.

Some programming languages can give a programmer direct access to computer hardware. This means that it will let the programmer have more control over how data will be represented and stored in the computer's memory. The benefit of this is that programs written in this sort of language have the potential of being more efficient or running faster. However, this comes at the cost of complexity. When more control is given to the programmer, we also give the programmer more chances to make errors.

Some programming languages also have a structure that makes writing programs easier, which in turn reduces the time spent by the programmer in writing the software. These languages give us less control but are easier to use. The disadvantage here is that programs written in these languages tend to run slower. If we write some administrative software, the speed of the application will not be our focus; rather, we want a programming language that will help us write high-quality software with as few errors as possible.

Requirements like this can also be the motivation for creating a new programming language.




## Source Code Translation
The code that a programmer writes is called source code, this code must be translated into machine code so that the computer can understand it. There are two main principles of how this translation is done. We will first explore these two concepts and look at their pros and cons before we look at a combination of these two concepts.

One way to carry out this translation is by using an interpreter. An interpreter will look at a single line of source code, translate it into machine code, let the computer execute this line, and then move on to the next line of code. The way the interpreter works is a bit like how a simultaneous translator works with human languages. A simultaneous translator will, for example, work for the UN. In the UN, everyone is entitled to speak in their native language. A group of translators listens to the talk, and as they listen, they will translate it into another language. Delegates can then listen to the speech in real time in their native language through headphones.

Another way to carry out the translation is by using a technique called compiling. When we compile source code into machine code, we first translate every line of code, and it is not until the translation of all of the lines of code has been done that the program is executed. We can compare this to the concept of translating a book. First, an author writes the book in one language. A translator will then translate the whole book into another language. It is not until the translation of all of the text in the original book is done that it will be available to read.

Interpreting and compiling are two of the main techniques for translating source code. A programming language can use either one of these techniques, and a language is therefore often referred to as either an interpreted or compiled language.

Let's look more closely at these two techniques so that we can understand them better before we compare them.

When an interpreted languages source code is executed, a specialized program called an interpreter will read the source code line by line and translate each line during runtime, the time the program is active.

A compiler will instead translate all the code in the source code document and store it in a file containing the machine code instructions. When we want to run the program, we can use this file to run it; it is at this point that the CPU will execute the machine code.


What are the advantages and disadvantages of these two methods of translation?

Advantages of Interpretation:
• It has a smaller program size.
• If we have the code and an interpreter, we can run it on any platform (for example, Windows, Linux, macOS, and so on).
• Interpreted languages tend to be more flexible for programmers to use. One
example of this is called dynamic typing.

Disadvantages of  Interpretation:
• The program runs slower as translation happens during runtime.
• Anyone who wants to run the program must have an interpreter installed.
• The user of the program has access to the source code, so if it is a commercial application, all the code we have written will be accessible to anyone, including any potential business secrets.



Advantages of Compilation:
• It runs faster as the translation is done previous to runtime.
• No extra program is needed to run the application — that is, the application has all the information it needs to run, so the user does not need to have any other programs installed.
• Compiled programming languages tend to help the programmer with things such
as type checking to a higher degree.

Disadvantages of Compilation:
• The programs tend to be larger as a single line of programming language code can constitute many lines of machine code as previous examples indicate.
• We need to make versions for all of the platforms that we intend the program to run on — that is, we need a Windows version, a macOS version, and a Linux version as the file a compiler outputs is only translated for one type of machine.
• The time it takes to complete the translation can be long, making it harder to try things out as we write the program.

Some examples of interpreted languages are PHP, Ruby, and JavaScript.
Some examples of compiled languages are C, C++, COBOL, ALGOL, Fortran, and Lisp


We also have a group of languages that both compile and interpret. When they compile the source code, they do not directly compile it into machine code. They follow an intermediate step where they compile the source code into byte code. This byte code is then interpreted as the program executes. The benefit of doing this is that we get some of the advantages of both techniques. For example, this byte code can be distributed to anyone who wants to run the program, and then an interpreter will interpret the byte code into machine code for the current system that the program is executed on.

Another advantage that compiled languages have—and this applies to the technique of mixing them, too—is that if there is an error in the source code, the compiler will detect this because the syntax (the grammar of a language) has to be correct and if it is not, the compiler can't proceed and will stop the translation. The programmer then needs to go back and correct the error before the program can compile again. Mixed technique languages share a disadvantage with interpreted languages, which is that programs written with them will run slower than programs written in a compiled language.

Some examples of mixed technique languages are Python, Java, C#, and Perl.




## Language Description
A programming language is a formal language comprising a set of instructions that produce various kinds of output.
Thousands of different programming languages have been created, and more are being created every year.
The description of a programming language is usually split into the two components of syntax (form) and semantics (meaning).


## Syntax
https://en.wikipedia.org/wiki/Syntax_(programming_languages)
Just as human languages have grammar to dictate the rules of the language, a programming language has syntax. The syntax is the rules for how we write a program using a language. There is one big difference between grammar and syntax and that is about forgiveness for errors. If you meet someone who speaks your native language but makes some errors here and there, you will still be able to understand what that person is trying to communicate to you. That is not the case for the syntax of a programming language. If written source code violates the syntactical rules of a programming language its interpretation or compilation will not be successful, the syntax must be flawless.

If we have an error in the syntax, it will be discovered during the translation, and here is where a compiled and an interpreted language will differ. For a compiled language, all the translation will be done before we can execute the program. If we have an error in the syntax, the compilation will stop as soon as the compiler discovers the mistake. We must then find the fault and correct it, then let the compiler try to translate the code again. It is not until our code does not have any syntax errors that we have something we can run completely.

This is different for an interpreted language as it will translate line by line as we run the program. This means that a syntax error can be hidden in a corner of the program that is rarely executed and will not be discovered until we eventually want to run that line of code. When this happens, the program will crash mid-execution with an error message letting us know what problem was there with our syntax.


This means that a source code document that we have written can either be syntactically correct or incorrect. The syntax is a set of rules defining how the source code will be written and structured. But that is not all. The syntax also defines other things, such as the words that make up the language. These are called keywords.



Keywords
When learning a new language, we must keep track of its keywords, also called reserved words, as these words are reserved by the language. If we use a keyword by accident for something other than its intended use, we will get an error. A language will typically have between 30 and 50 keywords. Here is a list of some common keywords:
• for
• if
• else
• break
• continue
• return
• while

Most programming languages are case sensitive, so the use of uppercase and lowercase letters matters—for example, "if" is not the same thing as "If" or "IF".



Operators
Apart from keywords, we also have something called operators, which we can use to represent the actions we want to perform on data much like the arithmetic operators of mathematics.

A programming language will also have several operators, and these are what we use to accomplish things such as addition and multiplication, as well as to compare data. The symbols that can be used are also defined as part of the language syntax.



Code Blocks
Having our code in one long sequence would make it difficult to read. It would be like having a book with no chapters or paragraphs. To add the concept of chapters and paragraphs to our code, we use something called code blocks.

It is common for a language to also allow us to define blocks of code. There are several reasons why you would want to do that, and we will talk more about them in later. However, for now, we can think of a block of code like a paragraph in standard text.

The language then defines how we mark the beginning and end of the block. A common technique that many languages employ is using parentheses, also called braces or curly brackets — {}. A language like this would open the code block with { and close the code block with }. Everything within is considered part of the block.

Other languages might have different ways to do the same thing, so again, when switching between languages, we must learn what the syntax rules are for that language.



Relations to mathematics
Programming is closely related to mathematics as programming has borrowed many concepts from it.

One of these concepts is the use of variables, which are essentially the same as they are in mathematics in the sense that we can use a name to represent a variable (a value that can change).

Another concept borrowed from mathematics is the use of operators. In mathematics, an operation takes zero or more input values (called operands) to produce a well-defined output value. Operators were mentioned above and the example of the arithmetic operators was given. Many things can represent an operation's operands, including variables as well as literals which represent values directly in source code like the number "1".

Another concept borrowed from mathematics is functions. In mathematics, a function is something that takes an input value and transforms it in some way to produce an output. This is close to how we can describe functions in programming as well.


The rules for how we can name variables as well as structure operations and functions are also part of the language syntax.

One thing we must remember when approaching programming is that if we understand how these concepts work in mathematics, that does not mean that we can apply this knowledge directly to programming, even if they happen to share the same name. They will be related, but how things are done in programming will differ from how things work in math.
