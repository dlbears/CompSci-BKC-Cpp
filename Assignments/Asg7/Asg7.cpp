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