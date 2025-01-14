Download:
https://www.python.org/downloads/




Before continuing with this tutorial, make sure you are logged in as a user with sudo privileges

Installing pip for Python 3

Ubuntu 18.04 ships with Python 3, as the default Python installation. Complete the following steps to install pip (pip3) for Python 3:

    Start by updating the package list using the following command:

    sudo apt update

    Use the following command to install pip for Python 3:

    sudo apt install python3-pip

    The command above will also install all the dependencies required for building Python modules.

    Once the installation is complete, verify the installation by checking the pip version:
    pip3 --version


    The version number may vary, but it will look something like this:
    pip 9.0.1 from /usr/lib/python3/dist-packages (python 3.6)







Executing Code

The most basic way to execute Python code is line by line within the Python interpreter. 

The Python interpreter can be started by installing the Python language and typing python at the command prompt (look for the Terminal on Mac OS X and Unix/Linux systems, or the Command Prompt application in Windows):

'''Python
$ python
Python 3.5.1 |Continuum Analytics, Inc.| (default, Dec 7...
Type "help", "copyright", "credits" or "license" for more...
>>>
'''

The Python interpreter

With the interpreter running, you can begin to type and execute
code snippets. Here we’ll use the interpreter as a simple calculator,
performing calculations and assigning values to variables:

'''Python
>>> 1 + 1
2
>>> x = 5
>>> x * 3
15
'''

The interpreter makes it very convenient to try out small snippets of
Python code and to experiment with short sequences of operations.

Self-contained Python scripts

Running Python snippets line by line is useful in some cases, but for
more complicated programs it is more convenient to save code to
file, and execute it all at once. By convention, Python scripts are
saved in files with a .py extension. For example, let’s create a script
called test.py that contains the following:

'''Python
# file: test.py
print("Running test.py")
x = 5
print("Result is", 3 * x)
'''

To run this file, we make sure it is in the current directory and type
python filename at the command prompt:

'''Python
$ python test.py
Running test.py
Result is 15
'''

For more complicated programs, creating self-contained scripts like
this one is a must.



Python IDE
https://www.jetbrains.com/pycharm/data-science/

https://www.jetbrains.com/help/pycharm/quick-start-guide.html