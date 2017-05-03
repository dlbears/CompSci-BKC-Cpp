#include <fstream>
#include <iostream>
using namespace std;

ifstream in("input.txt");
void readData (int&, int*, int*);

void readData (int& x, int* y, int* z) {
    in >> x;
    for(int k = 0; k < x; k++) {
        in >> y[k];
        in >> z[k];
    }
    return;
}

int main() {
    int n;
    int* idNumbers = new int[n];
    int* donations = new int[n];
    readData(n, idNumbers, donations);
    for (int k = 0; k < n; k++) cout << idNumbers[k] << " " << donations[k] << endl;
}
