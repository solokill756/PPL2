#include<iostream>
#include"EntryDate.h"
#include<ctime>
#include<iomanip>
using namespace std;

class Storage
{
protected:
    Vector<Supplies> sup;
public:
    Storage(/* args */);
    ~Storage();
    void currentStorage();
    void addSups(Supplies);
    int checkSupplies(string &);
    void updateStorage();
    Vector<Supplies> & getSups();
    void SortStorage(const int &x, const int &y, int l, int r);
};
