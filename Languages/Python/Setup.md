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
