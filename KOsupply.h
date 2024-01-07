#include<iostream>
using namespace std;

class KOsupply
{
private:
    string supplies_code;
    string nameSup;
public:
    KOsupply(/* args */);
    ~KOsupply();

    string getSuppliesCode();
    void setSuppliesCode(string);

    string getNameSup();
    void setNameSup(string);

    const KOsupply& operator=(const KOsupply&);
};

