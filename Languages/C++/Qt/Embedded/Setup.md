Technical requirements
The following hardware will be needed in order to derive the most from this chapter and
the rest of this book:
A target device (Raspberry Pi 3B+) with supporting hardware.

A host development PC running Ubuntu 16.04 or higher. This can be running
directly on a PC or in a VM with network access. Other Linux distributions may
work, but these documents are written for Ubuntu. (I am running Ubuntu 18.10 on
dedicated hardware.) You will need the following access rights for your account
on the host:
	Administrative (or root) privileges for installing software on your
	development PC are needed.

	A web browser (Chrome is recommended) is required.
	Internet access is necessary.
	
	The following tools should be configured and working on the host:
		ssh
		rsync
		scp
		tar
		xz
		bzip2
		g++
		patch

	The Host PC must be connected to a network that can also connect
	to the target device.

	The Host PC must be able to read/write micro SD cards. You will
	want a fast SD card reader.

Additionally, this book assumes that you have at least a basic grasp of the following technologies:
Installation of distribution provided software packages on your development PC
A basic understanding of how to use Linux, including how to make files
executable, run a program, edit a text file without a GUI, and safely reboot it
C++11 programming and debugging
