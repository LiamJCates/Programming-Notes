Local testing server

Local files vs. remote files
Throughout most learning you may  just open your examples directly in a browser — this can be done by double clicking the HTML file, dragging and dropping it into the browser window, or choosing File > Open... and navigating to the HTML file. There are many ways to achieve this.

If the web address path starts with file:// followed by the path to the file on your local hard drive, a local file is being used. In contrast, if you view one of our examples hosted on GitHub (or an example on some other remote server), the web address will start with http:// or https://, to show that the file has been received via HTTP.



The problem with testing local files
Some examples won't run if you open them as local files. This can be due to a variety of reasons, the most likely being:

They feature asynchronous requests. Some browsers (including Chrome) will not run async requests (see Fetching data from the server) if you just run the example from a local file. This is because of security restrictions (for more on web security, read Website security).
They feature a server-side language. Server-side languages (such as PHP or Python) require a special server to interpret the code and deliver the results.





Running a simple local HTTP server

Open your command prompt (Windows)/ terminal (macOS/ Linux). To check Python is installed, enter the following command:

python -V

Or you might have the py command available,
in which case try py -V

This should return a version number. If this is OK, navigate to the directory that your example is inside, using the cd command.

include the directory name to enter it, for example
cd Desktop

If Python version returned above is 3.X
python3 -m http.server
On windows try "python" instead of "python3", or "py -3"
If Python version returned above is 2.X
python -m SimpleHTTPServer

By default, this will run the contents of the directory on a local web server, on port 8000. You can go to this server by going to the URL localhost:8000 in your web browser. Here you'll see the contents of the directory listed — click the HTML file you want to run.

Note:
If you already have something running on port 8000, you can choose another port by running the server command followed by an alternative port number, e.g. python -m http.server 7800 (Python 3.x) or python -m SimpleHTTPServer 7800 (Python 2.x). You can then access your content at localhost:7800.
Running server-side languages locally
Python's SimpleHTTPServer (python 2.0) http.server (python 3.0) module is useful, but it doesn't know how to run code written in languages such as Python, PHP or JavaScript. To handle that you'll need something more — exactly what you'll need depends on the server-side language you are trying to run. Here are a few examples:

To run Python server-side code, you'll need to use a Python web framework. You can find out how to use the Django framework by reading Django Web Framework (Python). Flask is also a good (slightly less heavyweight) alternative to Django. To run this you'll need to install Python/PIP, then install Flask using pip3 install flask. At this point you should be able to run the Python Flask examples using for example python3 python-example.py, then navigating to localhost:5000 in your browser.
To run Node.js (JavaScript) server-side code, you'll need to use raw node or a framework built on top of it. Express is a good choice — see Express Web Framework (Node.js/JavaScript).
To run PHP server-side code, launch PHP's built-in development server:
$ cd path/to/your/php/code
$ php -S localhost:8000
