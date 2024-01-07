#include<iostream>
using namespace std;

class Manufacturer
{
private:
    string manufacturer;
    string nameMF;
public:
    Manufacturer();
    ~Manufacturer();

    string getManufacturer();
    void setManufacturer(string);

    string getNameMF();
    void setNameMF(string);

    const Manufacturer& operator=(const Manufacturer&);
};


