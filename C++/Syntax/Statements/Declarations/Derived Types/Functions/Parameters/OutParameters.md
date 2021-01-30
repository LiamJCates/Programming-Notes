## Returning multiple values via out parameters

Parameters that are only used for returning values back to the caller are called out parameters.

Pointers are an effective way to pass memory space that contains relevant data for functions to work on. The memory space shared can also return the result of an operation. When using a pointer with functions, it becomes important to ensure that the called function is only allowed to modify parameters that you want to let it modify, but not others. For example, a function that calculates the area of a circle given radius sent as a pointer should not be allowed to modify the radius. This is where you use the keyword const to control what a function is allowed to modify

This method, while functional, has a few minor downsides. First, the caller must pass in arguments to hold the updated outputs even if it doesn’t intend to use them. More importantly, the syntax is a bit unnatural, with both the input and output parameters being put together in the function call. It’s not obvious from the caller’s end that sin and cos are out parameters and will be changed. This is probably the most dangerous part of this method (as it can lead to mistakes being made). Some programmers and companies feel this is a big enough problem to advise avoiding output parameters altogether, or using pass by address for out parameters instead (which has a clearer syntax indicating whether a parameter is modifiable or not).

it is recommend to avoid out parameters altogether if possible. If you do use them, naming out parameters (and output arguments) with an “out” suffix (or prefix) can help make it clear that the value might be modified.
