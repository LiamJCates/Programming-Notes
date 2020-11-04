Regular expression

Regex for IPv4 addresses
Write a regular expression that can be used to extract IPv4 addresses from
a text fi le.
An IPv4 address has the form
nnn.nnn.nnn.nnn
where nnn is a number between 0 and 255.
The simplest pattern that will match an IPv4 address is as follows:
(?:[0-9]{1,3}\.){3}[0-9]{1,3}
If you can be sure that the source fi le contains valid IP addresses,
then this regex would be suffi cient. If you can’t be sure then you
need to be a bit more paranoid. The preceding pattern would correctly match
10.10.1.22
but would incorrectly match
999.999.999.999
Matching a number that is limited to a maximum of 255 is a bit
more complicated. The number 249 is permissible but 259 is not, and
199 is permissible but 299 is not. This leads you to use alternations
in the matching pattern. Here is the regex that matches a number in
the range 0 to 255:
(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)
You need to allow this pattern to be repeated four times, each part
joined by a dot. You should also surround the pattern with wordboundary meta-characters to avoid matching invalid addresses such
as this one:
1234.255.255.2550 # Invalid, we don't want this
So you end up with:
\b(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.){3}
(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\b
