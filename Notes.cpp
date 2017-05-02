#include <string> // standard String library
#include <iostream> // Input-Output stream library
#include <fstream> // File stream (IO stream but for files)
#include <cmath> //cmath aka Standard Math Library fabs = absolute value, sqrt = square root

using namespace std; // instead of constantly std::cout or std::cin

// Global variable (can be used in functions outside of the main) 
ofstream out("output.txt"); // output stream to a file "output", like cout but to a file
ifstream in("input.txt"); // input stream like cin, but from a file

// Functions
int just2 (void); // just2 :: void -> int (takes no arguments and returns an int)
int add (int, int); // add :: int -> int -> int (takes two integers and returns and integer)
int multiply (int, int); // multiply :: int -> int -> int 
void doStuff (void); // doStuff :: void -> void (takes nothing returns nothing) 

int just2 (void) {
    return 2;
}

int add (int x, int y) {
    return x + y;
}

int multiply (int x, int y) {
    return x * y;
}

void doStuff (void) {
    int result;
    out << "\njust2 is equal to: " << just2() << endl;
    out << "What if we add 2 to just2 ? : " << add(just2(), 2) << endl;
    result = multiply(add(just2(), 2), 2);
    out << "Now what if we multiply that result by 2 : " << result << "\n\n";
    return;
}


int main() {

    out << "\n";
    //Standard For-loop syntax
    for(int x = 1; x < 10; x++) { // for( initialized variable; condition to check; increment )
    out << x << " squared is " << x*x << endl;
    }

    out << "\n";
    // Standard While-loop syntax
    int number = 10;
    while (number > 0) { // while ( condition ) **BE CAREFUL OF INFINITE LOOPS**
        out << "Number is: " << number << endl;
        number--; //decrement operator -- (increment is ++)
    }
    out << "Condition failed, loop left\n";

    out << "\n";
    // Do-While-Loop syntax
    number = 0;
    do { // do { code to run } while ( condition );
        out << "Number is equal to: " << number << endl << endl;
    } while (number != 0); // Do runs at least once, regardless of while condition

    // Structured read loop
    int id;
    double hours, rate, pay;
    // out << "Enter ID: "; optional prompts for interactive input through cin
    in >> id;
    while(id > 0)
    {
        // out << "Enter Hours and Rate: ";
        in >> hours >> rate;
        pay = hours * rate;
        out << "ID: " << id << " Pay: " << pay << endl;
        // out << "Enter ID: ";
        in >> id;
    }

    // Arrays
    int integerArray[5] = {0, 1, 2, 3}; // [0, 1, 2, 3, 0]
    string stringArray[2] = {"string one", "string two"};
    char characterArray[3] = {'a', 'b', 'c'};

    // Multi-dimensional Arrays
    int mdIntArray [3][2] = {1, 2, 3, 4, 5, 6}; 
    /* 
    [
    [1, 2, 3], 
    [4, 5, 6]
    ] 
    
    3 columns, 2 rows 
    */

    // Run outside functions within main
    doStuff();

    string name; // This is a string variable
    in >> name; // from file (each call goes down a line)
    out << "Printing using string type variables: \n";
    out << name << endl; // to a file (on a new line)
    // cin >> name; prompts for input from console 
    // cout << name;  to console 

    //String!!
    out << "\nConcatinating String literals onto String variables with +=\n";
     // Concatination 
         name += " that is now concatenated";
         out << name << endl; // Word that is now concatenated;

     // Accessing and Assigning ~ string[int];
         name[0] = 'w'; // word that is now concatenated
     
     /* 
     int String.length(void) function  -  returns the length of the string  
     string::size_type  -  subset of int that only allows positive values
     */
        string::size_type strLen = name.length(); 
     
     out << "\nLooping through strings like arrays, using the length function, array-access-notation and for-loop\n";
     // Looping over strings like arrays
        for(int i = 0; i < strLen; i++) out << name[i] << endl;    

    /* 
    int String.find(char, int) function  -  finds the location of a char in a string and returns the location integer, starting from a position
    string::npos  -  npos is equal to -1; indicates no matches found from the find function
    */
    int count = 0;
    int pos = 0;
    char someChar = 'e';
    string der = "This egg is yellow!";
    out << "\nLoop on a string find function, to find each unique occurence of the char 'e'\nin string: " << der;
    do {
        pos = der.find(someChar, pos+1); 
        count = (pos == string::npos) ? count : count+1;
    } while(pos != string::npos);
    out << "\nThe total number of e's is/are: " << count;

    /* 
    void String.erase(int, int)  -  start position and number of chars to erase, mutates the original
    void String.insert(int, string)  -  start position, string to insert, mutates the original
    void String.replace(int, int, string)  -  start position, number to remove, string to insert, mutates the original 
    string String.substr(int, int)  -  start position, number of chars, returns a new string
    void String.clear(void)   -  mutates the original string and make it an empty string.
    */
    out << "\n\nA bunch of string functions that mutate: ";

    string eraseMe = "Erase Me!";
    out << "\nBefore: " << eraseMe;

    eraseMe.erase(0, eraseMe.length() - 1); // erase
    out << "\nAfter Erase: " << eraseMe;

    eraseMe.insert(0, "Replace Me"); // insert
    out << "\nAfter Insert: " << eraseMe; 

    eraseMe.replace(0, eraseMe.length() - 1, "I have been replaced"); // replace
    out << "\nAfter Replace: " << eraseMe;

    out << "\n\nAnd one that does not mutate, but returns a new string";

    string subString = eraseMe.substr(0, 6); // substr
    out << "\n\"" << subString << "\" is a substring of: \"" << eraseMe << "\"";

    out << "\n\nsubString before clear: \"" << subString << "\"\nsubString after clear: \"";
    subString.clear(); // clear
    out << subString << "\"";

}