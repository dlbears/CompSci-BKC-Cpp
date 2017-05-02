// Dennis Orsini
// Program #1
/*
The program loops over a range of values from -3.0 to 3.0 in increments of 0.5 and for each
calculating using the built-in C++ math library a y-value and printing it out to the console
along with the x-value.

Then checking if the y-value is closer to zero than the saved value, if so save it and its
X-value, then print out whether the Y value is Positive, Negative or Zero and adding to the
count.

Then after finishing the loop, printing the stored counts of positive, negative, and zero Ys
Then the Y-value that is closest to Zero along with its X-pair
*/
#include <iostream>
#include <math.h>
using namespace std;


int main()
{
    double x, y, xMemo, yMemo;
    int pCount, nCount, zCount;
    pCount = 0;
    nCount = 0;
    zCount = 0;
    xMemo = 0;
    yMemo = -1000;

    cout << "Dennis Orsini\tProgram #1\n\tX\t\tY\t\tDescription\n";

    for(x = -3.0; x <= 3; x += 0.5){
        y = (((4*pow(x,3))+(8*pow(x,2))-(31*x)-35)/(sqrt(3*pow(x,2)+1)+(2*fabs(x-1.5))));

        cout << "\t" << x << "        \t" << y << "       \t";

        if (fabs(yMemo) > fabs(y) && y != 0) {
            yMemo = y;
            xMemo = x;
        }

        if (y > 0) {
            pCount++;
            cout << "Y IS POSITIVE\n";
        } else if (y < 0) {
            nCount++;
            cout << "Y IS NEGATIVE\n";
        } else {
            zCount++;
            cout << "Y IS ZERO\n";
        }
    }

    cout << "Positive Ys: " << pCount << "\nNegative Ys: " << nCount;
    cout << "\nZero Ys: " << zCount;
    cout << "\nY closest to zero: " << yMemo << " (" << (fabs(yMemo)) << " from 0)\n";
    cout << "X pair: " << xMemo << "\nPROGRAM 1 COMPLETE\n";
}
