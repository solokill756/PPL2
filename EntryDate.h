#include <iostream>
#include "Supplies.h"
using namespace std;

class EntryDate
{
protected:
    string Time;
    Vector<Supplies> s;

public:
    EntryDate(string = "");
    ~EntryDate();
    string getTime();
    void setTime(const string &);
    void addSupplies(Supplies);
    const EntryDate &operator=(const EntryDate &);
    Vector<Supplies> &getSup();
    int operator==(const EntryDate &);
    // Vector<Supplies> addSup(Supplies);  ?????
};