```cpp
#include <iostream>
#include <ctime>		//<------
using namespace std;

int main( )
{
	//get number of seconds since 01/01/1990
	//we use the time function with the parameter 0 to return the current time
	//assign it to a time_t variable that is part of the ctime header
	time_t ttime = time(0);  //<------- time in seconds

	//example output of a time_t value, in this case called ttime here vv
	//cout << "Number of seconds elapsed since January 1, 1990:" << ttime << endl;

	//use the localtime function to format the time_t value
	//localtime function takes a reference of type time_t
	//we use our time_t value called ttime and the reference operator &
	//returns a value that is a tm struct that we call local_time
	tm *local_time = localtime(&ttime); //<----- formats time into a struct

	//A struct is just another data type, like int or char
	//but instead of one value it has smaller parts that are other values

	//example of outputting the time parts
	cout << "Time: ";

	//We can get the parts out of the tm struct called local_time using ->
	//this is how we get out the hours
	//we use the name of the struct which we have decided to call local_time
	//we use the operator -> which allows us to access values in the struct
	//we use the name of the value in the struct called tm_hour
	cout << local_time->tm_hour << ":";
	cout << local_time->tm_min << ":";
	cout << local_time->tm_sec << endl;
}

/*

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

*/
```
