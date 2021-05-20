How Makefiles Are Remade
Sometimes makefiles can be remade from other files, such as RCS or SCCS files. If a makefile
can be remade from other files, you probably want make to get an up-to-date version of the
makefile to read in.
To this end, after reading in all makefiles make will consider each as a goal target and
attempt to update it. If a makefile has a rule which says how to update it (found either
in that very makefile or in another one) or if an implicit rule applies to it (see Chapter 10
[Using Implicit Rules], page 115), it will be updated if necessary. After all makefiles have
been checked, if any have actually been changed, make starts with a clean slate and reads
all the makefiles over again. (It will also attempt to update each of them over again, but
normally this will not change them again, since they are already up to date.) Each restart
will cause the special variable MAKE_RESTARTS to be updated (see Section 6.14 [Special
Variables], page 75).
If you know that one or more of your makefiles cannot be remade and you want to keep
make from performing an implicit rule search on them, perhaps for efficiency reasons, you
can use any normal method of preventing implicit rule look-up to do so. For example,
you can write an explicit rule with the makefile as the target, and an empty recipe (see
Section 5.9 [Using Empty Recipes], page 59).
If the makefiles specify a double-colon rule to remake a file with a recipe but no prerequisites, that file will always be remade (see Section 4.12 [Double-Colon], page 40). In the
case of makefiles, a makefile that has a double-colon rule with a recipe but no prerequisites
will be remade every time make is run, and then again after make starts over and reads
the makefiles in again. This would cause an infinite loop: make would constantly remake
the makefile, and never do anything else. So, to avoid this, make will not attempt to remake makefiles which are specified as targets of a double-colon rule with a recipe but no
prerequisites.
If you do not specify any makefiles to be read with ‘-f’ or ‘--file’ options, make will try
the default makefile names; see Section 3.2 [What Name to Give Your Makefile], page 12.
Unlike makefiles explicitly requested with ‘-f’ or ‘--file’ options, make is not certain that
these makefiles should exist. However, if a default makefile does not exist but can be created
by running make rules, you probably want the rules to be run so that the makefile can be
used.
Therefore, if none of the default makefiles exists, make will try to make each of them in
the same order in which they are searched for (see Section 3.2 [What Name to Give Your
Makefile], page 12) until it succeeds in making one, or it runs out of names to try. Note
that it is not an error if make cannot find or make any makefile; a makefile is not always
necessary.
When you use the ‘-t’ or ‘--touch’ option (see Section 9.3 [Instead of Executing Recipes],
page 105), you would not want to use an out-of-date makefile to decide which targets to
touch. So the ‘-t’ option has no effect on updating makefiles; they are really updated even
if ‘-t’ is specified. Likewise, ‘-q’ (or ‘--question’) and ‘-n’ (or ‘--just-print’) do not
prevent updating of makefiles, because an out-of-date makefile would result in the wrong
output for other targets. Thus, ‘make -f mfile -n foo’ will update mfile, read it in, and
then print the recipe to update foo and its prerequisites without running it. The recipe
printed for foo will be the one specified in the updated contents of mfile.16 GNU make
However, on occasion you might actually wish to prevent updating of even the makefiles.
You can do this by specifying the makefiles as goals in the command line as well as specifying
them as makefiles. When the makefile name is specified explicitly as a goal, the options ‘-t’
and so on do apply to them.
Thus, ‘make -f mfile -n mfile foo’ would read the makefile mfile, print the recipe
needed to update it without actually running it, and then print the recipe needed to update
foo without running that. The recipe for foo will be the one specified by the existing
contents of mfile
