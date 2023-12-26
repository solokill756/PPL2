#include <iostream>
#include <fstream>
#include "Vector.cpp"
#include "Functions.h"
#include <cstring>
#pragma once
using namespace std;

class Supplies {
    protected:
        string supplies_code;
        string kind_of_supplies;
        string supplies_name;
        string manufacturers;
        long long supplies_price;
        int amount;
        string supplies_unit;
    public:
        Supplies(string = "", string = "", string = "", string = "", long long = 0, int = 0, string = "");
        ~Supplies();

        void setSuppliesCode(string);
        string getSuppliesCode();

        void setSuppliesName(string);
        string getSuppliesName();

        void setSuppliesUnit(string);
        string getSuppliesUnit();

        void setSuppliesMa(string);
        string getSuppliesMa();

        void setKOSupplies(string);
        string getKOSupplies();

        void setSuppliesPrice(long long);
        long long getSuppliesPrice();

        void setAmount(int);
        int getAmount();
        
        const Supplies& operator=(const Supplies&);
        int operator==(const Supplies&);

        friend istream& operator>>(istream& , Supplies&);
        long long GetTotalCost();
};