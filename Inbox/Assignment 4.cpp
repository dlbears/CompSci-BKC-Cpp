/* Dennis Orsini Assignment 4

This program utilizes a structured read-loop to read in integers a, b, and c which are then
checked for validity, and ran through a classify function which further runs more functions
on the pre-validated data. The loop then repeats until no more data is needed to be processed
as indicated by 999, after which the program prints out the total number of groups processed,
and how many were valid and how many were invalid.

*/
#include <iostream>
#include <fstream>
using namespace std;

ofstream out("output.txt");

bool isitavalidgroup(int, int, int);
void classify(int, int, int);
void rateonescore(int);
int findtotalscore(int, int, int);
void ratethegroup(int, int, int, int);


int main() {
    int a, b, c, validgroups = 0, invalidgroups = 0, groups = 0;

	out << "Dennis Orsini Assignment 4\n\n";

    cin >> a;
    while (a != 999) {
        cin >> b >> c;
        out << "\tSAT Scores: " << a << ", " << b << ", " << c << "\n\t";
        out << "The group data " << ((isitavalidgroup(a, b, c)) ? "is valid.\n" : "is not valid.\n");
        if (isitavalidgroup(a, b, c)) {
            validgroups++;
            groups++;
            classify(a, b, c);
        } else {
            invalidgroups++;
            groups++;
        }
        cin >> a;
		out << "\n\n";
    }

    out << "Total number of groups processed: " << groups << "\nNumber of valid groups: " << validgroups;
    out << "\nNumber of invalid groups: " << invalidgroups;

    out.close();
    return 0;
}

bool isitavalidgroup(int a, int b, int c) {
    // Receives three integers and checks whether they are within a specified range, if any fail returning false else true.
    int group[3] = {a, b, c};
    for (int x = 0; x < 3; x++) if (group[x] < 200 || group[x] > 800 || group[x] % 10 != 0) return false;
    return true;
}

void classify(int a, int b, int c) {
    // The functions receives three integers and calls multiple functions on these values then returns control to the main program.
    int group[3] = {a, b, c};
    for (int x = 0; x < 3; x++) rateonescore(group[x]);

    out << "\tThe sum for this group is: " << findtotalscore(a, b, c) << "\n\t";
    ratethegroup(a, b, c, findtotalscore(a, b, c));
    return;

}

void rateonescore(int d) {
    // Takes one integer and outputs to the console a predefined message contingent on the value received.
    if(d < 500) {
        out << "\tThe score is less than 500.";
    } else if (d < 800) {
        out << "\tThe score is between 500 and 800.";
    } else {
        out << "\tThe score is 800, a perfect score.";
    }
    out << endl;
    return;
}

int findtotalscore(int d, int e, int f) {
    // Takes three integers and returns the sum as an integer to the caller.
    return d + e + f;
}

void ratethegroup(int d, int e, int f, int total) {
    // Takes 4 integers and uses a set of conditions to determine what predefined message to print.
    if (total>=2100&&(d>=700&&e>=700&&f>=700)) {
        out << "The group status is: outstanding";
    } else if (total>=2100&&((d>=700&&e>=700)||(e>=700&&f>=700)||(d>=700&&f>=700))) {
        out << "The group status is: very good";
    } else if (total>=2100&&(d>=700||e>=700||f >= 700)) {
        out << "The group status is: lop-sided";
    } else if (total<2100&&(d<500||e<500||f<500)) {
        out << "The group status is: weak";
    } else {
        out << "The group status is: erratic";
    }
    out << endl;
    return;
}




























/*Output:
Dennis Orsini Assignment 4

	SAT Scores: 600, 1000, 300
	The group data is not valid.


	SAT Scores: 750, 780, 800
	The group data is valid.
	The score is between 500 and 800.
	The score is between 500 and 800.
	The score is 800, a perfect score.
	The sum for this group is: 2330
	The group status is: outstanding


	SAT Scores: 690, 780, 790
	The group data is valid.
	The score is between 500 and 800.
	The score is between 500 and 800.
	The score is between 500 and 800.
	The sum for this group is: 2260
	The group status is: very good


	SAT Scores: 102, 234, 222
	The group data is not valid.


	SAT Scores: 800, 690, 690
	The group data is valid.
	The score is 800, a perfect score.
	The score is between 500 and 800.
	The score is between 500 and 800.
	The sum for this group is: 2180
	The group status is: lop-sided


	SAT Scores: 490, 480, 470
	The group data is valid.
	The score is less than 500.
	The score is less than 500.
	The score is less than 500.
	The sum for this group is: 1440
	The group status is: weak


	SAT Scores: 250, 280, 300
	The group data is valid.
	The score is less than 500.
	The score is less than 500.
	The score is less than 500.
	The sum for this group is: 830
	The group status is: weak


	SAT Scores: 799, 800, 801
	The group data is not valid.


	SAT Scores: 675, 844, 700
	The group data is not valid.


	SAT Scores: 700, 600, 430
	The group data is valid.
	The score is between 500 and 800.
	The score is between 500 and 800.
	The score is less than 500.
	The sum for this group is: 1730
	The group status is: weak


	SAT Scores: 220, 480, 770
	The group data is valid.
	The score is less than 500.
	The score is less than 500.
	The score is between 500 and 800.
	The sum for this group is: 1470
	The group status is: weak


	SAT Scores: 550, 430, 220
	The group data is valid.
	The score is between 500 and 800.
	The score is less than 500.
	The score is less than 500.
	The sum for this group is: 1200
	The group status is: weak


	SAT Scores: 199, 200, 201
	The group data is not valid.


	SAT Scores: 550, 770, 420
	The group data is valid.
	The score is between 500 and 800.
	The score is between 500 and 800.
	The score is less than 500.
	The sum for this group is: 1740
	The group status is: weak


	SAT Scores: 520, 770, 530
	The group data is valid.
	The score is between 500 and 800.
	The score is between 500 and 800.
	The score is between 500 and 800.
	The sum for this group is: 1820
	The group status is: erratic


	SAT Scores: 210, 790, 660
	The group data is valid.
	The score is less than 500.
	The score is between 500 and 800.
	The score is between 500 and 800.
	The sum for this group is: 1660
	The group status is: weak


	SAT Scores: 330, 460, 770
	The group data is valid.
	The score is less than 500.
	The score is less than 500.
	The score is between 500 and 800.
	The sum for this group is: 1560
	The group status is: weak


	SAT Scores: 876, 185, 600
	The group data is not valid.


	SAT Scores: 760, 770, 780
	The group data is valid.
	The score is between 500 and 800.
	The score is between 500 and 800.
	The score is between 500 and 800.
	The sum for this group is: 2310
	The group status is: outstanding


	SAT Scores: 320, 510, 800
	The group data is valid.
	The score is less than 500.
	The score is between 500 and 800.
	The score is 800, a perfect score.
	The sum for this group is: 1630
	The group status is: weak


	SAT Scores: 800, 650, 220
	The group data is valid.
	The score is 800, a perfect score.
	The score is between 500 and 800.
	The score is less than 500.
	The sum for this group is: 1670
	The group status is: weak


	SAT Scores: 500, 985, 250
	The group data is not valid.


	SAT Scores: 450, 350, 780
	The group data is valid.
	The score is less than 500.
	The score is less than 500.
	The score is between 500 and 800.
	The sum for this group is: 1580
	The group status is: weak


	SAT Scores: 690, 230, 220
	The group data is valid.
	The score is between 500 and 800.
	The score is less than 500.
	The score is less than 500.
	The sum for this group is: 1140
	The group status is: weak


	SAT Scores: 234, 232, 986
	The group data is not valid.


	SAT Scores: 540, 550, 330
	The group data is valid.
	The score is between 500 and 800.
	The score is between 500 and 800.
	The score is less than 500.
	The sum for this group is: 1420
	The group status is: weak


Total number of groups processed: 26
Number of valid groups: 18
Number of invalid groups: 8
*/
