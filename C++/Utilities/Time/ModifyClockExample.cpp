/*
For students that have implemented their own clock and time adjustment:
  #include<ctime>
    //Start of menu loop

    time_t start_t, end_t;
    time(&start_t);

    //...menu prompt
    //... user input
    //... user selected time operation

    time(&end_t);
    int diff_t = difftime(end_t, start_t);

    while(diff_t--)
      addSecond();
*/






#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

//Global varaible to represent the components of 24 hour time 0:00:00 - 23:59:59
int hours = 0;
int minutes = 0;
int seconds = 0;

void displayTime(int hrs, int min, int sec)
{
    cout << std::setfill('0')
         << std::setw(2) << hrs << ":"
         << std::setw(2) << min << ":"
         << std::setw(2) << sec;
}

void display12HourTime(int hrs, int min, int sec)
{
    cout << "*       ";
    cout << (hrs > 12 ? "PM " : "AM ");
    displayTime(hrs%12, min, sec);
    cout << "       *";
}


void display24HourTime(int hrs, int min, int sec)
{
    cout << "*        ";
    displayTime(hrs, min, sec);
    cout << "         *" << endl;
}


void timeOutput()
{
    time_t ttime = time(0);
    tm *time = localtime(&ttime);

    int totalSeconds = time->tm_sec + seconds;
    int sec = totalSeconds % 60;
    int carrySeconds = totalSeconds / 60;

    int totalMinutes = time->tm_min + minutes + carrySeconds;
    int min = totalMinutes % 60;
    int carryMinutes = totalMinutes / 60;

    int totalHours = time->tm_hour + hours + carryMinutes;
    int hrs = totalHours % 24;

    cout << "***************************    ***************************" << endl;
    cout << "*      12-Hour Clock      *    *      24-Hour Clock      *" << endl;
    display12HourTime(hrs, min, sec);
    cout << "    ";
    display24HourTime(hrs, min, sec);
    cout << "***************************    ***************************" << endl
    << endl;
}

int displayMenu()
{
    int option;
    cout << "\t\t***************************" << endl;
    cout << "\t\t* 1-Add One Hour          *" << endl;
    cout << "\t\t* 2-Add One Minute        *" << endl;
    cout << "\t\t* 3-Add One Second        *" << endl;
    cout << "\t\t* 4-Exit Program          *" << endl;
    cout << "\t\t***************************" << endl << endl;
    cout << "Please select one of the above options: ";
    cin >> option;

    //Validate and execute user selected operation and adjust increment
    switch (option)
    {
    case 1: hours++;    break;
    case 2: minutes++;  break;
    case 3: seconds++;  break;
    case 4: break;
    default:
        cout << option << " is not a valid selection" << endl;
    }
    return option;
}

int main()
{
    do
    {
        //clear the screen
        system("clear");
        //display 12 and 24 hour times
        timeOutput();
    //Display the menu and check for exit case
    } while (displayMenu() != 4);
}
