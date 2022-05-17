#ifndef List06_h
#define List06_h 1
//class list defines member data and functions for the class of integers
#include <iostream>
using namespace std;
class List
{
        int size;
        int count; //number of occupied elements and index of next available element
        int* L; //points to an array of ints used to implement the List
public:
        List(int sz=100);
        void Scan(ifstream& i);
        void Insert(int v);
        bool isFull(void);
        void Print(ofstream& o);
        void Sort(void);
        void Swap(int&m, int& w);
};
#endif
