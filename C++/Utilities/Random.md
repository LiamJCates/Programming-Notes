A little trick we used
for generating a random number and putting it
into the middle of the string. First, we had to
add two additional include lines:
#include <stdlib.h>
#include <sstream>
The first line provides access to the rand()
function. The second line provides access to
some of the special features we’re about to talk
about — specifically, the ostringstream
type. Here are the three lines that perform the
magic:
int randomnumber = rand();
ostringstream converter;
converter << randomnumber;
The first of these creates a random number
by calling a function named rand(). You get
back from this function an integer, which is
random. The next one creates a variable of the
type called ostringstream, which is a type
that’s handy for converting numbers to strings.
A variable of this type has features similar to
that of a console. You can use the insertion
operator (<<), except that instead of going to
the console, anything you write goes into the
string itself. But this isn’t just any old string —
it’s a special string of type ostringstream
(which comes from the words output, string,
and stream; usually, things that allow the
insertion operator << or the extraction operator >> to perform input and output are called
streams). After we do this, we can add the
resulting string onto our string variable named
code. To do that, we use the line
code->append(converter.str());
The part inside parentheses — converter.
str() — returns an actual string version
of the converter variable. And that, we can
easily append to the code variable by using
the append function. It’s kind of tricky, but it
works quite nicely
