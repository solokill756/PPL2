#include "SuppliesManage.h"

SuppliesManage::SuppliesManage()
{
    this->PutMark();
    this->currentStorage();
    this->currentEntryDate();
}

SuppliesManage::~SuppliesManage()
{
}

int SuppliesManage::checkSupplies(string &yourChoice)
{
    Functions::gotoxy(75, 3); cout << "Cac ma Vat Tu trong kho la : ";
    Functions::gotoxy(75, 4); cout << "|| ";
    for (int i = 0; i < this->sups.getSize(); ++i)
    {
        cout << this->sups[i].getSuppliesCode() << " || ";
    }
    Functions::gotoxy(75, 6); cout << "Lua chon cua ban : ";
    int pos = -1;
    while (pos == -1)
    {
        cin >> yourChoice;
        for (int i = 0; i < this->sups.getSize(); ++i)
        {
            if (yourChoice == this->sups[i].getSuppliesCode())
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

void SuppliesManage::PutMark()
{
    int n, p;
    ifstream fileInput;
    string s;
    // Lay du lieu tu file Manufacturers.txt
    fileInput.open("Manufacturers.txt", ios::in);
    n = 0;
    p = 0;
    while (getline(fileInput, s))
    {
        if (n == 0)
        {
            n++;
            continue;
        }
        int i = 0;
        while (i < s.size())
        {
            string st = "";
            int j = i;
            while (s[j] != ':' && j < s.size())
            {
                // if(s[j] != ' ') {  Tai sao van bi dinh dau cach khi dung cau lenh nay
                if ((s[j] >= '0' && s[j] <= '9') || (s[j] >= 'a' && s[j] <= 'z') || (s[j] >= 'A' && s[j] <= 'Z'))
                {
                    st = st + s[j];
                }
                j++;
            }
            if (j < s.size())
                MarkMF[p] = st;
            else
                NameMF[p] = st;
            i = j + 1;
        }
        p++;
    }
    fileInput.close();
    SizeMF = p;
}

void SuppliesManage::addMarkUnit() {
    string markUnit , nameUnit;
    Functions::gotoxy(75 , 3); cout << "Moi ban nhap ki hieu don vi moi : ";
    cin >> markUnit;
    while(Functions::getUnitOfSupps(markUnit) != "") {
        Functions::gotoxy(75 , 5); cout << "                                                                                           ";
        Functions::gotoxy(75 , 5); cout << "Ma ban nhap da co san , moi ban nhap lai : "; 
        cin >> markUnit;
    }
    Functions::gotoxy(75 , 7); cout << "Moi ban nhap ten cho don vi moi : ";
    cin >> nameUnit;
    ofstream fileOut;
    fileOut.open("Unit.txt" , ios::app);
    fileOut << "\t" << left << setw(12) << markUnit << ":" << left << "    " << nameUnit << '\n';
    fileOut.close();
}

void SuppliesManage::addMarkTypeOFSupp() {
    string markTypeOFSup , nameTypeOFSup;
    Functions::gotoxy(75 , 3); cout << "Moi ban nhap ki hieu loai vat tu moi : ";
    cin >> markTypeOFSup;
    while(Functions::getKindOfSupps(markTypeOFSup) != "") {
        Functions::gotoxy(75 , 5); cout << "                                                                                           ";
        Functions::gotoxy(75 , 5); cout << "Ma ban nhap da co san , moi ban nhap lai : "; 
        cin >> markTypeOFSup;
    }
    Functions::gotoxy(75 , 7); cout << "Moi ban nhap ten cho loai vat tu moi : ";
    cin >> nameTypeOFSup;
    ofstream fileOut;
    fileOut.open("Supplies.txt" , ios::app);
    fileOut << "\t" << left << setw(12) << markTypeOFSup << ":" << "   " << nameTypeOFSup << '\n';
    fileOut.close();
}

void SuppliesManage::addMarkMK() {
    this->SizeMF++;
    int check = 0;
    string s1 , s2;
    int i = 0;
    Functions::gotoxy(75 , 5); cout << "Moi ban nhap ki hieu nha san xuat moi : ";
    cin >> s1;
    while(Functions::getManufacturers(s1) != "") {
        Functions::gotoxy(75 , 7); cout << "                                                                                           ";
        Functions::gotoxy(75 , 7); cout << "Ki hieu ban nhap da co san , moi ban nhap lai : "; 
        cin >> s1;
    }
    Functions::gotoxy(75 , 9); cout << "Moi ban nhap ten nha san xuat moi : ";
    cin >> s2;
    this->MarkMF[this->SizeMF - 1] = s1;
    this->NameMF[this->SizeMF - 1] = s2;
    ofstream fileOut;
    fileOut.open("Manufacturers.txt" , ios::app);
    fileOut << "\t" << left << setw(12) << s1 << ":" << "   " << s2 << '\n';
    fileOut.close();
}
void SuppliesManage::addSups(Supplies s)
{
    for (int i = 0; i < this->sups.getSize(); ++i)
    {
        if (this->sups[i].getSuppliesCode() == s.getSuppliesCode())
        {
            this->sups[i].setAmount(this->sups[i].getAmount() + s.getAmount());
            return;
        }
    }
    this->sups.push_back(s);
}

void SuppliesManage::addEd(EntryDate e)
{
    for (int i = 0; i < this->ed.getSize(); ++i)
        if (this->ed[i].getTime() == e.getTime())
        {
            for (int j = 0; j < e.getSup().getSize(); ++j)
            {
                bool kt = 0;
                for (int k = 0; k < this->ed[i].getSup().getSize(); ++k)
                {
                    if (this->ed[i].getSup()[k].getSuppliesCode() == e.getSup()[j].getSuppliesCode())
                    {
                        this->ed[i].getSup()[k].setAmount(this->ed[i].getSup()[k].getAmount() + e.getSup()[j].getAmount());
                        kt = 1;
                        break;
                    }
                }
                if (kt == 0)
                    this->ed[i].addSupplies(e.getSup()[j]);
            }
            return;
        }
    this->ed.push_back(e);
    return;
}

Vector<Supplies> &SuppliesManage::getSups()
{
    return this->sups;
}

Vector<EntryDate> &SuppliesManage::getEd()
{
    return this->ed;
}

void SuppliesManage::addTestEnDate(Vector<string> &SS)
{
    int n = 0;
    string s;
    Vector<Supplies> temp1;
    while (n < SS.getSize())
    {
        s = SS[n];
        if (n != 0)
        {
            EntryDate e;
            Supplies supplie;
            int vt = 0;
            int check = 1;
            while (vt < s.size())
            {
                int p = vt;
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
                    e.setTime(st);
                    check++;
                    break;
                case 2:
                    supplie.setSuppliesCode(st);
                    check++;
                    break;
                case 3:
                    supplie.setAmount(Functions::Change(st));
                    check++;
                    break;
                case 4:
                    supplie.setSuppliesMa(st);
                    check++;
                    break;
                default:
                    break;
                }
                vt = p + 1;
            }
            e.addSupplies(supplie);
            int kkt = 0;
            for (int i = 0; i < this->ed.getSize(); ++i)
                if (this->ed[i].getTime() == e.getTime())
                {
                    temp1 = e.getSup();
                    for (int j = 0; j < temp1.getSize(); ++j)
                    {
                        bool kt = 0;
                        for (int k = 0; k < this->ed[i].getSup().getSize(); ++k)
                        {
                            if (this->ed[i].getSup()[k].getSuppliesCode() == temp1[j].getSuppliesCode() && this->ed[i].getSup()[k].getSuppliesMa() == temp1[j].getSuppliesMa())
                            {
                                this->ed[i].getSup()[k].setAmount(this->ed[i].getSup()[k].getAmount() + temp1[j].getAmount());
                                kt = 1;
                                break;
                            }
                        }
                        if (kt == 0)
                        {
                            this->ed[i].getSup().push_back(temp1[j]);
                        }
                    }
                    kkt = 1;
                    break;
                }
            if (kkt == 0)
                this->ed.push_back(e);
        }
        n++;
    }
}

void SuppliesManage::currentEntryDate()
{
    Vector<string> S;
    string s;
    ifstream inputFile2("EntryDate.txt");
    while (getline(inputFile2, s))
    {
        S.push_back(s);
    }
    inputFile2.close();
    this->addTestEnDate(S);
}

void SuppliesManage::input()
{
    Vector<string> S;
    string s;
    ifstream inputFile1("input.txt");
    while (getline(inputFile1, s))
    {
        S.push_back(s);
    }
    inputFile1.close();
    this->addTestEnDate(S);
}

// Ham nay can fix lai !!!
void SuppliesManage::SortEntryDate(int l, int r)
{
    int i = l, j = r;
    EntryDate p = this->ed[(l + r) / 2];
    EntryDate temp;
    while (i < j)
    {
        while (Functions::conpare(this->ed[i].getTime(), p.getTime()) == 2)
            i++;
        while (Functions::conpare(this->ed[j].getTime(), p.getTime()) == 1)
            j--;
        if (i <= j)
        {
            // cout << this->ed[j].getTime() << " " << this->ed[i].getTime() << endl;
            temp = this->ed[i];
            this->ed[i] = this->ed[j];
            this->ed[j] = temp;
            // cout << temp.getTime() << endl;
            //  cout << this->ed[j].getTime() << " " << this->ed[i].getTime() << endl;
            i++;
            j--;
            // cout << endl;
        }
    }
    if (i < r)
        this->SortEntryDate(i, r);
    if (j > l)
        this->SortEntryDate(l, j);
}

void SuppliesManage::currentStorage()
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

void SuppliesManage::updateListEd()
{
    // this->SortEntryDate(0 , this->ed.getSize() - 1);
    ofstream outFile;
    outFile.open("EntryDate.txt", ios::trunc);
    outFile << "|   Ngày Nhập    |    Mã vật tư     |    Số lượng     |    Mã NSX    |" << '\n';

    for (int i = 0; i < this->ed.getSize(); ++i)
    {
        if (this->ed[i].getSup().getSize() > 0)
        {
            for (int j = 0; j < this->ed[i].getSup().getSize(); ++j)
            {
                outFile << setw(15) << left << this->ed[i].getTime() << "  ,  ";
                outFile << setw(14) << left << this->ed[i].getSup()[j].getSuppliesCode() << "  ,  ";
                outFile << setw(13) << left << this->ed[i].getSup()[j].getAmount() << "  ,  ";
                outFile << this->ed[i].getSup()[j].getSuppliesMa() << '\n';
            }
        }
    }
    outFile.close();
    if (outFile.is_open())
        outFile.close();
}

void SuppliesManage::updateStorage()
{
    ofstream outFile1;
    outFile1.open("Storage.txt", ios::trunc);
    outFile1 << "|   Mã vật tư   |   Tên vật tư  |  Mã Loại vật tư |    Số lượng     |   Đơn giá | Mã đơn vị |" << '\n';
    for (int i = 0; i < this->sups.getSize(); ++i)
    {
        outFile1 << "    " << setw(11) << left << this->sups[i].getSuppliesCode() << " , ";
        outFile1 << setw(13) << left << this->sups[i].getSuppliesName() << " , ";
        outFile1 << setw(15) << left << this->sups[i].getKOSupplies() << " , ";
        outFile1 << setw(15) << left << this->sups[i].getAmount() << " , ";
        outFile1 << setw(9) << left << this->sups[i].getSuppliesPrice() << " , ";
        outFile1 << setw(8) << left << this->sups[i].getSuppliesUnit();
        outFile1 << '\n';
    }
    outFile1.close();
    if (outFile1.is_open())
        outFile1.close();
}

void SuppliesManage::addNewData()
{
    int currentY = Functions::getY();
    this->input();
    int n = 0;
    string sss;
    ifstream inputFile3("input.txt");
    while (getline(inputFile3, sss))
    {
        if (n != 0)
        {
            int i = 0;
            int check = 0;
            Supplies su;
            int New = 0;
            int count;
            while (i < sss.size())
            {
                int p = i;
                string st = "";
                while (p < sss.size() && sss[p] != ',')
                {
                    if (sss[p] != ' ')
                        st = st + sss[p];
                    p++;
                }
                switch (check)
                {
                case 0:
                    check++;
                    break;
                case 1:
                    count = 0;
                    for (int j = 0; j < this->sups.getSize(); ++j)
                        if (this->sups[j].getSuppliesCode() == st)
                            break;
                        else
                            count++;
                    if (count == this->sups.getSize())
                        New = 1;
                    su.setSuppliesCode(st);
                    check++;
                    break;
                case 2:
                    su.setAmount(Functions::Change(st));
                    check++;
                    break;
                default:
                    break;
                }
                i = p + 1;
            }
            if (New == 1)
            {   
                for(int currentY = 3; currentY < 40; currentY++) {
                    Functions::gotoxy(75, currentY); cout << "                                                                                                               ";
                }
                Functions::gotoxy(75, 3); cout << "Ban da them ma vat tu moi khong co trong kho , moi ban them thong tin ve vat tu " << su.getSuppliesCode() << '!';
                cin >> su;
            }
            (*this).addSups(su);
        }
        n++;
    }
    inputFile3.close();
    this->updateStorage();
    this->updateListEd();
}

void SuppliesManage::deleteSupplies(string st)
{
    this->checkSupplies(st);
    for (int i = 0; i < this->sups.getSize(); ++i)
        if (this->sups[i].getSuppliesCode() == st)
        {
            this->sups.erase(i);
            break;
        }
    for (int i = 0; i < this->ed.getSize(); ++i)
    {
        int j = 0;
        int check = 0;
        do
        {
            int size = this->ed[i].getSup().getSize() - 1;
            while (j <= size)
            {
                if (this->ed[i].getSup()[j].getSuppliesCode() == st)
                {
                    this->ed[i].getSup().erase(j);
                    check = 1;
                    j = 0;
                    break;
                }
                j++;
            }
            if (j != 0 || size < 0)
                check = 0;
        } while (check == 1);
        // if(this->ed[i].getSup().getSize() == 0) this->ed.erase(i);
    }
    int i = 0;
    int check = 0;
    do
    {
        int size = this->ed.getSize();
        while (i < size)
        {
            if (this->ed[i].getSup().getSize() == 0)
            {
                this->ed.erase(i);
                i = 0,
                check = 1;
                break;
            }
            i++;
        }
        if (size == 0 || i != 0)
            check = 0;
    } while (check == 1);
    this->updateStorage();
    this->updateListEd();
}

void SuppliesManage::deleteSupplies100()
{
    int i = 0;
    int check = 0;
    do
    {
        int size = this->sups.getSize();
        while (i < size)
        {
            if (this->sups[i].getAmount() > 100)
            {
                // cout << sups[i].getSuppliesCode() << '\n';
                for (int j = 0; j < this->ed.getSize(); ++j)
                {
                    int k = 0;
                    int checkk = 0;
                    do
                    {
                        int sizek = this->ed[j].getSup().getSize();
                        while (k < sizek)
                        {
                            if (this->sups[i].getSuppliesCode() == this->ed[j].getSup()[k].getSuppliesCode())
                            {
                                checkk = 1;
                                k = 0;
                                this->ed[j].getSup().erase(k);
                                break;
                            }
                            k++;
                        }
                        if (k != 0 || sizek == 0)
                            checkk = 0;
                    } while (checkk == 1);
                }
                int j = 0;
                int checkj = 0;
                do
                {
                    int sizej = this->ed.getSize();
                    while (j < sizej)
                    {
                        if (this->ed[j].getSup().getSize() == 0)
                        {
                            this->ed.erase(j);
                            j = 0,
                            checkj = 1;
                            break;
                        }
                        j++;
                    }
                    if (sizej == 0 || j != 0)
                        checkj = 0;
                } while (checkj == 1);
                check = 1;
                this->sups.erase(i);
                i = 0;
                break;
            }
            i++;
        }
        if (i != 0 || size == 0)
            check = 0;

    } while (check == 1);
    this->updateStorage();
    this->updateListEd();
}

void SuppliesManage::FindSupplies()
{
    string yourChoice;
    int pos = this->checkSupplies(yourChoice);
    Functions::gotoxy(75, 12); cout << "Duoi day la cac thong tin ve Vat Tu " << yourChoice << " !!!";
    Functions::gotoxy(75, 14); cout << "Ma Vat Tu   : " << yourChoice << endl;
    Functions::gotoxy(75, 16); cout << "Ten Vat Tu  : " << sups[pos].getSuppliesName() << endl;
    string str = this->sups[pos].getKOSupplies();
    Functions::gotoxy(75, 18); cout << "Loai Vat Tu : " << Functions::getKindOfSupps(this->sups[pos].getKOSupplies()) << endl;
    Functions::gotoxy(75, 20); cout << "So luong    : " << sups[pos].getAmount() << endl;
    Functions::gotoxy(75, 22); cout << "Gia         : " << sups[pos].getSuppliesPrice() << endl;
    Functions::gotoxy(75, 24); cout << "Don vi      : " << Functions::getUnitOfSupps(this->sups[pos].getSuppliesUnit()) << endl;
    Functions::gotoxy(75, 26); cout << "Cac nha san xuat cung cap vat tu " << yourChoice << " la : ";
    for(int i = 0 ; i < this->ed.getSize() ; ++i) {
        for(int j = 0 ; j < this->ed[i].getSup().getSize() ; ++j) {
            int check = 0;
            int count = 0;
            if(this->ed[i].getSup()[j].getSuppliesCode() == yourChoice) {
                for(int k = 0 ; k < this->SizeMF ; ++k)
                    if(this->ed[i].getSup()[k].getSuppliesMa() == this->MarkMF[k]) {
                        if(count == 0) cout << this->NameMF[k];
                        else cout << "    ,    " << this->NameMF[k];
                        check = 1;
                        count++;
                        break;
                    }
            }
            if(check == 1) break;
        }
    }
    Functions::gotoxy(75, 28);
}

void SuppliesManage::SortStorage(const int &x, const int &y, int l, int r)
{
    int i = l, j = r;
    Supplies p = this->sups[(l + r) / 2];
    while (i < j)
    {
        switch (x)
        {
        case 1:
            if (y == 1)
            {
                while (Functions::compareString(this->sups[i].getSuppliesCode(), p.getSuppliesCode()) == 2)
                    i++;
                while (Functions::compareString(this->sups[j].getSuppliesCode(), p.getSuppliesCode()) == 1)
                    j--;
            }
            else if (y == 2)
            {
                while (Functions::compareString(this->sups[i].getSuppliesCode(), p.getSuppliesCode()) == 1)
                    i++;
                while (Functions::compareString(this->sups[j].getSuppliesCode(), p.getSuppliesCode()) == 2)
                    j--;
            }
            break;
        case 2:
            if (y == 1)
            {
                while (Functions::compareString(this->sups[i].getSuppliesName(), p.getSuppliesName()) == 2)
                    i++;
                while (Functions::compareString(this->sups[j].getSuppliesName(), p.getSuppliesName()) == 1)
                    j--;
            }
            else if (y == 2)
            {
                while (Functions::compareString(this->sups[i].getSuppliesName(), p.getSuppliesName()) == 1)
                    i++;
                while (Functions::compareString(this->sups[j].getSuppliesName(), p.getSuppliesName()) == 2)
                    j--;
            }
            break;
        case 3:
            if (y == 1)
            {
                while (Functions::compareString(this->sups[i].getKOSupplies(), p.getKOSupplies()) == 2)
                    i++;
                while (Functions::compareString(this->sups[j].getKOSupplies(), p.getKOSupplies()) == 1)
                    j--;
            }
            else if (y == 2)
            {
                while (Functions::compareString(this->sups[i].getKOSupplies(), p.getKOSupplies()) == 1)
                    i++;
                while (Functions::compareString(this->sups[j].getKOSupplies(), p.getKOSupplies()) == 2)
                    j--;
            }
            break;
        case 4:
            if (y == 1)
            {
                while (this->sups[i].getAmount() < p.getAmount())
                    i++;
                while (this->sups[j].getAmount() > p.getAmount())
                    j--;
            }
            else if (y == 2)
            {
                while (this->sups[i].getAmount() > p.getAmount())
                    i++;
                while (this->sups[j].getAmount() < p.getAmount())
                    j--;
            }
            break;
        case 5:
            if (y == 1)
            {
                while (this->sups[i].getSuppliesPrice() < p.getSuppliesPrice())
                    i++;
                while (this->sups[j].getSuppliesPrice() > p.getSuppliesPrice())
                    j--;
            }
            else if (y == 2)
            {
                while (this->sups[i].getSuppliesPrice() > p.getSuppliesPrice())
                    i++;
                while (this->sups[j].getSuppliesPrice() < p.getSuppliesPrice())
                    j--;
            }
            break;
        default:
            break;
        }
        if (i <= j)
        {
            // cout << i << " " << j << '\n';
            Supplies temp = this->sups[i];
            this->sups[i] = this->sups[j];
            this->sups[j] = temp;
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

void SuppliesManage::InsertStorage(Supplies su, int index, const int &x)
{   
    int currentX;
    int currentY = Functions::getY() + 1;
    while (index < 0 || index > this->sups.getSize())
    {
        Functions::gotoxy(75, currentY++); cout << "Ban da them vao vi tri qua do dai trong kho moi ban nhap lai : ";
        cin >> index;
    }
    this->sups.insert(su, index);
    time_t time_now = time(NULL);
    struct tm *time_info = localtime(&time_now);             // Chuyển time_t sang struct tm.
    char buffer[80];                                         // Chuỗi ký tự để chứa ngày đã định dạng.
    strftime(buffer, sizeof(buffer), "%d/%m/%Y", time_info); // Định dạng ngày tháng.
    string date_str(buffer);                                 // Gán chuỗi ký tự vào std::string.
    EntryDate e;
    e.setTime(date_str);
    e.addSupplies(su);
    // this->addEd(e); Tại sao lại không sử dụng được ???
    this->ed.push_back(e);
    if (x == 1)
    {
        int y, z;
        Functions::gotoxy(75, currentY++); cout << "- Sap xep theo ma vat tu nhap phim 1";
        Functions::gotoxy(75, currentY++); cout << "- Sap xep theo ten vat tu nhap phim 2";
        Functions::gotoxy(75, currentY++); cout << "- Sap xep theo loai vat tu nhap phim 3";
        Functions::gotoxy(75, currentY++); cout << "- Sap xep theo so luong vat tu nhap phim 4";
        Functions::gotoxy(75, currentY++); cout << "- Sap xep theo gia vat tu nhap phim 5";
        Functions::gotoxy(75, currentY++); cout << "Moi ban nhap : ";
        cin >> y;
        Functions::gotoxy(75, currentY++); cout << "Ban muon sap xep giam dan hay tang dan ?";
        Functions::gotoxy(75, currentY++); cout << " - Nhap phim 1 neu muon tang dan";
        Functions::gotoxy(75, currentY++); cout << " - Nhap phim 2 neu muon giam dan";
        Functions::gotoxy(75, currentY++); cout << "Moi ban nhap : ";
        cin >> z; // Code giao diện để người dùng muốn sort theo kiểu nào
        this->SortStorage(y, z, 0, this->sups.getSize() - 1);
    }
    this->updateStorage();
    this->updateListEd();
}

void SuppliesManage::show()
{
    // in ra terminal
    int pos = 4;
    Functions::gotoxy(75, 3); cout << "|  Ma Vat Tu     |	 So Luong	  |	  Tong Tien	  |";
    for (int i = 0; i < this->sups.getSize(); ++i)
    {
        Functions::gotoxy(75, pos++);
        cout << "     " << setw(12) << left << this->sups[i].getSuppliesCode();
        cout << "|       " << setw(14) << left << this->sups[i].getAmount();
        cout << "|	   " << this->sups[i].GetTotalCost();
    }
    Functions::gotoxy(75, pos++ + 5);
    ofstream fileOut;
    fileOut.open("Result.txt", ios::trunc);
    fileOut << "|  Mã vật tư	     |	Số lượng	  |	  Tổng tiền	  |" << '\n';
    for (int i = 0; i < this->sups.getSize(); ++i)
    {
        fileOut << "   " << setw(13) << left << this->sups[i].getSuppliesCode();
        fileOut << "		   " << setw(10) << left << this->sups[i].getAmount();
        fileOut << "	     " << this->sups[i].GetTotalCost() << '\n';
    }
    fileOut.close();
}

void SuppliesManage::showAll()
{
    Functions::gotoxy(75, 3); cout << "Bang Vat Tu do CTTNHH2TV THAOTHANH phat trien\n";
    Functions::gotoxy(75, 4); cout << "|   Ma Vat Tu   |   Ten Vat Tu  |   Loai Vat Tu  |    So Luong    |   Don Gia  | Don Vi  |  Tong Tien  |";
    int pos = 5;
    for (int i = 0; i < this->sups.getSize(); ++i)
    {
        Functions::gotoxy(75, pos);
        cout << "|     " << left << setw(10) << this->sups[i].getSuppliesCode() << "|";
        cout << left << "     " << setw(10) << this->sups[i].getSuppliesName() << "|";
        cout << left << "" << setw(16) << Functions::getKindOfSupps(this->sups[i].getKOSupplies()) << "|";
        cout << left << "      " << setw(10) << this->sups[i].getAmount() << "|";
        cout << "    " << left << setw(8) << this->sups[i].getSuppliesPrice() << "|";
        cout << "   " << left << setw(6) << Functions::getUnitOfSupps(this->sups[i].getSuppliesUnit()) << "|";
        cout << "   " << left << setw(10) << this->sups[i].GetTotalCost() << "|";
        pos++;
    }
    Functions::gotoxy(75, pos);
}

void SuppliesManage::exportSupplies(const string &SuppliesCode, int &amount, const int &p)
{
    if (this->sups[p].getAmount() < amount || amount < 0)
    {
        int currentY = Functions::getY();
        int currentX = Functions::getX();
        cout << "Hien tai trong kho vat tu co ma " << this->sups[p].getSuppliesCode() << " Chi co so luong la : " << this->sups[p].getAmount();
        while (amount > this->sups[p].getAmount())
        {
            Functions::gotoxy(currentX, currentY + 1); cout << "                                                                                                        ";
            Functions::gotoxy(currentX, currentY + 1); cout << "Ban da nhap qua so luong cho phep moi ban nhap lai : ";
            cin >> amount;
        }
    }
    this->sups[p].setAmount(this->sups[p].getAmount() - amount);
}

Vector<EntryDate> SuppliesManage::getExportDate()
{
    Vector<EntryDate> result;
    Vector<string> S;
    string s;
    Vector<Supplies> temp1;
    ifstream inputFile1("ExportDate.txt");
    while (getline(inputFile1, s))
    {
        S.push_back(s);
    }
    inputFile1.close();
    int n = 0;
    while (n < S.getSize())
    {
        s = S[n];
        if (n != 0)
        {
            EntryDate e;
            Supplies supplie;
            int vt = 0;
            int check = 1;
            while (vt < s.size())
            {
                int p = vt;
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
                    e.setTime(st);
                    check++;
                    break;
                case 2:
                    supplie.setSuppliesCode(st);
                    check++;
                    break;
                case 3:
                    supplie.setAmount(Functions::Change(st));
                    check++;
                    break;
                case 4:
                    supplie.setSuppliesPrice(Functions::Change(st));
                    check++;
                    break;
                default:
                    break;
                }
                vt = p + 1;
            }
            e.addSupplies(supplie);
            int kkt = 0;
            for (int i = 0; i < result.getSize(); ++i)
                if (result[i].getTime() == e.getTime())
                {
                    temp1 = e.getSup();
                    for (int j = 0; j < temp1.getSize(); ++j)
                    {
                        bool kt = 0;
                        for (int k = 0; k < result[i].getSup().getSize(); ++k)
                        {
                            if (result[i].getSup()[k].getSuppliesCode() == temp1[j].getSuppliesCode() && result[i].getSup()[k].getSuppliesMa() == temp1[j].getSuppliesMa())
                            {
                                result[i].getSup()[k].setAmount(result[i].getSup()[k].getAmount() + temp1[j].getAmount());
                                result[i].getSup()[k].setSuppliesPrice(result[i].getSup()[k].getSuppliesPrice() + temp1[j].getSuppliesPrice());
                                kt = 1;
                                break;
                            }
                        }
                        if (kt == 0)
                        {
                            result[i].getSup().push_back(temp1[j]);
                        }
                    }
                    kkt = 1;
                    break;
                }
            if (kkt == 0)
                result.push_back(e);
        }
        n++;
    }
    return result;
}

void SuppliesManage::statisticsTypeofSupplies()
{
    ofstream outFile;
    Vector<Supplies> typeOfSupplies;
    for (int i = 0; i < this->sups.getSize(); ++i)
    {
        int check = 0;
        for (int j = 0; j < typeOfSupplies.getSize(); ++j)
            if (this->sups[i].getKOSupplies() == typeOfSupplies[j].getKOSupplies())
            {
                typeOfSupplies[j].setAmount(typeOfSupplies[j].getAmount() + this->sups[i].getAmount());
                typeOfSupplies[j].setSuppliesPrice(typeOfSupplies[j].getSuppliesPrice() + this->sups[i].getSuppliesPrice() * this->sups[i].getAmount());
                check = 1;
                break;
            }
        if (check == 0)
            typeOfSupplies.push_back(this->sups[i]);
    }
    //in ra terminal
    int pst = 4;
    Functions::gotoxy(75, 3); cout << "|  Ma loai vat tu |    Tong so luong    |   Tong gia tien  |";
    for (int i = 0; i < typeOfSupplies.getSize(); ++i)
    {
        Functions::gotoxy(75, pst++); 
        cout << left << " " << setw(16) << Functions::getKindOfSupps(typeOfSupplies[i].getKOSupplies()) << " | ";
        cout << left << "    " << setw(15) << typeOfSupplies[i].getAmount() << " | ";
        cout << "    " << left << setw(13) << typeOfSupplies[i].getSuppliesPrice();
    }
    Functions::gotoxy(75, pst++ + 5);

    // file
    outFile.open("Bangthongke.txt", ios::trunc);
    outFile << "|  Mã Loại vật tư |    Tổng số lượng     |   Tổng giá tiền  |" << '\n';
    for (int i = 0; i < typeOfSupplies.getSize(); ++i)
    {
        outFile << left << " " << setw(16) << Functions::getKindOfSupps(typeOfSupplies[i].getKOSupplies()) << " , ";
        outFile << left << "      " << setw(15) << typeOfSupplies[i].getAmount() << " , ";
        outFile << "    " << left << setw(13) << typeOfSupplies[i].getSuppliesPrice() << '\n';
    }
    outFile.close();
}

void SuppliesManage::showUnit()
{
    ifstream input_file;
    string s;
    Functions::gotoxy(75, 4); cout << "|   Ma don vi    |    Ten don vi   |";
    int pos = 5;
    int count = 0;
    input_file.open("Unit.txt", ios::in);
    while (getline(input_file, s))
    {
        if (count != 0)
        {
            Functions::gotoxy(75, pos++); cout << s;
        }
        count++;
    }
    input_file.close();
}

void SuppliesManage::showKOSups()
{
    ifstream input_file;
    string s;
    Functions::gotoxy(75, 4); cout << "|   Loai vat tu  |    Ten loai vat tu   |";
    int pos = 5;
    int count = 0;
    input_file.open("Supplies.txt", ios::in);
    while (getline(input_file, s))
    {
        if (count != 0)
        {
            Functions::gotoxy(75, pos++); cout << s;
        }
        count++;
    }
    input_file.close();
}