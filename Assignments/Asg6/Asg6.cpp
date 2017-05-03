#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

ifstream in("input.txt");
void readData (int&, int[], int[]);
void printData (int, int[], int[]);

void readData (int& x, int y[], int z[]) {
    in >> x;
    for(int k = 0; k < x; k++) {
        in >> y[k];
        in >> z[k];
    }
    return;
}

void printData (int x, int y[], int z[]) {
    cout << "************\nID  Donation\n";
    for(int k = 0; k < x; k++) cout << y[k] << " " << z[k] << "\n";
    cout << "************";
    return;
}

void arraySort (int n, int y[], int z[]) {
    for(int k = 0; k < n - 1; k++) {
        for(int j = k+1; j < n; j++) { 
            if (y[k] > y[j]) {
                int temp = y[k];
                y[k] = y[j];
                y[j] = temp;
                temp = z[k];
                z[k] = z[j];
                z[j] = temp;
            }
        }
    }
}

    


int main() {
    int n;
    int* idNumbers = new int[n];
    int* donations = new int[n];
    readData(n, idNumbers, donations);
    printData(n, idNumbers, donations);
    arraySort(n, idNumbers, donations);
    printData(n, idNumbers, donations);
    arraySort(n, donations ,idNumbers);
    printData(n, idNumbers, donations);
}
