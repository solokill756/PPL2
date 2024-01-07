#include"Manufacturer.h"

Manufacturer::Manufacturer()
{
}

Manufacturer::~Manufacturer()
{
}

string Manufacturer::getManufacturer()
{   
    return this->manufacturer;
}

void Manufacturer::setManufacturer(string manufacturer)
{
    this->manufacturer = manufacturer;
}

string Manufacturer::getNameMF()
{
    return nameMF;
}

void Manufacturer::setNameMF(string nameMF)
{
    this->nameMF = nameMF;
}

const Manufacturer &Manufacturer::operator=(const Manufacturer &temp)
{
    if (this != &temp)
    {
        this->manufacturer = temp.manufacturer;
        this->nameMF = temp.nameMF;
    }
    return *this;
}

