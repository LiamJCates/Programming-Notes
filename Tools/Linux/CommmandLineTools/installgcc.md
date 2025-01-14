The GNU Compiler Collection (GCC) is a collection of compilers and libraries for C, C++, Objective-C, Fortran, Ada, Go , and D programming languages. A lot of open-source projects, including the Linux kernel and GNU tools, are compiled using GCC.

This article explains how to install GCC on Ubuntu 20.04.
Installing GCC on Ubuntu 20.04

The default Ubuntu repositories contain a meta-package named “build-essential” that includes the GNU compiler collection, GNU debugger, and other development libraries and tools required for compiling software.

To install the Development Tools packages, run the following command as root or user with sudo privileges :

sudo apt update
sudo apt install build-essential

The command installs a lot of packages, including gcc, g++ and make.

You may also want to install the manual pages about using GNU/Linux for development:

sudo apt-get install manpages-dev

Verify that the GCC compiler is successfully installed by running the following command that prints the GCC version:

gcc --version

Ubuntu 20.04 repositories provide GCC version 9.3.0:

gcc (Ubuntu 9.3.0-10ubuntu2) 9.3.0
Copyright (C) 2019 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

That’s it. GCC tools and libraries have been installed on your Ubuntu system.


### Installing Multiple GCC Versions

This section provides instructions about how to install and use multiple versions of GCC on Ubuntu 20.04. The newer versions of the GCC compiler include new functions and optimization improvements.

At the time of writing this article, the default Ubuntu repositories include several GCC versions, from 7.x.x to 10.x.x.

In the following example, we will install the latest three versions of GCC and G++.

Install the desired GCC and G++ versions by typing:

sudo apt install gcc-8 g++-8 gcc-9 g++-9 gcc-10 g++-10

The commands below configures alternative for each version and associate a priority with it. The default version is the one with the highest priority, in our case that is gcc-10.

sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-10 100 --slave /usr/bin/g++ g++ /usr/bin/g++-10 --slave /usr/bin/gcov gcov /usr/bin/gcov-10
sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-9 90 --slave /usr/bin/g++ g++ /usr/bin/g++-9 --slave /usr/bin/gcov gcov /usr/bin/gcov-9
sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-8 80 --slave /usr/bin/g++ g++ /usr/bin/g++-8 --slave /usr/bin/gcov gcov /usr/bin/gcov-8

Later if you want to change the default version use the update-alternatives command:

sudo update-alternatives --config gcc

There are 3 choices for the alternative gcc (providing /usr/bin/gcc).

  Selection    Path            Priority   Status
------------------------------------------------------------
* 0            /usr/bin/gcc-10   100       auto mode
  1            /usr/bin/gcc-10   100       manual mode
  2            /usr/bin/gcc-8    80        manual mode
  3            /usr/bin/gcc-9    90        manual mode

Press <enter> to keep the current choice[*], or type selection number:

You will be presented with a list of all installed GCC versions on your Ubuntu system. Enter the number of the version you want to be used as a default and press Enter.

The command will create symbolic links to the specific versions of GCC and G++.
