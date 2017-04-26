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
  for(int i = 0; i < n; i++) in >> numbers[i];
}

void printArray(int q, double numb[]) {
  out << fixed << "\t";
  out.precision(2);
  for(int i = 0; i < q; i++) out << numb[i] << (((i+1) % 5 == 0) ? "\n\t" : " ");
}

double findAverage(int k, double p[]) {
  double sum = 0;
  for(int i = 0; i < k; i++) sum += p[i];
  return (sum / k);
}

void closestAndFurthest(int q, double avg, double p[]) {
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
  for(int i = 0; i < m; i++) s[i] = (r[i] - avg);
}
