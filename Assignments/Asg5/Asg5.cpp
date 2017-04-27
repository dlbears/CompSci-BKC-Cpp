/*
Dennis Orsini Assignment #5
This program will take in a fixed number of data into an array from the input
and process it with functions printing any output to the output file
*/
#include <fstream>
using namespace std;

ifstream in("in.txt");
ofstream out("out.txt");

void readData(int, double[]);
void printArray(int, double[]);
double findAverage(int, double[]);
void closestAndFurthest(int, double, double[]);
void howFarAway(int, double, double[], double[]);

int main() {
  int size; //Must assign size a value before using it for Array size
  in >> size;
  
  double first[size], second[size], avg;

  readData(size, first);
  out << "Original Array:\n"; 
  printArray(size, first);
  avg = findAverage(size, first);
  out << "\nAverage: " << avg;
  closestAndFurthest(size, avg, first);
  howFarAway(size, avg, first, second);
  out << "New Array:\n";
  printArray(size, second);
  out << "\nNew Average: " << findAverage(size, second);
}

void readData(int n, double numbers[]) {
  //Read in n numbers from input into array numbers
  for(int i = 0; i < n; i++) in >> numbers[i];
}

void printArray(int q, double numb[]) {
  //Print q numbers from array numb to output, each 5 numbers seperated by a new line
  out << fixed << "\t";
  out.precision(2);
  for(int i = 0; i < q; i++) out << numb[i] << (((i+1) % 5 == 0) ? "\n\t" : " ");
}

double findAverage(int k, double p[]) {
  //Finds the average of the first k numbers in array p and returns it
  double sum = 0;
  for(int i = 0; i < k; i++) sum += p[i];
  return (sum / k);
}

void closestAndFurthest(int q, double avg, double p[]) {
  /*
  Finds the numbers that are closest and furthest from avg in the p array, 
  using temporary arrays to store the current closest/furthest and returns the result
  */
  double closest[2] = {1000, 1000}, furthest[2] = {0, 0};
  for(int i = 0; i < q; i++) {
    double absVal = (((avg-p[i]) < 0) ? (p[i] - avg) : (avg - p[i]));
    if (absVal < closest[0]){
        closest[1] = p[i];
        closest[0] = absVal;   
    }
    if (absVal > furthest[0]){
        furthest[1] = p[i];
        furthest[0] = absVal;
    }
  }
  out << "\nFurthest from the average: " << furthest[1] << "\nClosest to the average: " << closest[1] << endl;
}

void howFarAway(int m, double avg, double r[], double s[]) {
  //Sets each value of the s array equal to the corresponding value in the r array minus the avg
  for(int i = 0; i < m; i++) s[i] = (r[i] - avg);
}

/*

Input (in.txt):

13
-210
5
54.3
0
6
17.3
-553
325
785
68.2
3.5
-100.3
1

Output (out.txt):

Original Array:
	-210.00 5.00 54.30 0.00 6.00
	17.30 -553.00 325.00 785.00 68.20
	3.50 -100.30 1.00 
Average: 30.92
Furthest from the average: 785.00
Closest to the average: 17.30
New Array:
	-240.92 -25.92 23.38 -30.92 -24.92
	-13.62 -583.92 294.08 754.08 37.28
	-27.42 -131.22 -29.92 
New Average: 0.00

*/
