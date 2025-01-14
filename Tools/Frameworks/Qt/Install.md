Start at the Qt website:

https:/​/​www.​qt.​io


look for and download Qt Open Source for Desktop & Mobile:
1. From the top-level menu, select Products and then IDE & Tools
2. Click on Start for Free
3. Select Desktop & Mobile Applications
4. Click on Get your open source package

The site will detect your operating system and suggest a recommended download. In all cases, download and launch the installer.

If you continue to use Qt beyond these personal projects, ensure that you
read the licensing information available on the Qt website (https:/​/​www.
qt.​io/​licensing/​). Upgrade to the commercial Qt license if the scope of
your projects requires it or if you want access to the official Qt support
and the benefits of a close strategic relationship with the Qt company.

After the initial welcome dialog, the first thing you are presented with is the option to sign up for or log in with a Qt account. Feel free to create one if you wish, but for now we’ll go ahead and Skip.

You are then asked to select which components you wish to install.
Your first decision is which version(s) of the Qt framework you want. You can have multiple versions installed side by side. Let's select the latest and greatest (Qt 8.10 at the time of writing) and leave all the older versions unchecked.


Next, expand the selected version and you will see a secondary list of options.

All the options where the description reads “Qt x.x.x Prebuilt Components for ...” are what is known as a Kit. A Kit is essentially a toolset enabling you to build your application with a specific compiler/linker and run it on a particular target architecture.

Each kit comes with Qt framework binaries compiled specifically for that particular toolset as well as necessary supporting files. Note that kits do not come with the referenced compiler; you will need to install those ahead of time.

One exception to this on Windows is MinGW (which includes GCC for Windows), which you can optionally install via the Tools component list at the bottom.

On Windows, that is exactly what we’ll do, so we select the MinGW 5.3.0 32 bit kit and also the MinGW 5.3.0 development environment from the Tools section. On my (64-bit) machine, I already have Microsoft Visual Studio 2017 installed, so we will also select the MSVC 2017 64-bit kit to help demonstrate some techniques later in the book. On Linux, we select GCC 64-bit, while on Mac OS, we select macOS 64-bit (which uses the Clang compiler). Note that on Mac OS, you must have XCode installed, and it's a good idea to launch XCode at least once to give it an opportunity to complete its initialization and configuration.

Feel free to press pause, go and install whatever other IDEs or compilers you want to use, and then come back and pick the kits to match. It doesn’t matter too much which you go for — the techniques explained throughout the book are applicable regardless of the kit, you may just get slightly different results.

Note that the available kits you are presented with will differ depending on your operating system and chipset; for example, if you are on a 32 bit machine, you won’t be offered any 64 bit kits.

Regardless of kits and APIs, you will note in the Tools section that Qt Creator is installed by default, this is an IDE:



Using Qt with Visual Studio Code
https://www.kdab.com/using-visual-studio-code-for-writing-qt-applications/
https://www.kdab.com/using-visual-studio-code-for-qt-apps-pt-1/
https://www.kdab.com/using-visual-studio-code-for-qt-apps-pt-2/
