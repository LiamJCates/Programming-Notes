<stdlib> Header

We also have another header <stdlib> that includes various useful library functions that are used extensively in C++ programming.

We have listed some of the popular functions in <stdlib> below:
|Function |	Description |
|---------|-------------|
| abs(x) | Returns absolute value of an integral argument x |
| atof(const char* str) | Converts string to double; returns double |
| atoi(const char* str) | Converts string to int; returns an int |
| atol(const char* str) | Converts string to long int; returns a long int |
| atoll(const char* str) | Converts string to long long int; returns a long long int |
| strtod | Converts string to double |
| strtol | Converts string to long int |
| strtoul | Converts string to unsigned long integer |
| strtof | Converts string to float |
| strtold | Converts string to long double |
| strtoull | Converts string to unsigned long long integer |
| strtoll | Converts string to long long integer |
| srand(int seed) | This is a pseudo-random generator that is initialized to argument ‘seed’ |
| qsort | Sorts elements of the array in ascending order(internally uses quick sort method) |
| abort | Aborts the process resulting in abnormal program termination |
| atexit | Has function passed as an argument which is executed resulting in normal program termination. |
| malloc(size_t size) | Used to allocate memory specified by size and return a pointer to it |
| calloc ( size_t num, size_t size) | Allocates memory of (num*size) bytes with all bits initialized to zero |
| free(void* ptr) | Deallocates memory block allocated by malloc, calloc or realloc function call. |
| realloc ( void* ptr, size_t size ) | Resizes the memory block pointed to by ptr that was initially allocated using malloc or calloc function call. |
| quick_exit | Normal termination of the process after returning control to the host environment. |
| system | Invokes command processor to execute system command passed as an argument |
| getenv | Retrieves the value of environment string passed as an argument to the function |
| wctomb | Convert the wide character to a multibyte sequence |
| wcstombs | Convert wide character string to multibyte string |
|
