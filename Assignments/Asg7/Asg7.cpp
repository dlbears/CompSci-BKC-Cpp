//Dennis Orsini Assignment #7
#include <fstream>
#include <string>
using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

string readOriginalDate(void);
void breakOriginalDate(string, string&, string&, string&);
void printDate3Ways(string, string, string);

int main()
{
  do {
      string date, day, month, year;
      date = readOriginalDate();
      breakOriginalDate(date, day, month, year);
      printDate3Ways(day, month, year);
  } while (!in.eof());
  return 0;
}

string readOriginalDate(void) {
  string value = "";
  in >> value;
  return value;
}
void breakOriginalDate(string date, string& day, string& month, string& year) {
    int dash1 = date.find('/', 0);
    int dash2 = date.find('/', dash1 + 1);
    month = (dash1 == 2) ? date.substr(0, 2) : date.substr(0, 1);
    day = (dash2 == dash1 + 2) ? date.substr(dash1 + 1, 1) : date.substr(dash1 + 1, 2);
    year = date.substr(dash2 + 1, 2);
    
    out << "\n\nThe original date is: " << date << endl;
    out << month << " is the month " << day << " is the day, and " << year << " is the year.\n";
    return;
}
void printDate3Ways(string day, string month, string year) {
    string euro, eng, engMonth, fullYear, yearDate;
    int d = stoi(day);
    int mon = stoi(month);
    int yr = stoi(year);
    
    euro = to_string(d) + "-" + to_string(mon) + "-" + year;
    
    switch (mon) {
        case 1:
            engMonth = "January";
            break;
        case 2:
            engMonth = "February";
            break;
        case 3:
            engMonth = "March";
            break;
        case 4:
            engMonth = "April";
            break;
        case 5:
            engMonth = "May";
            break;
        case 6:
            engMonth = "June";
            break;
        case 7:
            engMonth = "July";
            break;
        case 8:
            engMonth = "August";
            break;
        case 9:
            engMonth = "September";
            break;
        case 10:
            engMonth = "October";
            break;
        case 11:
            engMonth = "November";
            break;
        case 12:
            engMonth = "December";
            break;
    }
    
    if (yr <= 25) {
        fullYear = "20" + year;
    } else {
        fullYear = "19" + year;
    }
    
    eng = engMonth + " " + to_string(d) + ", " + fullYear;
    if (mon < 10 && d < 10) {
        yearDate = "0" + to_string(mon) + "-" + "0" + to_string(d) + "-" + fullYear;
    } else if (mon < 10 || d < 10) {
        yearDate = ((mon < 10) ? ("0" + to_string(mon) + "-" + day) : (month + "-" + "0" + to_string(d))) + "-" + fullYear; 
    } else {
        yearDate = month + "-" + day + "-" + fullYear;
    }
    
    out << euro << " is the European way of writing the date.\n";
    out << eng << " is the American way.\n";
    out << yearDate << " is the full way.\n";
    return;
}

/* input.txt:
01/5/78
5/2/66
01/08/16
12/26/12
8/15/25
10/9/26
12/20/97
4/3/14
07/09/88
03/25/91
1/01/01
*/

/* output.txt


The original date is: 01/5/78
01 is the month 5 is the day, and 78 is the year.
5-1-78 is the European way of writing the date.
January 5, 1978 is the American way.
01-05-1978 is the full way.


The original date is: 5/2/66
5 is the month 2 is the day, and 66 is the year.
2-5-66 is the European way of writing the date.
May 2, 1966 is the American way.
05-02-1966 is the full way.


The original date is: 01/08/16
01 is the month 08 is the day, and 16 is the year.
8-1-16 is the European way of writing the date.
January 8, 2016 is the American way.
01-08-2016 is the full way.


The original date is: 12/26/12
12 is the month 26 is the day, and 12 is the year.
26-12-12 is the European way of writing the date.
December 26, 2012 is the American way.
12-26-2012 is the full way.


The original date is: 8/15/25
8 is the month 15 is the day, and 25 is the year.
15-8-25 is the European way of writing the date.
August 15, 2025 is the American way.
08-15-2025 is the full way.


The original date is: 10/9/26
10 is the month 9 is the day, and 26 is the year.
9-10-26 is the European way of writing the date.
October 9, 1926 is the American way.
10-09-1926 is the full way.


The original date is: 12/20/97
12 is the month 20 is the day, and 97 is the year.
20-12-97 is the European way of writing the date.
December 20, 1997 is the American way.
12-20-1997 is the full way.


The original date is: 4/3/14
4 is the month 3 is the day, and 14 is the year.
3-4-14 is the European way of writing the date.
April 3, 2014 is the American way.
04-03-2014 is the full way.


The original date is: 07/09/88
07 is the month 09 is the day, and 88 is the year.
9-7-88 is the European way of writing the date.
July 9, 1988 is the American way.
07-09-1988 is the full way.


The original date is: 03/25/91
03 is the month 25 is the day, and 91 is the year.
25-3-91 is the European way of writing the date.
March 25, 1991 is the American way.
03-25-1991 is the full way.


The original date is: 1/01/01
1 is the month 01 is the day, and 01 is the year.
1-1-01 is the European way of writing the date.
January 1, 2001 is the American way.
01-01-2001 is the full way.

*/