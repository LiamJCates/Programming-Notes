scanf

The prototype of scanf is given below which is very similar to printf.

int scanf(const char * restrict format, ...);

scanf() is sister of printf(). They work in tandem. As its name says scan function it scans stdin or keyboard for input. Its signature is same as that of printf(). It raeds bytes from keyboard input, interprets them according to format string. It also expects a set of pointer arguments as opposed to values for printf(). The pointers indicate where the interpreted data from the input will be stored. The result is UNDEFINED if there are less number of pointer arguments than the number of conversion specifers in format string. Excess arguments will be evaluated but ignored. The format string can have only white-space characters or an ordinary character (neither ‘%’ nor a white-space character) or a conversion specification.

The full detail of conversion specification can be found at The fscanf function §(iso.7.12.6.2)

which lists fscanf function but conversion specifiers are same for both.

Time for some code. You have already seen many examples of scanf so I will just explain some concepts here. Consider the following program:

```c
#include <stdio.h>

int main()
{
  char str[128] = {0};

  scanf("%s", str);
  printf("You entered:\n%s\n", str);

  return 0;
}
```
and the output is:
```
Hi! My name is Shiv.
You entered:
Hi!
```
It is certainly not the corect output. We had expected to see like: “Hi! My name is Shiv.”. What happend to input string after “Hi!”. Well, in a form given above for scanf() it will stop taking input after white-space for character strings. For numerics it does not matter as it does not match the format. For characters it is character-by-character so no confusion either. So what if you want to have the entire string including white-spaces. Use [^n] as given below:

```c
#include <stdio.h>

int main()
{
  char str[128] = {0};

  scanf("%[^\n]s", str);
  printf("You entered:\n%s\n", str);

  return 0;
}
```

and the output is:
```
Hi! My name is Shiv.
You entered:
Hi! My name is Shiv.
```
What if you want to filter a string based on certain patterns. For example, a charcater string does not contain more that a single space, English alphabets, period and digits. To scan such a string you can define a pttern as program given below shows:

```c
#include <stdio.h>

int main()
{
  char c[100]={0};

  scanf("%[ A-Za-z0-9!.]", c);
  printf("%s\n", c);

  return 0;
}
```

and the output is:
```
Hi! My name is Shiv! My phone no. is 1234. %^$&*
Hi! My name is Shiv! My phone no. is 1234.
```

There is also a major problem associated with input and that comes when you have characters involved. Consider the following program:

```c
#include <stdio.h>

int main()
{
  int   i = 0;
  float f = 0.0;
  char  c1 = '\0';
  char  c2 = '\0';
  char  c3 = '\0';

  printf("Enter an integer, a float and three character one by one:\n");

  scanf("%d", &i);
  scanf("%f", &f);
  scanf("%c", &c1);
  scanf("%c", &c2);
  scanf("%c", &c3);

  printf("You entered\n");
  printf("%d\n", i);
  printf("%f\n", f);
  printf("%c\n", c1);
  printf("%c\n", c2);
  printf("%c\n", c3);

  return 0;
}
```

and the output is:

```
2
3.4
s
You entered
2
3.400000


s
```
What is happening here is that newline entered by our RET key is getting assigned to c1 and c3. That is why the program accepted only second character. The enter after float f; was assigned to c1 and the character entered to c2 and then the RET newline to c3. There is a very simple way to recover from this:

```c
#include <stdio.h>

int main()
{
  int   i = 0;
  float f = 0.0;
  char  c1 = '\0';
  char  c2 = '\0';
  char  c3 = '\0';

  printf("Enter an integer, a float and three character one by one:\n");
  scanf("%d", &i);
  scanf("%f", &f);
  scanf(" %c", &c1);
  scanf(" %c", &c2);
  scanf(" %c", &c3);

  printf("%d\n", i);
  printf("%f\n", f);
  printf("%c\n", c1);
  printf("%c\n", c2);
  printf("%c\n", c3);

  return 0;
}
```
The whitespace character shown will eat up all the white-space given after the previous input.
