#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "List06.h"
using namespace std;
//--------------------------------------------------------------------------
//A ListException prints an error message passed as the parameter to the console for the list
struct ListException
{
        ListException(const char* m)
        {
                cout << endl;
                cout << "I am the List and I am " << m << ".";
                cout << endl;
        }
};
//---------------------------------------------------------------------------
//This is a constructor for the List which takes a parameter for the size of the list and sets the count variable of the list to 0
List::List(int sz):size(sz),count(0){L=new int[size];}
//---------------------------------------------------------------------------
//Function isFull retuns a boolean based off of if count, the number of elements in the list, is bigger than the size of the list
bool  List::isFull(void){return count>=size;}
//----------------------------------------------------------------------------
//Function Scan reads in the data from the passed input file and returns nothing
void List::Scan(ifstream& i)
{
        //infinite loop
        for(;;)
        {
                //read in the int in the file to variable v
                int v;
                i >> v;
                //if the end of file marker has been reached break out of the loop
                if(i.eof()) break;
                //pass the value of v to the Insert function for List
                Insert(v);
        }
}
//---------------------------------------------------------------------------------
//Function insert takes an integer parameter and returns nothing. The function adds a value to the List
void List::Insert(int v)
{
        //if the isFull function returns true throw a ListException with the message "Full"
        if(isFull()) throw ListException("full");
        //otherwise L at the index of count is equal to v
        L[count]=v;
        //value of count for the list is incremented
        count++;
}
//---------------------------------------------------------------------------------
//Function print takes an argument of an output file stream and returns nothing. The function prints the list to the output file
void List::Print(ofstream& o)
{
        //a for loop to the index of count of the list, or the number of filled values in the list
        for(int a=0; a<count; a++)
        {
                //if the index of the loop mod 10 is true a endl is printed to the outfile file for formatting
                if(a%10==0)
                {
                        o << endl;
                }
                //data is printed to the output file with a width of 5 and justified to the right
                o <<setw(5) << right <<  L[a];
        }
}
//------------------------------------------------------------------------------
//The sort function takes no arguments and returns no arguments. The function sorts the list
void List::Sort(void)
{
        //loops through the list starting at the end of the list
        for(int eol=count-1; eol>0; eol--)
        {
                int iom=0;
                //loops through all the values in the list up to the current count value
                for(int i=1; i<=eol; i++) if(L[i]>L[iom]) iom=i; //if the value of List at i is greater than the value of list at iom iom, or the
                                                                //highest value is set to i
                {
                        //the swap function is used swaping the values of the list at the eol index and the iom index
                        Swap(L[eol],L[iom]);
                }
        }
}
//---------------------------------------------------------------------------------
//function Swap takes two reference parameters to swap in the list. Performs a simple swap algorithim
void List::Swap(int &m, int &w)
{
        int b=m;
        m=w;
        w=b;
}
