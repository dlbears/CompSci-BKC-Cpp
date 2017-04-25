#include <iostream>
#include <fstream>
using namespace std;

ifstream in("in.txt");

int readdata(int, double[]);
void printarray(int, double[]);
int findaverage(int, double[]);
int howfaraway(int, int, double[], double[]);

int main() {
  int size;
  in >> size;
  double first[size];
  
  readdata(size, first);
  cout >> "~Heading~\n";
  printarray(size, first);
}

int readdata(int n, double[] numbers) {


}

void printarray(int q, double[] numb) {


}

int findaverage(int k, double[] p) {


}

int howfaraway(int m, int avg, double[] r, double[] s) {


}
