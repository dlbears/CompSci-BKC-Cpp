#include <string> // String type library
#include <iostream> // Input-Output stream library
#include <fstream> // File stream (IO stream but for files)
using namespace std; // instead of constantly std::cout or std::cin

ofstream out("output.txt"); // output stream to a file "output", like cout but to a file
ifstream in("input.txt"); // input stream like cin, but from a file
int main() {
    string name; //This is a string variable
    
    in >> name; // from file (each call goes down a line)
    out << name; // to a file (on a new line)

    cin >> name; // prompts for input from console 
    cout << name; // to console 
     
}