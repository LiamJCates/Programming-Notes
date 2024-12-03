The manipulation of date and time in C++. C++ inherits date & time functions and structures from C language.

We need to include <ctime> header into our C++ program in order to manipulate date and time.


### The “tm” Structure

The header <ctime> has four time-related types: tm, clock_t, time_t, and size_t.

Each of the types, clock_t, size_t, and time_t represent the system time and date as an integer. The structure tm holds the date and time in the form of a C structure.

The “tm” structure is defined as follows:

```cpp
struct tm
{
	int tm_sec; // seconds of minutes from 0 to 61
  int tm_min; // minutes of hour from 0 to 59
  int tm_hour; // hours of day from 0 to 24
  int tm_mday; // day of month from 1 to 31
  int tm_mon; // month of year from 0 to 11
  int tm_year; // year since 1900
  int tm_wday; // days since sunday
  int tm_yday; // days since January 1st
  int tm_isdst; // hours of daylight savings time
};
```

### Date And Time Functions

The following table shows some of the functions that we use for date and time in C and C++.


| Function Prototype | Description |
|--------------------|-------------|
| char *ctime(const time_t *time) | Returns a pointer to a string in the form weekday month date hours:minutes:seconds year. |
| struct tm *gmtime(const time_t *time) | Returns pointer to the tm structure in the Coordinated Universal Time (UTC) format which is essentially Greenwich Mean Time (GMT). |
| struct tm *localtime(const time_t *time) | Returns pointer to tm structure representing local time. |
| size_t strftime() | Used to format date and time in specific format. |
| char * asctime ( const struct tm * time ) | Converts time object of type tm to string and returns a pointer to this string. |
| time_t time(time_t *time) | Returns current time. |
| clock_t clock(void) | Returns an approximate value for the amount of time the calling program has been running. A value of .1 is returned if the time is not available. |
| double difftime ( time_t time2, time_t time1 ) | Returns difference between two time objects time1 and time2. |
| time_t mktime(struct tm *time) | Converts tm structure to time_t format or calendar equivalent. |


Programming Examples

The following code Example calculates the current time in local and GMT format and displays it.

```cpp
#include <iostream>
#include <ctime>
using namespace std;

int main( )
{
	time_t ttime = time(0);

	char* dt = ctime(&ttime);
	cout << "The current local date and time is: " << dt << endl;

	tm *gmt_time = gmtime(&ttime);
	dt = asctime(gmt_time);
	cout << "The current UTC date and time is:"<< dt << endl;
}
```

Output:

The current local date and time is: Fri Mar 22 03:51:20 2019

The current UTC date and time is: Fri Mar 22 03:51:20 2019

The above example retrieves the current time using the time function and then converts it into a string format to display it. Similarly, it also retrieves GMT using gmtime function and converts it to the string format using “asctime” function. Later it displays the GMT time to the user.

The next example will display the various members of the “tm” structure.

The code example is as shown below:

```cpp
#include <iostream>
#include <ctime>
using namespace std;

int main( )
{
   time_t ttime = time(0);
   cout << "Number of seconds elapsed since January 1, 1990:" << ttime << endl;
   tm *local_time = localtime(&ttime);

   cout << "Year: "<< 1900 + local_time->tm_year << endl;
   cout << "Month: "<< 1 + local_time->tm_mon<< endl;
   cout << "Day: "<< local_time->tm_mday << endl;
   cout << "Time: "<< 1 + local_time->tm_hour << ":";
   cout << 1 + local_time->tm_min << ":";
   cout << 1 + local_time->tm_sec << endl;
}
```

Output:

Number of seconds elapsed since January 1, 1990:1553227670
Year: 2019
Month: 3
Day: 22
Time: 4:8:51

As shown in the output above, we retrieved the local time, and then display the year, month, day and time in the form “hour: minutes: seconds”.
