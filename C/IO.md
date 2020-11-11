Character Input and Output

Text input or output, regardless of where it originates or where it goes to,
is dealt with as streams of characters, A text stream is a sequence of characters divided into lines; each line consists of zero or more characters followedby
a newline character.

The standard library provides several functions .for reading or writing one
character at a time, of which getchar and putchar are the simplest.

getchar reads the next input character from a text stream
and returns that as its value.

putchar prints a character each time it is called

char c = getchar();

putchar(c);

File Copying
Given getchar and putchar, you can write a surprising amount of useful code without knowing anything more about input and output.

The simplest example is a program that copies its input to its output one character at a time:

read a character
while (character is not end-of-file indicator)
  output the character just read
  read a character

#include <stdio.h>

main(){
  int c;

  c = getchar();

  while(c != EOF){
    putchar(c);
    c = getchar();
  }
}

The problem is distinguishing the end of the input from valid data. The
solution is that getchar returns a distinctive value when there is no more
input, a value that cannot be confused with any real character. This value is
called EOF,for "end of file." We must declare c to be a type big enough to
hold any value that getchar returns. We can't use char since c must be big
enough to hold EOFin addition to any possible char. Therefore we use into
EOFis an integer defined in <stdio. h>, but the specific numeric value
doesn't matter as long as it is not the same as any char value. By using the
symbolic constant, we are assured that nothing in the program depends on the
specific numeric value.



We can shorten the last example by moving the assignment into the
#include <stdio.h>

main(){
  int c;

  while((c = getchar()) != EOF)
    putchar(c);

}



Character Counting

main(){
  double nc;

  for(nc = 0; getchar() != EOF; ++nc);

  printf("%.0f\n", nc);
}



Line Counting

 #include <stdio.h>

main(){
  int c, nl = 0;

  while((c = getchar()) != EOF)
    if(c == '\n')
      ++nl;
  printf("%d\n", nl);
}




Word Counting


 #include <stdio.h>

 #define IN 1   //Inside a word
 #define OUT 0  //Outside a word

main(){
  int c, nl, nw, nc, state;

  state = OUT;

  nl = nw = nc = 0;
  while((c = getchar()) != EOF){
    ++nc;
    if (c == '\n')
      ++nl;
    if (c == ' ', || c == '\n' || c = = '\t')
      state = OUT;
    else if (state == OUT) {
      state = IN;
      ++nw;
    }
  }
  printf("%d %d %d\n", nl, nw, nc)
}
