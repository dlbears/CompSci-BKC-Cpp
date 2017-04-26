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

    out << "\nConcatinating String literals onto String variables with +=\n";
     // String concatination
         name += " that is now concatenated";
         out << name << endl; // Word that is now concatenated;

     // String access/editing
         name[0] = 'w'; // word that is now concatenated
     
     /* 
     String length function returns the length of the string - \0 (at the end) 
     string::size_type, subset of int that only allows positive values
     */
        string::size_type strLen = name.length(); 
     
     out << "\nLooping through strings like arrays, using the length function, array-access-notation and for-loop\n";
     //Print out each char on its own line
        for(int i = 0; i < strLen; i++) out << name[i] << endl;    
}