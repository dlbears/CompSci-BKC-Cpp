#include <fstream>
#include <iostream>
using namespace std;

ifstream in("input.txt");
void readData (int&, int[], int[]);
void printData (int, int[], int[]);
void addData (int&, int[], int[]);
int arrayFind (int, int, int[]);

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

void arraySort (int x, int y[], int z[]) {
    for(int k = 0; k < x - 1; k++) {
        for(int j = k+1; j < x; j++) { 
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
    return;
}

void addData (int& x, int y[], int z[]) {
    char response;
    cout << "\n\nAdd data? (Y/N) ";
    cin >> response; 
    while (response == 'Y') { //add toUpper methoed
        int id = 222, donation = 222, cond;
        cout << "\nID: ";
        cin >> id;
        cond = arrayFind(x, id, y);
        if (cond != -1) {
            cout << "\nID: " << y[cond] << " already exists";
            cout << "\nwith " << z[cond] << " in donations.";
        } else {
            if (x < 50) {
                cout << "\nDonation: ";
                cin >> donation;
                y[x] = id;
                z[x] = donation;
                x++;
            } else {
                cout << "\nSorry no new accounts may be added.";
                return;
            }
        }
        cout << "\n\nAny more data? (Y/N) ";
        cin >> response;
    }
}

int arrayFind (int x, int cond, int q[]) {
    for (int k = 0; k < x; k++) if (q[k] == cond) return k;
    return -1; 
}


int main() {
    int n, idNumbers[50], donations[50];
    
    cout << "\nBEFORE SORT\n";
    readData(n, idNumbers, donations);
    printData(n, idNumbers, donations);
    
    cout << "\n\nSORTED BY ID\n";
    arraySort(n, idNumbers, donations);
    printData(n, idNumbers, donations);
    
    addData(n, idNumbers, donations);
    cout << "\n\nSORTED BY ID AFTER ADDITIONS\n";
    printData(n, idNumbers, donations);
    arraySort(n, idNumbers, donations);

    cout << "\n\nAFTER DONATION SORT\n";
    arraySort(n, donations ,idNumbers);
    printData(n, idNumbers, donations);

    return 0;
}
