#include <string> // standard String library
#include <iostream> // Input-Output stream library
#include <fstream> // File stream (IO stream but for files)
using namespace std; // instead of constantly std::cout or std::cin

ofstream out("output.txt"); // output stream to a file "output", like cout but to a file
ifstream in("input.txt"); // input stream like cin, but from a file
int main() {
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
     String.length(void) function  -  returns the length of the string  
     string::size_type  -  subset of int that only allows positive values
     */
        string::size_type strLen = name.length(); 
     
     out << "\nLooping through strings like arrays, using the length function, array-access-notation and for-loop\n";
     // Looping over strings like arrays
        for(int i = 0; i < strLen; i++) out << name[i] << endl;    

    /* 
    String.find(char, int) function  -  finds the location of a char in a string and returns the location integer, starting from a position
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
    String.erase(int, int)  -  start position and number of chars to erase, mutates the original
    String.insert(int, string)  -  start position, string to insert, mutates the original
    String.replace(int, int, string)  -  start position, number to remove, string to insert, mutates the original 
    String.substr(int, int)  -  start position, number of chars, returns a new string
    */
    out << "\n\nA bunch of string functions that mutate: ";

    string eraseMe = "Erase Me!";
    out << "\nBefore: " << eraseMe;

    eraseMe.erase(0, eraseMe.length() - 1);
    out << "\nAfter Erase: " << eraseMe;

    eraseMe.insert(0, "Replace Me");
    out << "\nAfter Insert: " << eraseMe; 

    eraseMe.replace(0, eraseMe.length() - 1, "I have been replaced");
    out << "\nAfter Replace: " << eraseMe;

    out << "\n\nAnd one that does not mutate, but returns a new string";

    string subString = eraseMe.substr(0, 6);
    out << "\n\"" << subString << "\" is a substring of: \"" << eraseMe << "\"";
}