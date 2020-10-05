Goal

Defining the goal:

    Given a product name and website, we search through product listings on the given website to determine if the given product exists;
    If it does, we navigate to the product detail page, and check if it is available;
    If it is available, add it to our cart;
    Checkout with pre-configured payment information.
    Confirm purchase and stop the script

What is Selenium

Selenium allows us to interact with the HTML elements of a website.

Selenium is an open-source web-based automation tool often used for automated testing of web applications.

Selenium is often paired with Python.  

Python allows the creation of scripts that can test all aspects of a web app, and hence whenever you update your codebase, all you need to do is to run the tests and wait for the results, rather than manually test a feature.

In some sense, the shopping bot we will be building is also a form of automated testing: Shopping sites may very well write up the same script, and run it after every new deployment of their web app.

Prerequisites
Linux command prompt

Python

pip

Firefox:
sudo apt-get install firefox

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


 that actually runs!
