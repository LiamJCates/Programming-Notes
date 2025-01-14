a Unix-like operating system such as Linux organizes its files
in what is called a hierarchical directory structure. This means they are organized in a tree-like pattern of directories (sometimes called folders in other
systems), which may contain files and other directories. The first directory
in the file system is called the root directory.

Note that unlike Windows, which has a separate file system tree for
each storage device, Unix-like systems such as Linux always have a single file
system tree, regardless of how many drives or storage devices are attached to
the computer. Storage devices are attached (or more correctly, mounted) at
various points on the tree according to the whims of the system administrator,
the person (or people) responsible for the maintenance of the system.

Imagine that the file system is a maze shaped like an upside-down
tree and we are able to stand in the middle of it. At any given time, we are
inside a single directory, and we can see the files contained in the directory
and the pathway to the directory above us (called the parent directory) and
any subdirectories (called the child directory) below us. The directory we are standing in is called the
current working directory. To display the current working directory, we use the
pwd (print working directory) command.

When we first log in to our system (or start a terminal emulator session),
our current working directory is set to our home directory. Each user account is
given its own home directory, and it is the only place a regular user is allowed
to write files.

To list the files and directories in the current working directory, we use the
ls command.

To change the current working directory we use the cd command. cd followed by the pathname of the sedired working directory.

A pathname is the route we take along
the branches of the tree to get to the directory we want. We can specify
pathnames in one of two different ways: as absolute pathnames or as relative
pathnames.

An absolute pathname begins with the root directory and follows the tree
branch by branch until the path to the desired directory or file is completed.

Where an absolute pathname starts from the root directory and leads to its
destination, a relative pathname starts from the working directory. To do
this, it uses a couple of special notations to represent relative positions in
the file system tree. These special notations are . (dot) and .. (dot dot).
The . notation refers to the working directory, and the .. notation refers
to the working directory’s parent directory.


On Linux systems, files are named in a manner similar to that of other systems
such as Windows, but there are some important differences.

Filenames that begin with a period character are hidden. This only means that ls will not list them unless you say ls -a. When your account was created, several hidden files were placed in your home directory to configure things for your account. In addition, some applications place their configuration and settings files in your home directory as hidden files.

Filenames and commands in Linux, like Unix, are case sensitive. The filenames File1 and file1 refer to different files.

Though Linux supports long filenames that may contain embedded spaces
and punctuation characters, limit the punctuation characters in the names
of files you create to period, dash, and underscore. Most important, do not
embed spaces in filenames. If you want to represent spaces between words
in a filename, use underscore characters. You will thank yourself later.

Linux has no concept of a “file extension” like some other operating systems. You may name files any way you like. The contents or purpose of a
file is determined by other means. Although Unix-like operating systems
don’t use file extensions to determine the contents/purpose of files, many
application programs do.

cd
Changes the working directory to your home directory.

cd -
Changes the working directory to the previous working directory.

cd
~user_name Changes the working directory to the home directory of user_name.
For example, typing cd ~bob will change the directory to the home
directory of user “bob.”

ls
List directory contents

file
Determine file type

less
View file contents

ls
Can be used without a directory to list the contents of the current working directory. ls can be followed by an absolute or relative pathname to list the contents of the specified directory. Ls can be followed by multiple directories to list their contents in a single output, grouped by directory.


Common ls Options

| Option | Long option | Description |
+--------+-------------+-------------+
| -a | --all | List all files, even those with names that begin with a period, which are normally not listed (that is, hidden). |
| -A | --almost-all | Like the -a option except it does not list . (current directory) and .. (parent directory). |
| -d | --directory | Ordinarily, if a directory is specified, ls will list the contents of the directory, not the directory itself. Use this option in conjunction with the -l option to see details about the directory rather than its contents. |
| -F | --classify | This option will append an indicator character to the end of each listed name. For example, it will append a forward slash (/) if the name is a directory. |
| -h | --human-readable | In long format listings, display file sizes in humanreadable format rather than in bytes. |
| -l | Display results in long format. |
| -r | --reverse | Display the results in reverse order. Normally, ls displays its results in ascending alphabetical order. |
| -S | | Sort results by file size. |
| -t | | Sort by modification time. |


Here is an example of a file from the output of ls -l

-rw-r--r-- 1 root root 32059 2017-04-03 11:05 oo-cd-cover.odf

-rw-r--r--
Access rights to the file. The first character indicates the type of file. Among the different types, a leading dash means a regular file, while a d indicates a directory.
The next three characters are the access rights for the file’s owner, the next three are for members of the file’s group, and the final three are for everyone else.

1
File’s number of hard links. See "Symbolic Links" and "Hard Links".

root
The username of the file’s owner.

root
The name of the group that owns the file.

32059
Size of the file in bytes.

2017-04-03 11:05
Date and time of the file’s last modification.

oo-cd-cover.odf
Name of the file.
