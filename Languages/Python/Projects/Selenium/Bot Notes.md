Goal

Defining the goal:

    Given a product name and website, we search through product listings on the given website to determine if the given product exists;
    If it does, we navigate to the product detail page, and check if it is available;
    If it is available, add it to our cart;
    Checkout with pre-configured payment information.
    Confirm purchase and stop the script


Prerequisites
    Linux command prompt
    Using WSL on Win10

    Python

    pip

    Firefox:
    sudo apt-get install firefox


Scripting Language
Python allows the creation of scripts that can test all aspects of a web app, and hence whenever you update your codebase, all you need to do is to run the tests and wait for the results, rather than manually test a feature.

In some sense, the shopping bot we will be building is also a form of automated testing: Shopping sites may very well write up the same script, and run it after every new deployment of their web app.

Selenium

The Selenium package is used to automate web browser interaction from Python.

Selenium allows us to interact with the HTML elements of a website.

Selenium is an open-source web-based automation tool often used for automated testing of web applications.
