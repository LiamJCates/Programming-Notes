### What is a Command Line
The first instance of CLI built for “interfacing with computers over teletype machines in the 1950s.” It allows a user to interact with the system, taking character-based command inputs.

The CLI is just an interface, the main task is done by a program called command language interpreter. The "shell" is the command language interpreter that shall execute commands read from a command line string, the standard input, or a specified file.

Therefore, when we speak of the command line, we are really referring to the shell. A shell application ensures that the commands to be executed are expressed in the language described in Shell Command Language. The shell takes such commands and passes them to the operating system to carry out.

For most Linux distros, Bash (bourne again shell) is the default command-line interface or shell used to execute commands. The name is an acronym for bourne-again shell, a reference to the fact that bash is an enhanced replacement for sh, the original Unix shell program written by Steve Bourne.


### Accessing The Shell
The shell is accessed using the Terminal – a hardware device used to input and display data. However, the terminal application you see on your Linux systems is an emulator that replicates the jobs of a real-world terminal.

When using a graphical user interface (GUI), we need another program called a terminal emulator to interact with the shell. If we look through our desktop menus, we will probably find one. KDE uses konsole, and GNOME4 uses gnome-terminal, though it’s likely called simply Terminal on your menu.

A number of other terminal emulators are available for Linux, but they all basically do the same thing: give us access to the shell. You will probably develop a preference for one or another terminal emulator based on the number of bells and whistles it has.


### Commands
Linux distributions can leverage an extensive range of commands to accomplish various tasks.


The first piece of text you see when you land on the shell is called the prompt. A shell prompt will appear whenever the shell is ready to accept input.

While it might vary in appearance somewhat depending on the distribution, the typically include

username @ machinename directory $

If the last character of the prompt is a hash mark (#) rather than a
dollar sign, the terminal session has superuser privileges.

This means either we are logged in as the root user or we selected a terminal emulator that provides superuser (administrative) privileges

The Linux CLI is case-sensitive

Running some commands may require you to install additional packages or it’s just that the commands aren’t
meant to work on your system.

The descriptions of these Linux commands are based on their manual pages.

Command syntax to access a man page:

man command_name

For eg: man cat


We can access the command history by using the up arrow, the command history is a list that lets of view previous commands entered into the terminal, in the order they were entered. Most Linux distributions remember the last 1,000 commands by default. Once we have accessed the command history, we can use the down arrow to move forward in the command history.

Using the left and right arrows, we can position the cursor anywhere on
the command line. This makes editing commands easy.

While the shell is all about the keyboard, you can also use a mouse with your
terminal emulator. A mechanism built into the X Window System (the underlying engine that makes the GUI go) supports a quick copy-and-paste technique.
If you highlight some text by holding down the left mouse button and dragging
the mouse over it (or double-clicking a word), it is copied into a buffer maintained by X. Pressing the middle mouse button will cause the text to be pasted
at the cursor location.

Don’t be tempted to use ctrl-C and ctrl-V to perform copy and paste
inside a terminal window. They don’t work. These control codes have different
meanings to the shell and were assigned many years before the release of
Microsoft Windows.



### Command Options and Arguments

Commands are often followed by one or more options that modify their
behavior and, further, by one or more arguments, the items upon which the
command acts. So, most commands look kind of like this:

command -options arguments

Most commands use options, which consist of a single character preceded by a dash, for example, -l. Many commands, however, including
those from the GNU Project, also support long options, consisting of a word
preceded by two dashes. Also, many commands allow multiple short options
to be strung together.



We can end the terminal session by using the exit command or pressin ctrl-D
