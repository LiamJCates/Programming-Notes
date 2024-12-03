_Bool counts as an integral type and is used to represent boolean values. Here is stdbool.h for your quick reference.

/*===---- stdbool.h - Standard header for booleans -------------------------===
 *
 * Copyright (c) 2008 Eli Friedman
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 *===-----------------------------------------------------------------------===
 */

#ifndef __STDBOOL_H
#define __STDBOOL_H

/* Don't define bool, true, and false in C++, except as a GNU extension. */
#ifndef __cplusplus
#define bool _Bool
#define true 1
#define false 0
#elif defined(__GNUC__) && !defined(__STRICT_ANSI__)
/* Define _Bool, bool, false, true as a GNU extension. */
#define _Bool bool
#define bool  bool
#define false false
#define true  true
#endif

#define __bool_true_false_are_defined 1

#endif /* __STDBOOL_H */

As you can see from the definition true is 1 and false is 0. Any non-zero value is considered to be true. Here is a program demonstrating that.

// Boolean Program
// Description: Demo of boolean data typec

#include <stdio.h>
#include <stdbool.h>

int main()
{
  bool bcpp      = 4;
  _Bool bc       = 5;
  bool True      = true;
  _Bool False    = false;
  bool bFalseCPP = -4;
  _Bool bFalseC  = -7;

  printf("%d %d %d %d %d %d\n", bcpp, bc, True, False, bFalseCPP, bFalseC);

  getchar();

  return 0;
}

and the output is:

1 1 1 0 1 1

Note that true and false are keywords while True and False are identifiers.

Though I wanted to avoid dealing with this but since I am including header files verbatim I must give an explanation of #define pre-processor macro at least. I will touch it very little as it will be covered in more detail later. #define has two parameters though not as function arguments. Whenever the first part is encountered second will be replaced. Consider this example:

// Boolean Program
// Description: Demo of boolean data type

#define MAX 7
int main()
{
  MAX;
  return 0;
}

Just do $gcc -E define.c to see the magic. Note that #define parameters are not type safe. Compiler will just paste the contents. Notice how MAX is replaced by 7.
