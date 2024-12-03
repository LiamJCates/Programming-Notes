### include

The statement #include is a pre-processor directive.

It will look for whatever is contained in angular brackets in the INCLUDEPATH of compiler. For now you can assume that /usr/include is in include path of compiler. Basically what it does is that it looks for a file names stdio.h in the INCLUDEPATH. If that is found the content of that file is pasted here in our program.If you really want to see what happens then you can type $gcc -E nothing.c. You will see lots of text scrolling on your screen. The -E switch tells gcc that just preprocess the file, do not compile it, and send the resulting output to standard output, which happens to be your monitor in this case.
