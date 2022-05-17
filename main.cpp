#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "List06.h"
using namespace std;
//--------------------------------------------------------------------------
//CommandLineException takes the max number of command line arguments and the number of arguments passed and prints a CommandLineException
struct CommandLineException {
        CommandLineException(int max,int actual)
        {
                cout << endl << "Too many command line arguments." << endl;
                cout << "A maximum of " << max << " arguments are permitted." << endl;
                cout << actual << " arguments were entered." << endl;
        }
};
//A FileException takes a char of the file name and writes that the file passed can not be opened
struct FileException {
        FileException(const char* fn)
        { cout << endl << "File " << fn << " could not be opened." << endl;
        }
};

//int main can take 0, 1 or 2 arguments from the command line
int main(int argc, char* argv[])
{
        try {
        char ifn[255], ofn[255]; //Input and output file names
        switch (argc)
        {
                case 1: //Prompt for both file names
                         cout << "Enter the input file name. ";
                        cin >> ifn;
                        cout << "Enter the output file name. ";
                        cin >> ofn;
                        break;
                case 2: //Prompt for the output file name
                        strcpy(ifn,argv[1]);
                        cout << "Enter the output file name. ";
                        cin >> ofn;
                        break;
                case 3: //Both file names are arguments
                        strcpy(ifn,argv[1]);
                        strcpy(ofn,argv[2]);
                        break;
                default:
                        throw CommandLineException(2,argc-1);
                         break;
        }
        //if the input file doesn't exist throw a FileException with the input file name
        ifstream i(ifn); if (!i) throw FileException(ifn);
        //if the output file doesn't exist throw a FileException with the output file name
        ofstream o(ofn); if (!o) throw FileException(ofn);
        //Makes a list of 1000
        List L(1000);
        //uses the List Scan function to read in the data with the input file
        L.Scan(i);
        o << "Unsorted list:";
        //uses the List Print function to print the unsorted list to the output file
        L.Print(o);
        o << endl;
        o << endl << "Sorted list:";
        //Sorts the list using the List Sort function
        L.Sort();
        //The sorted List is printed using the List Print function
        L.Print(o);
        //The input and output files are closed
        o.close();
        i.close();
//if anything goes wrong in the try statement it is printed that the program was terminated and is exited
 } catch (... ) {
        cout << "Program terminated." << endl;
        exit(EXIT_FAILURE);
        }
        return 0;
}
