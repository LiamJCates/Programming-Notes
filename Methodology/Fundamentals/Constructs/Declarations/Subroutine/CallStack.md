Call stack

Most modern implementations of a subroutine call use a call stack, a special case of the stack data structure, to implement subroutine calls and returns. Each procedure call creates a new entry, called a stack frame, at the top of the stack; when the procedure returns, its stack frame is deleted from the stack, and its space may be used for other procedure calls. Each stack frame contains the private data of the corresponding call, which typically includes the procedure's parameters and internal variables, and the return address.

The call sequence can be implemented by a sequence of ordinary instructions (an approach still used in reduced instruction set computing (RISC) and very long instruction word (VLIW) architectures), but many traditional machines designed since the late 1960s have included special instructions for that purpose.

The call stack is usually implemented as a contiguous area of memory. It is an arbitrary design choice whether the bottom of the stack is the lowest or highest address within this area, so that the stack may grow forwards or backwards in memory; however, many architectures chose the latter.[citation needed]

Some designs, notably some Forth implementations, used two separate stacks, one mainly for control information (like return addresses and loop counters) and the other for data. The former was, or worked like, a call stack and was only indirectly accessible to the programmer through other language constructs while the latter was more directly accessible.

When stack-based procedure calls were first introduced, an important motivation was to save precious memory.[citation needed] With this scheme, the compiler does not have to reserve separate space in memory for the private data (parameters, return address, and local variables) of each procedure. At any moment, the stack contains only the private data of the calls that are currently active (namely, which have been called but haven't returned yet). Because of the ways in which programs were usually assembled from libraries, it was (and still is) not uncommon to find programs that include thousands of subroutines, of which only a handful are active at any given moment.[citation needed] For such programs, the call stack mechanism could save significant amounts of memory. Indeed, the call stack mechanism can be viewed as the earliest and simplest method for automatic memory management.

However, another advantage of the call stack method is that it allows recursive subroutine calls, since each nested call to the same procedure gets a separate instance of its private data.



## How Function Calls Are Handled by the Microprocessor
A function call essentially means that the microprocessor jumps to executing the next instruction belonging to the called function at a nonsequential memory location. After it is done with executing the instructions in the function, it returns to where it left off. To implement this logic, the compiler converts your function call into a CALL instruction for the microprocessor. This instruction is accompanied by the address in memory the next instruction needs to be taken from—this address belongs to your function routine.
When the microprocessor encounters CALL, it saves the position of the instruction to be executed after the function call on the stack and jumps to the memory location contained in the CALL instruction.
As the stack grows upward, the stack pointer always increments as it grows and points to the top of the stack.

The nature of the stack makes it optimal for handling function calls. When a function is called, all local variables are instantiated on the stack—that is, pushed onto the stack. When the function ends, they’re simply popped off it, and the stack pointer returns to where it originally was.


This memory location contains instructions belonging to the function. The microprocessor executes them until it reaches the RET statement (the microprocessor’s code for return programmed by you). The RET statement results in the microprocessor popping that address from the stack stored during the CALL instruction. This address contains the location in the calling function where the execution needs to continue from.

Thus, the microprocessor is back to the caller and continues where it left off.
