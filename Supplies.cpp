#include "Supplies.h"

Supplies::Supplies(string sc, string kos, string sn, string manu, long long sp, int amount, string su)
{
    this->supplies_code = sc;
    this->supplies_name = sn;
    this->manufacturers = manu;
    this->kind_of_supplies = kos;
    this->supplies_unit = su;
    this->supplies_price = sp;
    this->amount = amount;
}

void Supplies::setSuppliesCode(string sc)
{
    this->supplies_code = sc;
}

string Supplies::getSuppliesCode()
{
    return this->supplies_code;
}

void Supplies::setSuppliesName(string sn)
{
    this->supplies_name = sn;
}

string Supplies::getSuppliesName()
{
    return this->supplies_name;
}

void Supplies::setSuppliesUnit(string su)
{
    this->supplies_unit = su;
}

string Supplies::getSuppliesUnit()
{
    return this->supplies_unit;
}

void Supplies::setSuppliesPrice(long long sp)
{
    this->supplies_price = sp;
}

long long Supplies::getSuppliesPrice()
{
    return supplies_price;
}

void Supplies::setSuppliesMa(string sm)
{
    this->manufacturers = sm;
}

string Supplies::getSuppliesMa()
{
    return manufacturers;
}

void Supplies::setKOSupplies(string kos)
{
    this->kind_of_supplies = kos;
}

string Supplies::getKOSupplies()
{
    return kind_of_supplies;
}

void Supplies::setAmount(int amount)
{
    this->amount = amount;
}

int Supplies::getAmount()
{
    return amount;
}

const Supplies &Supplies::operator=(const Supplies &temp)
{
    if (this != &temp)
    {
        this->supplies_code = temp.supplies_code;
        this->supplies_name = temp.supplies_name;
        this->manufacturers = temp.manufacturers;
        this->kind_of_supplies = temp.kind_of_supplies;
        this->supplies_unit = temp.supplies_unit;
        this->supplies_price = temp.supplies_price;
        this->amount = temp.amount;
    }
    return *this;
}

int Supplies::operator==(const Supplies &temp)
{
    if (temp.supplies_code == this->supplies_code)
        return 1;
    else
        return 0;
}

Supplies::~Supplies() {}

istream &operator>>(istream &i, Supplies &su)
{
    int currentY = Functions::getY() + 1;
    Functions::gotoxy(75, currentY++); cout << "Ten vat tu : ";
    i >> su.supplies_name;
    ifstream input_file;
    input_file.open("Supplies.txt", ios::in);
    string s;
    Functions::gotoxy(75, currentY++); cout << "Cac ki hieu vat tu co san trong kho la : ";
    int count = 0;
    while (getline(input_file, s))
    {
        if (count != 0) 
        {
            Functions::gotoxy(75, currentY++); cout << s;
        }
        count++;
    }
    input_file.close();
    Functions::gotoxy(75, currentY++); cout << "Moi ban nhap ki hieu loai vat tu : ";
    i >> su.kind_of_supplies;
    s = Functions::getKindOfSupps(su.kind_of_supplies);
    while (s == "")
    {   
        Functions::gotoxy(75, currentY + 1); cout << "                                                                                                        ";
        Functions::gotoxy(75, currentY); cout << "Ki hieu loai vat tu ban vua nhap khong co san trong kho !";
        Functions::gotoxy(75, currentY + 1); cout << "Moi ban nhap lai : ";
        cin >> su.kind_of_supplies;
        s = Functions::getKindOfSupps(su.kind_of_supplies);
    }
    currentY += 2;
    count = 0;
    input_file.open("Unit.txt", ios::in);
    Functions::gotoxy(75, currentY++); cout << "Cac ki hieu don vi co san trong kho la : ";
    while (getline(input_file, s))
    {
        if (count != 0)
        {
            Functions::gotoxy(75, currentY++); cout << s;
        }
        count++;
    }
    input_file.close();
    Functions::gotoxy(75, currentY++); cout << "Moi ban nhap ki hieu don vi : ";
    i >> su.supplies_unit;
    s = Functions::getUnitOfSupps(su.supplies_unit);
    while (s == "")
    {
        Functions::gotoxy(75, currentY + 1); cout << "                                                                                                        ";
        Functions::gotoxy(75, currentY); cout << "Ki hieu don vi ban vua nhap khong co san trong kho !" << endl;
        Functions::gotoxy(75, currentY + 1); cout << "Moi ban nhap lai : ";
        cin >> su.supplies_unit;
        s = Functions::getUnitOfSupps(su.supplies_unit);
    }
    currentY += 2;
    Functions::gotoxy(75, currentY++); cout << "Gia tien : ";
    i >> su.supplies_price;
    return i;
}

long long Supplies::GetTotalCost()
{
    // double sl = double(this->amount);
    if (this->amount > 200)
    {
        return this->amount * (this->supplies_price * 85 / 100);
    }
    else if (this->amount > 100 && this->amount <= 200)
    {
        return this->amount * (this->supplies_price * 90 / 100);
    }
    else
    {
        return this->amount * this->supplies_price;
    }
}


