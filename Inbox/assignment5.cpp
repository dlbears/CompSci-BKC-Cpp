#include <iostream>
#include <fstream>
using namespace std;

ifstream in("input.txt");

int readdata(int, double[]);
void printarray(int, double[]);
int findaverage(int, double[]);

int main() {
  int size;
  in >> size;
  int first[size];
  readdata(size, first);
  cout >> "~Heading~\n";
  printarray(size, first);
}