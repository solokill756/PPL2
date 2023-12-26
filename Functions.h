#include<iostream>
#include<fstream>
#include<windows.h>
using namespace std;
class Functions {
    public:
        static int Change(const string&);
        static int conpare(string , string);
        static int compareString(const string&, const string&);
        static void gotoxy(int, int);
        static void setcolor(int);
        static int getX();
        static int getY();
        static void newTerminal();
        static void setConsoleSize(int, int);
        static long long getCostOfSupp(long long , long long);
        static string getKindOfSupps(const string&);
        static string getUnitOfSupps(const string&);
        static string getManufacturers(const string&);
};