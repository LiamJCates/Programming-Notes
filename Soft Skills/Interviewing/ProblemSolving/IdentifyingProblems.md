Consider four common problem areas for any given function:

1. Input
Check that the data comes into the function properly. Make sure you aren’t accessing a variable that you don’t have, you aren’t reading something as an int that should be a long, and you have all the values you need to perform the task.

2. Functionality
Check that each line of the function works correctly. The function is intended to perform a task. Verify that the task is executed correctly at each line and that the desired result is produced at the end.

3. Output
Check that the data comes out of the function correctly. The return value should be what you expect. In addition, if the function is expected to update any caller variables, make sure this occurs.

4. Error Conditions
Check for common error conditions. Error conditions vary depending on the specifics of a problem. They tend to involve unusual argument values. For instance, functions that operate on data structures may have trouble with empty or nearly empty data structures; functions that take a pointer as an argument may fail if passed a null pointer. Make sure that error conditions from operations that can fail, such as memory allocation and I/O, are handled appropriately.
