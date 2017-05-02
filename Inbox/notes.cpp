// Single line comment
/*
multi-line comment
*/

#include <iostream> //input-output library
#include <cmath> //cmath library fabs = absolute value, sqrt = square root
using namespace std;

int main()
{   
    int number, square;
    number = 4;
    square = number * number;
    cout << number << " squared is" << square << endl;
    // ...loop up until 10

    // in for-loop form ->
    for(int x = 1; x < 10; x++) { // for(initialized variable; condition to check; increment)
    cout << x << " squared is " << x*x << endl;
    }

    //more for-loop examples
    for(int starCount = 1; starCount <= 20; starCount++) cout << "*";
}

//Day 2

double power (double base, double exponent);
double power (double base, double exponent) {
    return (exponent > 1) ? base * (power(base, exponent - 1)) : base;
}

int main()
{   double gpa, result;
    cout << "\tTable of Values\n" << "\tgpa\tresult\tadmit\n\t";
    for(gpa = 0.0; gpa <= 4.0; gpa += 0.5) {
        result = ((power(gpa, 3)) + (7 * gpa) - 1) / ((power(gpa,2)) - ((gpa + 5)/3));
        cout << gpa << "\t" << result << ((result > 0) ? "\tadmit\n\t" : "\n\t");
    }
}


//Day 3

// structured read loop
// > trailer method <
int main()
{
    int id;
    double hours, rate, pay;
    cout << "Enter ID: ";
    cin >> id;
    while(id > 0)
    {
        cout << "Enter hours worked and rate of pay: ";
        cin >> hours >> rate;
        pay = hours * rate;
        cout <<"ID: " << id << " Pay: " << pay << endl;
        cout << "Enter ID: ";
        cin >> id;
    }
    return 0;
}
*/
//Day 4 - Missed
// -----------------

//Day 5
/* Stepwise refinement

1*1 + 2*2 ... + 30*30 = [1*1 + ... 29*29] + 30*30 ... Sum of a series
*/

int main()
{
    int sum = 0;
    for(int x = 1; x <= 30; x++) sum += x*x;
    cout << sum;
}


// Datatype Void indicating nothing; eg. void function(void) 
// indicating a function that takes no arguments and returns nothing
//Void -> Void

// Arrays
int array5 [5] = {0, 1, 2, 3} // [0, 1, 2, 3, 0]
