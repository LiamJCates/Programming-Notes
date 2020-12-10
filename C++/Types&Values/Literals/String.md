## String Literals
String Literals
Declare string literals by enclosing text in quotation marks (""). Like character literals, string literals support Unicode: just prepend the literal with
the appropriate prefix, such as L. The following example assigns string literals
to the arrays english and chinese:
char english[] = "A book holds a house of gold.";
char16_t chinese[] = u"\u4e66\u4e2d\u81ea\u6709\u9ec4\u91d1\u5c4b";

Printing Unicode to the console is surprisingly complicated. Typically, you need to ensure that the correct code page is selected. If you need to embed Unicode characters into a string literal, look at
wprintf in the <cwchar> header.

Consecutive string literals get concatenated together, and any intervening whitespaces or newlines get ignored. So, you can place string literals on multiple lines in your source, and the compiler will treat them as one:
#include <cstdio>
int main() {
char house[] = "a "
"house "
"of " "gold.";
printf("A book holds %s\n ", house);
}

Usually, such constructions are useful for readability only when you
have a long string literal that would span multiple lines in your source code.
