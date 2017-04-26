#include <iostream>
#include <fstream>
using namespace std;

ifstream in("in.txt");
ofstream out("out.txt");

void readdata(int, double[]);
void printarray(int, double[]);
double findaverage(int, double[]);
void howfaraway(int, int, double[], double[]);

int main() {
  int size;
  double first[size], second[size], avg;
  
  in >> size;
  readdata(size, first);
  out << "~Heading~\n";
  printarray(size, first);
}

int readdata(int n, double numbers[]) {
  for(int i = 0; i < n; i++) in >> numbers[i];
}

void printarray(int q, double numb[]) {
  for(int i = 0; i < q; i++) out << numbs[i] << (((i+1) % 5 == 0) ? "\n" : " ");
}

double findaverage(int k, double p[]) {
  double sum;
  for(int i = 0; i < k; i++) sum += p[i];
  return sum / k;
}

void howfaraway(int m, int avg, double r[], double s[]) {
  for(int i = 0; i < m; i++) s[i] = r[i] - avg;
}
