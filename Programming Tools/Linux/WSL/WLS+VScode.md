WSL Installation


1. enable WSL

You must first enable the "Windows Subsystem for Linux" optional feature before installing any Linux distributions on Windows.

Open PowerShell as Administrator and run:
dism.exe /online /enable-feature /featurename:Microsoft-Windows-Subsystem-Linux /all /norestart


2. Run Windows Update (Potentially restart)


3. Enable Virtual Machine feature

Before installing WSL 2, you must enable the Virtual Machine Platform optional feature.

Open PowerShell as Administrator and run:
dism.exe /online /enable-feature /featurename:VirtualMachinePlatform /all /norestart

4. Download the Linux kernel update package


5. Set WSL 2 as your default version

Open PowerShell as Administrator and run:
wsl --set-default-version 2

6. Open the Microsoft Store and Install a Linux distribution.

9. Ensure that distro is version 2

To get the disto name in PowerShell:
wsl --list --verbose

Using the name of the distro you would like to change:
wsl --set-version <distribution name> 2

7. Launch the distro and create a user account and password for your new Linux distribution.

In PowerShell, set the defualt user to root, run:

<distribution name> config --default-user root


Ensure folder (C:\Users\<username>\AppData) is uncompressed
Navigate to AppData parent directory
right click > Properties > General > Attributes > Advanced > Compress or Encrypt Attributes
Uncheck all boxes


8. Open the Microsoft Store and Install Windows Terminal


Change Ubuntu to the default terminal

Open Windows Terminal, click on the drop-down menu and select “Settings.”
Click on the “Open JSON file” to open the “settings.json” file in the default text or code editor.
Once opened, scroll down till you find the Profiles array
Find "defaultProfile":
We will be changing the value of this property
in the profiles array locate "name": "Ubuntu"

After the last property, add a comma to the last and a "startingDirectory" property

```
"profiles":
    {
        "defaults": {},
        "list":
        [
		...
            {
                "guid": "{2c4de342-38b7-51cf-b940-2309a097f518}",
                "hidden": false,
                "name": "Ubuntu",
                "source": "Windows.Terminal.Wsl",
				"startingDirectory": "//wsl$/Ubuntu/root/"
            },
		...
        ]
    }
```

Now copy the "guid" value and use it to replace the "defaultProfile" value


10. Install VS Code in Windows

11. Install Windows Extensions
Remote - WSL
C/C++
Clang-Format




Open WSL


sudo apt-get update

sudo apt-get upgrade

sudo apt-get install wget ca-certificates

sudo apt-get install build-essential gdb

Verify the location of g++ and gdb
whereis g++
whereis gdb

If either are missing:

sudo apt-get install g++

sudo apt-get install gdb


and run:
code .

Linux VScode Extensions
C/C++
Clang-Format


To fix clang-format in VScode
"The 'clang-format' command is not available. Please check your clang.formatTool user setting and ensure it is installed."

sudo apt install clang-format

potentially:
install "clang for windows"
sudo ln -s /usr/bin/clang-format-3.4 /usr/bin/clang-format
