project (.pro) files are parsed by a utility called qmake,

qmake generates Makefiles that drive the building of the application.

We define the type of project output we want, what source files are included as well as the dependencies and much more.

Much of this is achieved by simply setting variables as we will do in our project file now.

Add the following to scratchpad.pro:
TEMPLATE = app
QT += qml quick
CONFIG += c++14
SOURCES += main.cpp
RESOURCES += qml.qrc


Let’s run through each of these lines in turn:

TEMPLATE = app
TEMPLATE tells qmake what type of project this is. In our case, it’s an executable application that is represented by app. Other values we are interested in are lib for building library binaries and subdirs for multi project solutions.

Note that we set a variable with the = operator.


QT += qml quick
Qt is a modular framework that allows you to pull in only the parts you need. The QT flag specifies the Qt modules we want to use. The core and gui modules are included by default.

Note that we append additional values to a variable that expects a list with +=.

CONFIG += c++14
CONFIG allows you to add project configuration and compiler options. In this case, we are specifying that we want to make use of C++14 features.

Note that these language feature flags will have no effect if the compiler you are using does not support them.


SOURCES += main.cpp
SOURCES is a list of all the *.cpp source files we want to include in the project. Here, we add our empty main.cpp file, where we will implement our main() function. We don’t have any yet, but when we do, our header files will be specified with a HEADERS variable.


RESOURCES += qml.qrc
RESOURCES is a list of all the resource collection files (*.qrc) included in the project. Resource collection files are used for managing application resources such as images and fonts, but most crucially for us, our QML files.


With the project file updated, save the changes.

Whenever you save a change to your *.pro files, qmake will parse the file. If all is well, you will get a small green bar at the bottom-right of Qt Creator. A red bar indicates some kind of issue, usually a syntax error. Any output from the process will be written out to the General Messages window to help you diagnose and fix the problem.

White space is ignored, so don’t worry about matching up the blank lines exactly.


To get qmake to take a fresh look at your project and generate new Makefiles, right-click on your project in the Projects pane and select Run qmake. It may be slightly tedious, but it’s a good habit to manually run qmake in this way on each of your projects before building and running your application. I’ve found that certain types of code changes can “slip under the radar” and leave you scratching your head when you run your application and they don’t seem to have had any effect. If you ever see your application ignoring the changes you’ve just made, run qmake on each of your projects and try again. The same applies if you get spurious linker errors.
