#include "EntryDate.h"

EntryDate::EntryDate(string s) : Time(s)
{
}

EntryDate::~EntryDate()
{
}

string EntryDate::getTime()
{
    return this->Time;
}

void EntryDate::setTime(const string &Time)
{
    this->Time = Time;
}

const EntryDate &EntryDate::operator=(const EntryDate &temp)
{
    if (this != &temp)
    {
        this->Time = temp.Time;
        this->s = temp.s;
    }
    return (*this);
}

Vector<Supplies> &EntryDate::getSup()
{
    return this->s;
}

// Vector<Supplies> EntryDate::addSup(Supplies sup)
// {
//     this->s.push_back(sup);
// }

void EntryDate::addSupplies(Supplies sup)
{
    for (int i = 0; i < this->s.getSize(); ++i)
    {
        if (this->s[i].getSuppliesCode() == sup.getSuppliesCode())
        {
            this->s[i].setAmount(this->s[i].getAmount() + sup.getAmount());
            return;
        }
    }
    this->s.push_back(sup);
}

int EntryDate::operator==(const EntryDate &other)
{
    if (other.Time == this->Time)
        return 1;
    else
        return 0;
}