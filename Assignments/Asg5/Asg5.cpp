#include <iostream>
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
  int size;
  double first[size], second[size], avg;

  in >> size;
  readData(size, first);
  out << "Original Array:\n"; 
  printArray(size, first);
  avg = findAverage(size, first);
  out << "\nAverage: " << avg;
  closestAndFurthest(size, avg, first);
  howFarAway(size, avg, first, second);
  printArray(size, first);
}

int readData(int n, double numbers[]) {
  for(int i = 0; i < n; i++) in >> numbers[i];
}

void printArray(int q, double numb[]) {
  for(int i = 0; i < q; i++) out << numbs[i] << (((i+1) % 5 == 0) ? "\n" : " ");
}

double findAverage(int k, double p[]) {
  double sum;
  for(int i = 0; i < k; i++) sum += p[i];
  return sum / k;
}

void closestAndFurthest(int q, double avg, double p[]) {
  double closest = 1000, furthest = 0;
  for(int i = 0; i < q; i++) {
    double absVal = (((avg-p[i]) < 0) ? p[i]-avg : avg-p[i]);
    closest = ((absVal < closest) ? p[i] : closest);
    furthest = ((absVal > furthest) ? p[i] : furthest);
  }
  out << "\nFurthest from the average: " << furthest << "\nClosest to the average: " << closest << endl;
}

void howFarAway(int m, double avg, double r[], double s[]) {
  for(int i = 0; i < m; i++) s[i] = r[i] - avg;
}
