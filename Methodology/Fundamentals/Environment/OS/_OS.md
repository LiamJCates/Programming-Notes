Computer
Every computer is composed of various components that communicate using binary values. The configuration on these components is known as the computer architecture. All of the computer's components are controlled, either directly or indirectly, by commands executed by the computer's central processing unit, or CPU.

The CPU is a hardware unit that understands and executes binary valued commands specified by a given instruction set architecture.



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
