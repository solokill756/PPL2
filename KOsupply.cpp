#include"KOsupply.h"

KOsupply::KOsupply(/* args */)
{
}

KOsupply::~KOsupply()
{
}

void KOsupply::setSuppliesCode(string sc)
{
    this->supplies_code = sc;
}

string KOsupply::getSuppliesCode()
{
    return this->supplies_code;
}

string KOsupply::getNameSup()
{
    return this->nameSup;
}
void KOsupply::setNameSup(string ns)
{
    this->nameSup = ns;
}

const KOsupply& KOsupply::operator=(const KOsupply& temp)
{
    if (this != &temp)
    {
        this->supplies_code = temp.supplies_code;
        this->nameSup = temp.nameSup;
    }
    return *this;
}