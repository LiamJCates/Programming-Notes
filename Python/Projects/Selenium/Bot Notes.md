What is Selenium

Selenium allows us to interact with the HTML elements of a website.

Selenium is an open-source web-based automation tool often used for automated testing of web applications.

Selenium is often paired with Python.  

Python allows the creation of scripts that can test all aspects of a web app, and hence whenever you update your codebase, all you need to do is to run the tests and wait for the results, rather than manually test a feature.

In some sense, the shopping bot we will be building is also a form of automated testing: Shopping sites may very well write up the same script, and run it after every new deployment of their web app.

Prerequisites

TODO:
Linux OS
Link to win 10 install

pip
Link to pip tutorial


Set Up Selenium

detailed instructions can be found here: https://pypi.org/project/selenium/

Python language bindings for Selenium WebDriver.

The selenium package is used to automate web browser interaction from Python.
Home: http://www.seleniumhq.org
Docs: selenium package API
Dev:  https://github.com/SeleniumHQ/Selenium
PyPI: https://pypi.org/project/selenium/
IRC:  #selenium channel on freenode

Several browsers/drivers are supported (Firefox, Chrome, Internet Explorer), as well as the Remote protocol.
Supported Python Versions

    Python 2.7, 3.4+

Installing

If you have pip on your system, you can simply install or upgrade the Python bindings:

pip install -U selenium



Aside from pip installing the relevant packages, one extra step is to download and setup the actual driver for your choice of browser. More detailed instructions can be found here. Once you open the link, scroll down to the “Drivers” section, which would walk you through the process. For my example, I will use the Firefox driver.


Goal

For our example, let’s define our goal as follows:

    Given a product name, we search through the listings on https://www.supremenewyork.com/shop and determine if it exists;
    If it does, we navigate to the product detail page, and check if it is available;
    If it is available, add it to our cart;
    Checkout with pre-configured payment information.
    Profit.

To summary: enter a product name, then … profit*!

* Through the mental satisfaction of writing a piece of code that actually runs!
