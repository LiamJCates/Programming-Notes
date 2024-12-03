Set Up Selenium

detailed instructions can be found here: https://pypi.org/project/selenium/


Supported Python Versions

Python 2.7, 3.4+

Installing

If you have pip on your system, you can simply install or upgrade the Python bindings:

pip install -U selenium

Aside from pip installing the relevant packages, we setup the actual driver for your choice of browser.

Selenium requires a driver to interface with the chosen browser. Firefox, for example, requires geckodriver:
https://github.com/mozilla/geckodriver/releases



Geckodriver Setup

Go to the geckodriver releases page:
https://github.com/mozilla/geckodriver/releases

    For the following steps use an account with sudo privileges or prepend sudo to each command:

    Find the latest version of the driver for your platform and download it.

    For example:
    wget https://github.com/mozilla/geckodriver/releases/download/v0.27.0/geckodriver-v0.27.0-linux64.tar.gz

    Extract the file with:
    tar -xvzf geckodriver*

    Make it executable:
    chmod +x geckodriver

    Then either add the driver to your PATH so other tools can find it:
    export PATH=$PATH:/path-to-extracted-file/

    Or download it to any location and move the file to a location on the PATH
    mv geckodriver /usr/local/bin/


Failure to follow these steps will give you an error selenium.common.exceptions.WebDriverException: Message: ‘geckodriver’ executable needs to be in PATH.
