Setting put WSL2 to Raspberry Pi Cross Compiler Environment

Install Ubuntu from Windows store

sudo apt update && sudo apt full-upgrade -y

Install Windows Terminal

Configure Windows Terminal

Set Ubuntu as default for Windows terminal
	1. Open Windows Terminal Settings using Crtl+,
	2. This action will open the profiles.json file in the default text or code editor. Here, scroll down till you find the Profiles array.
	3. In there, find the console profile you want to set as the default and copy the GUID value. For example, I want to set Ubuntu as the default terminal. So, I copied the “guid” value of the Ubuntu profile.
	4. Now, scroll all the way to the top, replace the “defaultProfile” value with the copied GUID value.
	5. Save the file and close it.
	6. Relaunch Windows Terminal and you should see the new default console.

Set default directory
	Open WSL and cd to your home directory: 	cd ~
	Then use nano to edit your .bashrc file:	nano .bashrc
	At the bottom of the file add the line:		cd ~
	Finally, restart WSL.



On Windows
Install Xming

start XLaunch
	Display settings:
		Multiple Windows
		Display Number: 0
		Next >
		Start no client
		Next >
		Uncheck Clipboard
		Check No Access Control
		Next >
		Finish

Powershell: > ipconfig
find vEthernet (WSL) IPv4 address



On Ubuntu
sudo apt install x11-apps
export DISPLAY=[IPv4]:0.0
	Where [IPv4] address is the vEthernet address found in previous steps


http://www.heavybaremetal.com/index.php/blog/6-how-to-cross-compile-qt-5-for-raspberry-pi-3

Set Up Raspberry Pi

Download Rpi OS image file
	download the latest Raspberry Pi OS image from the Raspberry Pi website, available here: https://www.raspberrypi.org/downloads/raspberry-pi-os/
	I recommend the medium sized image: “Raspberry Pi OS (32-bit) with desktop”. Direct download link: https://downloads.raspberrypi.org/raspios_armhf_latest

Insert micro SD into host

flash image onto microsd
You will also need to download Balena Etcher to burn the image to the SD card, available here: https://www.balena.io/etcher/

Open Etcher,
Select Flash From File > select the image file

Select Target > select the image file

Select Flash

insert micro sd into raspberry pi
perform setup steps, including deciding on a password

### Change raspberry pi hostname

use ctrl+alt+t shortcut to open terminal
edit etc/hostname to desired hostname
[remote]:~ $ sudo nano etc/hostname

confirm change by running
[remote]:~ $ hostname

For future commands the hostname chosen here will be represented by [hostname]


### Enabling SSH with raspi-config

1. Open the terminal on your Raspberry Pi and run the tool by typing:
[remote]:~ $ sudo raspi-config
A BIOS-looking raspi-config tool loads.
2. Use the arrows on your keyboard to select Interfacing Options
3. Select the P2 SSH option on the list.
4. Select <Yes> on the “Would you like the SSH server to be enabled?” prompt.
5. Hit Enter on the “The SSH server is enabled” confirmation box.
6. Navigate down and select Finish to close the raspi-config.

(optional) also in the raspi-config, change it to boot to the console instead of X, change the GPU memory to 256 MB.


[remote]:~ $ sudo rpi-update

[remote]:~ $ sudo reboot



### Enabling SSH  without password

[local]:~ $ ssh-keygen -t rsa
[local]:~ $ ssh-copy-id remote_user@remote_IP
[local]:~ $ ssh pi@[hostname]
[remote]:~ $ chmod 600 .ssh/authorized_keys
[remote]:~ $ chmod 700 .ssh


### Enable the source repository for apt on the Raspberry Pi

[local]:~ $ ssh pi@[hostname]

[remote]:~ $ sudo nano /etc/apt/sources.list
	delete the # to uncomment the third line
	Quit and save the changes, by pressing control + 'y'

[remote]:~ $ sudo apt update && sudo apt full-upgrade -y && sudo apt autoremove -y
[remote]:~ $ sudo reboot



### Install various Qt and graphics libraries for building Qt code for the Pi

[local]:~ $ssh pi@[hostname]
[remote]:~ $ sudo apt-get update
[remote]:~ $ sudo apt build-dep qt4-x11 -y
[remote]:~ $ sudo apt build-dep libqt5gui5 -y
[remote]:~ $ sudo apt install -y libudev-dev libinput-dev libts-dev libxcb-xinerama0-dev libxcb-xinerama0


### Prepare our target directory

[remote]:~ $ sudo mkdir /usr/local/qt5pi
[remote]:~ $ sudo chown pi:pi /usr/local/qt5pi






### Synchronize the Pi and local Linux
Now that the Pi has been updated, and had those libraries installed, we need to synchronize the local Linux development environment with the Pi.


[local]:~ $ sudo apt update && sudo apt full-upgrade -y && sudo apt autoremove -y
[local]:~ $ sudo apt install git python python3 -y


We will be creating the directory "raspi" in the home directory to hold the development tools and the sysroot that will be created, to mirror files from the Pi.

Get Tools
[local]:~ $ mkdir ~/raspi && cd ~/raspi
[local]:~ $ git clone --progress https://github.com/raspberrypi/tools

Create sysroot
[local]:~ $ mkdir sysroot sysroot/usr sysroot/opt

Using rsync we can properly keep things synchronized in the future as well.

[local]:~ $ rsync -avz pi@[hostname]:/lib sysroot
[local]:~ $ rsync -avz pi@[hostname]:/usr/include sysroot/usr
[local]:~ $ rsync -avz pi@[hostname]:/usr/lib sysroot/usr
[local]:~ $ rsync -avz pi@[hostname]:/opt/vc sysroot/opt

If any permission issues are experienced follow this syntax:
[local]:~ $ sudo rsync -avz --rsync-path="sudo rsync" pi@[hostname]:/usr/lib sysroot/usr



We need to get a script to fix some of the symbolic links to allow us to use the files we just copied across. Luckily there is a great script provided by Kukkimonsuta:

[local]:~ $ wget https://raw.githubusercontent.com/Kukkimonsuta/rpi-buildqt/master/scripts/utils/sysroot-relativelinks.py
[local]:~ $ chmod +x sysroot-relativelinks.py
[local]:~ $ ./sysroot-relativelinks.py sysroot




[on host PC] Get qtbase and configure Qt. The target directory is /usr/local/qt5pi on the Pi, the host tools like qmake will go to ~/raspi/qt5, while make install will target ~/raspi/qt5pi (this is what we will sync to the device). Don't forget to adjust paths if you changed that. For some reason the ~/ in the paths may not work, if this the case just use full paths. You need to change <qt-version> with a proper Qt version (5.12.3 for example). You need to change <rpi-version> with a proper Raspberry Pi version. Use: linux-rasp-pi-g++ for RPi, linux-rasp-pi2-g++ for RPi2 and linux-rasp-pi3-g++ for RPi3. If your system is 64 bit you may also edit device option to: -device-option CROSS_COMPILE=~/raspi/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian-x64/bin/arm-linux-gnueabihf- For higher Qt version (like 5.9.1) you may also need to add -no-use-gold-linker option. You probably also want to add -jn option to make command, where n is a number of cores you like to use for the complication.

[local]:~ $ cd ~/raspi
[local]:~ $ git clone --progress git://code.qt.io/qt/qtbase.git -b <qt-version>
[local]:~ $ git clone --progress https://github.com/LangtonsAnt/Qt5.12.3-RPi3-mkspec.git
[local]:~ $ cp Qt5.12.3-RPi3-mkspec/qmake.conf qtbase/mkspecs/devices/linux-rasp-pi3-g++/
[local]:~ $ cd qtbase
[local]:~ $ ./configure -release -opengl es2 -device <rpi-version> -device-option CROSS_COMPILE=~/raspi/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/bin/arm-linux-gnueabihf- -sysroot ~/raspi/sysroot -opensource -confirm-license -make libs -prefix /usr/local/qt5pi -extprefix ~/raspi/qt5pi -hostprefix ~/raspi/qt5 -v

[local]:~ $ sudo make -j<CPU count>
CPU count can be determined using the lscpu command

[local]:~ $ make install






If you failed, you can clear everything with:

git clean -dfx

[on host PC] Deploy Qt to the device. We simply sync everything from ~/raspi/qt5pi to the prefix we configured above.

cd ..
rsync -avz qt5pi pi@raspberrypi.local:/usr/local

[on host PC] Build an example up to test if everything went well. After proper build, copy an executable to the device.

cd qtbase/examples/opengl/qopenglwidget
~/raspi/qt5/bin/qmake
make

scp qopenglwidget pi@raspberrypi.local:/home/pi

[on RPi] Update the device to let the linker find the Qt libs:

echo /usr/local/qt5pi/lib | sudo tee /etc/ld.so.conf.d/qt5pi.conf
sudo ldconfig

If you're facing issues with running the example, try to use 00-qt5pi.conf instead of qt5pi.conf, to introduce proper order.
[on RPi] Fix the EGL/GLES libraries. The device may have the Mesa version of libEGL and libGLESv2 in /usr/lib/arm-linux-gnueabihf, resulting Qt apps picking these instead of the real thing from /opt/vc/lib. This may be fine for X11 desktop apps not caring about OpenGL performance but is totally useless for windowing system-less, fullscreen embedded apps. You may want to save the originals somewhere, just in case. Make sure you're in "/home/pi" aka "~" when you run these commands:

sudo mv /usr/lib/arm-linux-gnueabihf/libEGL.so.1.0.0 /usr/lib/arm-linux-gnueabihf/libEGL.so.1.0.0_backup
sudo mv /usr/lib/arm-linux-gnueabihf/libGLESv2.so.2.0.0 /usr/lib/arm-linux-gnueabihf/libGLESv2.so.2.0.0_backup
sudo ln -s /opt/vc/lib/libEGL.so /usr/lib/arm-linux-gnueabihf/libEGL.so.1.0.0
sudo ln -s /opt/vc/lib/libGLESv2.so /usr/lib/arm-linux-gnueabihf/libGLESv2.so.2.0.0
sudo ln -s /opt/vc/lib/libbrcmEGL.so /opt/vc/lib/libEGL.so
sudo ln -s /opt/vc/lib/libbrcmGLESv2.so /opt/vc/lib/libGLESv2.so

Please make sure to also add missing symbolic links:

sudo ln -s /opt/vc/lib/libEGL.so /opt/vc/lib/libEGL.so.1
sudo ln -s /opt/vc/lib/libGLESv2.so /opt/vc/lib/libGLESv2.so.2

[on RPi] Run example, that we've built before. At this point it should just work at fullscreen with 60 FPS and mouse, keyboard, and possibly touch support.
[on host PC] Build other Qt modules as desired, the steps are always the same (you need to adjust <qt-module> and <qt-version>):

git clone git://code.qt.io/qt/<qt-module>.git -b <qt-version>
cd <qt-module>

~/raspi/qt5/bin/qmake
make
make install

Then deploy new files by running:

rsync -avz qt5pi pi@raspberrypi.local:/usr/local












## Deviation


### Install libraries and utilities
Now we need to install Qt in the VM. We will be using 5.12.3. This is not the latest release, but I have found later releases do not work correctly.

Before installing Qt, we need to install some libraries and utilities that will be used later.

[local]:~ $ sudo apt install -y libgl1-mesa-dev libglu1-mesa-dev mesa-common-dev libxkbcommon-x11-0
[local]:~ $ sudo apt-get install -y lib32z1
[local]:~ $ sudo apt-get install -y libxcb-xinerama0-dev
[local]:~ $ sudo apt-get install -y flex bison gperf libicu-dev libxslt-dev ruby
[local]:~ $ sudo apt-get install -y libssl-dev libxcursor-dev libxcomposite-dev libxdamage-dev libxrandr-dev libfontconfig1-dev libcap-dev libxtst-dev libpulse-dev libudev-dev libpci-dev libnss3-dev libasound2-dev libxss-dev libegl1-mesa-dev gperf bison


### Download installer for Qt 5.12.3
Now we need to get the Qt installer.

The easiest way is to use commands below, but you can go to their website and get it. Be sure to get the 5.12.3 version.

[local]:~ $ wget http://download.qt.io/official_releases/qt/5.12/5.12.3/qt-opensource-linux-x64-5.12.3.run
[local]:~ $ chmod +x qt-opensource-linux-x64-5.12.3.run
