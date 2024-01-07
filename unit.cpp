#include"unit.h"

unit::unit(/* args */)
{
}

unit::~unit()
{
}

void unit::setNameUnit(string nu)
{
    this->nameUnit = nu;
}

string unit::getNameUnit()
{
    return nameUnit;
}

string unit::getSuppliesUnit()
{
    return this->supplies_unit;
}

void unit::setSuppliesUnit(string su)
{
    this->supplies_unit = su;
}

const unit &unit::operator=(const unit &temp)
{
    if (this != &temp)
    {
        this->nameUnit = temp.nameUnit;
        this->supplies_unit = temp.supplies_unit;
    }
    return *this;
}
