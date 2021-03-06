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
    string euro, euEnDay, euroMonth, eng, engMonth, fullDay, fullMonth, fullYear, yearDate;
    string monthsArr[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int d = (day.length() == 1) ? (day[0] - '0') : ((day[0] - '0') * 10) + (day[1] - '0');
    int mon = (month.length() == 1) ? (month[0] - '0') : ((month[0] - '0') * 10) + (month[1] - '0');
    int yr = ((year[0] - '0') * 10) + (year[1] - '0');
    euEnDay = (d < 10 && day.length() == 2) ? (day.substr(1, 1)) : day;
    euroMonth = (mon < 10 && month.length() == 2) ? month.substr(1, 1) : month;
    engMonth = monthsArr[mon - 1];
    fullDay = (d < 10 && day.length() == 1) ? ("0" + day) : day;
    fullMonth = (mon < 10 && month.length() == 1) ? ("0" + month) : month;
    fullYear = (yr <= 25) ? ("20" + year) : ("19" + year);
    euro = euEnDay + "-" + euroMonth + "-" + year;
    eng = engMonth + " " + euEnDay + ", " + fullYear;
    yearDate = fullMonth + "-" + fullDay + "-" + fullYear;
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