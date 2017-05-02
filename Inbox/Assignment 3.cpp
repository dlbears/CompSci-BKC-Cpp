/*
Dennis Orsini Assignment 3

This program uses a structured read loop to take in data (three integers) and process it through the utilization of 4 utility functions.
That find the sum of the three inputted integers, print my name that many times, if it is within a specified range, then checks how many
of the integers are even, then, increments a counter for the number of datasets processed, finally, once all the data is processed,
signified by entering 88 for the first value, the loop then breaks and the total number of datasets processed is printed, terminating the program.
*/
#include <iostream>
using namespace std;

void introduction(void);
int findsum(int, int, int);
void printmyname(int);
int howmanyeven(int, int, int);

int sets = 0, largestValue = 0, smallestValue = 10000, timesNamePrinted = 0, a = 0, b, c;

int main()
{
  cout << "Dennis Orsini Assignment 3\n\n";
  introduction();
  cin >> a;
  while(a != 88)
  {
    cin >> b >> c;
    cout << "The original integers are: " << a << ", " << b << ", " << c << "\nThe sum is: " << findsum(a, b, c) << endl;
    printmyname(findsum(a, b, c));
    cout << "There " << ((howmanyeven(a, b, c) == 1) ? "is " : "are ") << howmanyeven(a, b, c) << " even " << ((howmanyeven(a, b, c) == 1) ? "number.\n\n" : "numbers.\n\n");
    sets++;
    cin >> a;
  }
  cout << sets << " sets of data entered and processed.";
  cout << "\nName was printed: " << timesNamePrinted << ((timesNamePrinted > 1) ? " times" : " time");
  cout << "\nLargest sum computed: " << largestValue << "\nSmallest sum computed: " << smallestValue;
  return 0;
}

void introduction(void) {
    // Prints to the console predefined introductory text describing the program, take and returns nothing.
    cout << "This program uses a structured read loop to take in data (three integers) and process it through the utilization of 4 utility functions.";
    cout << "\nThat find the sum of the three inputted integers, print my name that many times, if it is within a specified range, then checks how many\n";
    cout << "of the integers are even, then, increments a counter for the number of datasets processed, finally, once all the data is processed, \n";
    cout << "signified by entering 88 for the first value, the loop then breaks and the total number of datasets processed is printed, terminating the program.\n\n";
}

int findsum(int a, int b, int c) {
    // Takes in in three integers, a, b, and c, and returns the sum of the larger two, checks if it is larger or smaller than the ones stored, and returns the sum.
    int sum = ((a > b) ? ((b > c) ? a + b : a + c) : ((a > c) ? a + b : b + c));

    if (a > b)
        if (b > c) return a + b;
        else return a + c;
    else if (a > c) return a + b;
    else return b + c;


    largestValue = (sum > largestValue) ? sum : largestValue;
    smallestValue = (sum < smallestValue) ? sum : smallestValue;
    return sum;
}

void printmyname(int d) {
    // Takes in an integer, d, and prints to the console my name d many times, unless the integer is less than 0 and greater than 10.
    if (d >= 1 && d <= 10) {
        for(int x = 0; x < d; x++) {
            cout << "Dennis Orsini\n";
            timesNamePrinted++;
        }
    } else {
     cout << "It is not possible to print the name in this case.\n";
    }
}

int howmanyeven(int a, int b, int c) {
    // Takes in three integers, a, b, and c, and determines how many of these integers are even, then returning the count.
    int count = 0;
    if (a % 2 == 0) count++;
    if (b % 2 == 0) count++;
    if (c % 2 == 0) count++;
    return count;
}
