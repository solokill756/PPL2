#include<iostream>
using namespace std;

class unit
{
private:
    string supplies_unit;
    string nameUnit;
public:
    unit();
    ~unit();
    
    void setNameUnit(string);
    string getNameUnit();

    void setSuppliesUnit(string);
    string getSuppliesUnit();

    const unit& operator=(const unit&);
};

