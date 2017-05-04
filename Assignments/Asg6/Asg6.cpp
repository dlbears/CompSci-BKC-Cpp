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
        int id, donation, cond;
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
                break;
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
    arraySort(n, idNumbers, donations);
    printData(n, idNumbers, donations);

    cout << "\n\nAFTER DONATION SORT\n";
    arraySort(n, donations ,idNumbers);
    printData(n, idNumbers, donations);

    return 0;
}

/* input.txt:
15
500 123123
453 523443
512 236334
123 543121
122 662353
473 123555
363 987965
986 243632
668 333333
555 757999
998 153422
173 666634
265 286356
789 842698
234 347977


cout:

BEFORE SORT
************
ID  Donation
500 123123
453 523443
512 236334
123 543121
122 662353
473 123555
363 987965
986 243632
668 333333
555 757999
998 153422
173 666634
265 286356
789 842698
234 347977
************

SORTED BY ID
************
ID  Donation
122 662353
123 543121
173 666634
234 347977
265 286356
363 987965
453 523443
473 123555
500 123123
512 236334
555 757999
668 333333
789 842698
986 243632
998 153422
************

Add data? (Y/N) Y
ID: 998
ID: 998 already exists
with 153422 in donations.

Any more data? (Y/N) Y
ID: 111
Donation: 111111

Any more data? (Y/N) Y
ID: 645
Donation: 666666

Any more data? (Y/N) Y
ID: 351
Donation: 321234

Any more data? (Y/N) Y
ID: 898
Donation: 888987

Any more data? (Y/N) Y
ID: 173
ID: 173 already exists
with 666634 in donations.

Any more data? (Y/N) Y
ID: 654
Donation: 456654

Any more data? (Y/N) Y
ID: 444
Donation: 444444

Any more data? (Y/N) N

SORTED BY ID AFTER ADDITIONS
************
ID  Donation
111 111111
122 662353
123 543121
173 666634
234 347977
265 286356
351 321234
363 987965
444 444444
453 523443
473 123555
500 123123
512 236334
555 757999
645 666666
654 456654
668 333333
789 842698
898 888987
986 243632
998 153422
************

AFTER DONATION SORT
************
ID  Donation
111 111111
500 123123
473 123555
998 153422
512 236334
986 243632
265 286356
351 321234
668 333333
234 347977
444 444444
654 456654
453 523443
123 543121
122 662353
173 666634
645 666666
555 757999
789 842698
898 888987
363 987965
************
*/