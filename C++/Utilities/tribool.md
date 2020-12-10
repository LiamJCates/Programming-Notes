tribool
The tribool is a bool-like type that supports three states rather than two:
true, false, and indeterminate. Boost offers boost::logic::tribool in the
<boost/logic/tribool.hpp> header.

#include <boost/logic/tribool.hpp>
using boost::logic::indeterminate;

boost::logic::tribool t = true, f = false, i = indeterminate;

The tribool class implicitly converts to bool. If a tribool is true, it converts to true; otherwise, it converts to false. The tribool class also supports
operator!, which returns true if tribool is false; otherwise, it returns false.
Finally, indeterminate supports operator(), which takes a single tribool argument and returns true if that argument is indeterminate; otherwise, it returns false.
indeterminate(i); //true

Boolean Operations
The tribool class supports all the Boolean operators. Whenever a tribool
expression doesn’t involve an indeterminate value, the result is the same as the equivalent Boolean expression. Whenever an indeterminate is involved, the
result can be indeterminate

When to Use tribool
Aside from describing the vital status of Schrödinger’s cat, you can use
tribool in settings in which operations can take a long time. In such settings, a tribool could describe whether the operation was successful. An
indeterminate value could model that the operation is still pending.

A Partial List of Supported Operations
| Operation | Notes |
| tribool{} \n tribool{ false } | Constructs a tribool with value false. |
| tribool{ true } | Constructs a tribool with value true. |
| tribool{ indeterminate } | Constructs a tribool with value indeterminate. |
| tb.safe_bool() | Evaluates to true if tb is true, else false. |
| indeterminate(tb) | Evaluates to true if tb is indeterminate, else false. |
| !tb | Evaluates to true if tb is false, else false. |
| tb1 && tb2 | Evaluates to true if tb1 and tb2 are true; evaluates to false if tb1 or tb2 are false; otherwise, indeterminate. |
| tb1 || tb2 | Evaluates to true if tb1 or tb2 are true; evaluates to false if tb1 and tb2 are false; otherwise, indeterminate. |
| bool{ tb } | Evaluates to true if tb is true, else false.|
