## Array Parameters

C++ arrays are always passed by reference (even if not declare to be reference parameters). It is said they "decay" into pointers when passed to a function. For example:

    void f(int A[]) {
        A[0] = 5;
    }

    int main() {
        int B[10];
        B[0] = 2;
        f(B);
        cout << B[0] << endl;  // the output is 5
    }

Although f's parameter looks like it is passed by value (there is no &), since it is an array it is actually passed by reference, so the assignment to A[0] is really assigning to B[0], and the program prints 5 (not 2).

As array parameters decay, some special consideration must be given:
	either the [] or * operator are used to dereference the array and provide element access in the caller's environment
	To perform actions that traverse the array, the length must be given as a separate parameter
	If you want to pass an array by value, you should use a vector, not a regular C++ array.
