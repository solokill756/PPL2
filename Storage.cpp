#include"Storage.h"

Storage::Storage()
{
      this->currentStorage();
}

Storage::~Storage()
{}

void Storage::currentStorage()
{
    Vector<string> S;
    string s;
    int n = 0;
    ifstream inputFile("Storage.txt");
    while (getline(inputFile, s))
    {
        if (n != 0)
        {
            int i = 0;
            int check = 1;
            Supplies su;
            while (i < s.size())
            {
                int p = i;
                string st = "";
                while (p < s.size() && s[p] != ',')
                {
                    if (s[p] != ' ')
                        st = st + s[p];
                    p++;
                }
                switch (check)
                {
                case 1:
                    su.setSuppliesCode(st);
                    check++;
                    break;
                case 2:
                    su.setSuppliesName(st);
                    check++;
                    break;
                case 3:
                    su.setKOSupplies(st);
                    check++;
                    break;
                case 4:
                    su.setAmount(Functions::Change(st));
                    check++;
                    break;
                case 5:
                    su.setSuppliesPrice(Functions::Change(st));
                    check++;
                    break;
                case 6:
                    su.setSuppliesUnit(st);
                    check++;
                    break;
                default:
                    break;
                }
                i = p + 1;
            }
            (*this).addSups(su);
        }
        n++;
    }
    inputFile.close();
}

void Storage::addSups(Supplies s)
{
    for (int i = 0; i < this->sup.getSize(); ++i)
    {
        if (this->sup[i].getSuppliesCode() == s.getSuppliesCode())
        {
            this->sup[i].setAmount(this->sup[i].getAmount() + s.getAmount());
            return;
        }
    }
    this->sup.push_back(s);
}

int Storage::checkSupplies(string &yourChoice)
{
    Functions::gotoxy(75, 3); cout << "Cac ma Vat Tu trong kho la : ";
    Functions::gotoxy(75, 4); cout << "|| ";
    for (int i = 0; i < this->sup.getSize(); ++i)
    {
        cout << this->sup[i].getSuppliesCode() << " || ";
    }
    Functions::gotoxy(75, 6); cout << "Lua chon cua ban : ";
    int pos = -1;
    while (pos == -1)
    {
        cin >> yourChoice;
        for (int i = 0; i < this->sup.getSize(); ++i)
        {
            if (yourChoice == this->sup[i].getSuppliesCode())
            {
                pos = i;
                break;
            }
        }
        if (pos == -1)
        {
            Functions::gotoxy(75, 9); cout << "                                                                                                        ";
            Functions::gotoxy(75, 8); cout << "Ma ban vua nhap khong co trong kho de thuc hien chuc nang ma ban vua chon!!!" << '\n';
            Functions::gotoxy(75, 9); cout << "Vui long nhap lai dung voi nhung ma Vat Tu chung toi dua ra : ";
        }
    }
    return pos;
}

void Storage::updateStorage()
{
    ofstream outFile1;
    outFile1.open("Storage.txt", ios::trunc);
    outFile1 << "|   Mã vật tư   |   Tên vật tư  |  Mã Loại vật tư |    Số lượng     |   Đơn giá | Mã đơn vị |" << '\n';
    for (int i = 0; i < this->sup.getSize(); ++i)
    {
        outFile1 << "    " << setw(11) << left << this->sup[i].getSuppliesCode() << " , ";
        outFile1 << setw(13) << left << this->sup[i].getSuppliesName() << " , ";
        outFile1 << setw(15) << left << this->sup[i].getKOSupplies() << " , ";
        outFile1 << setw(15) << left << this->sup[i].getAmount() << " , ";
        outFile1 << setw(9) << left << this->sup[i].getSuppliesPrice() << " , ";
        outFile1 << setw(8) << left << this->sup[i].getSuppliesUnit();
        outFile1 << '\n';
    }
    outFile1.close();
    if (outFile1.is_open())
        outFile1.close();
}

Vector<Supplies> &Storage::getSups()
{
    return this->sup;
}

void Storage::SortStorage(const int &x, const int &y, int l, int r)
{
    int i = l, j = r;
    Supplies p = this->getSups()[(l + r) / 2];
    while (i < j)
    {
        switch (x)
        {
        case 1:
            if (y == 1)
            {
                while (Functions::compareString(this->getSups()[i].getSuppliesCode(), p.getSuppliesCode()) == 2)
                    i++;
                while (Functions::compareString(this->getSups()[j].getSuppliesCode(), p.getSuppliesCode()) == 1)
                    j--;
            }
            else if (y == 2)
            {
                while (Functions::compareString(this->getSups()[i].getSuppliesCode(), p.getSuppliesCode()) == 1)
                    i++;
                while (Functions::compareString(this->getSups()[j].getSuppliesCode(), p.getSuppliesCode()) == 2)
                    j--;
            }
            break;
        case 2:
            if (y == 1)
            {
                while (Functions::compareString(this->getSups()[i].getSuppliesName(), p.getSuppliesName()) == 2)
                    i++;
                while (Functions::compareString(this->getSups()[j].getSuppliesName(), p.getSuppliesName()) == 1)
                    j--;
            }
            else if (y == 2)
            {
                while (Functions::compareString(this->getSups()[i].getSuppliesName(), p.getSuppliesName()) == 1)
                    i++;
                while (Functions::compareString(this->getSups()[j].getSuppliesName(), p.getSuppliesName()) == 2)
                    j--;
            }
            break;
        case 3:
            if (y == 1)
            {
                while (Functions::compareString(this->getSups()[i].getKOSupplies(), p.getKOSupplies()) == 2)
                    i++;
                while (Functions::compareString(this->getSups()[j].getKOSupplies(), p.getKOSupplies()) == 1)
                    j--;
            }
            else if (y == 2)
            {
                while (Functions::compareString(this->getSups()[i].getKOSupplies(), p.getKOSupplies()) == 1)
                    i++;
                while (Functions::compareString(this->getSups()[j].getKOSupplies(), p.getKOSupplies()) == 2)
                    j--;
            }
            break;
        case 4:
            if (y == 1)
            {
                while (this->getSups()[i].getAmount() < p.getAmount())
                    i++;
                while (this->getSups()[j].getAmount() > p.getAmount())
                    j--;
            }
            else if (y == 2)
            {
                while (this->getSups()[i].getAmount() > p.getAmount())
                    i++;
                while (this->getSups()[j].getAmount() < p.getAmount())
                    j--;
            }
            break;
        case 5:
            if (y == 1)
            {
                while (this->getSups()[i].getSuppliesPrice() < p.getSuppliesPrice())
                    i++;
                while (this->getSups()[j].getSuppliesPrice() > p.getSuppliesPrice())
                    j--;
            }
            else if (y == 2)
            {
                while (this->getSups()[i].getSuppliesPrice() > p.getSuppliesPrice())
                    i++;
                while (this->getSups()[j].getSuppliesPrice() < p.getSuppliesPrice())
                    j--;
            }
            break;
        default:
            break;
        }
        if (i <= j)
        {
            // cout << i << " " << j << '\n';
            Supplies temp = this->getSups()[i];
            this->getSups()[i] = this->getSups()[j];
            this->getSups()[j] = temp;
            i++;
            j--;
        }
    }
    if (i < r)
    {
        this->SortStorage(x, y, i, r);
    }
    if (l < j)
    {
        this->SortStorage(x, y, l, j);
    }
}