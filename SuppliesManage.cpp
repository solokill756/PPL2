#include "SuppliesManage.h"

SuppliesManage::SuppliesManage()
{
    this->PutKOSupply();
    this->putUnit();
    this->PutMark();
    this->currentEntryDate();
}

SuppliesManage::~SuppliesManage()
{
}

Storage& SuppliesManage::getStorage()
{
    return this->kho;
}

void SuppliesManage::PutMark()
{
    Manufacturer temp;
    int SizeMF;
    string MarkMF[N + 1];
    string NameMF[N + 1];
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
    for(int i = 0; i < SizeMF; i++)
    {
        temp.setManufacturer(MarkMF[i]);
        temp.setNameMF(NameMF[i]);
        mf.push_back(temp);
    }
}

void SuppliesManage::putUnit() {
    unit temp;
    int SizeMF;
    string MarkMF[N + 1];
    string NameMF[N + 1];
    int n, p;
    ifstream fileInput;
    string s;
    // Lay du lieu tu file Manufacturers.txt
    fileInput.open("Unit.txt", ios::in);
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
    for(int i = 0; i < SizeMF; i++)
    {
        temp.setSuppliesUnit(MarkMF[i]);
        temp.setNameUnit(NameMF[i]);
        un.push_back(temp);
    }
}

void SuppliesManage::PutKOSupply()
{
    KOsupply temp;
    int SizeMF;
    string MarkMF[N + 1];
    string NameMF[N + 1];
    int n, p;
    ifstream fileInput;
    string s;
    // Lay du lieu tu file Manufacturers.txt
    fileInput.open("Supplies.txt", ios::in);
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
    for(int i = 0; i < SizeMF; i++)
    {
        temp.setSuppliesCode(MarkMF[i]);
        temp.setNameSup(NameMF[i]);
        ko.push_back(temp);
    }
}

void SuppliesManage::addMarkUnit() {
    string markUnit , nameUnit;
    Functions::gotoxy(75 , 3); cout << "Moi ban nhap ki hieu don vi moi : ";
    cin >> markUnit;
    while(this->getUnitOfSupps(markUnit) != "") {
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
    while(this->getKindOfSupps(markTypeOFSup) != "") {
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
    Manufacturer temp;
    int check = 0;
    string s1 , s2;
    int i = 0;
    Functions::gotoxy(75 , 5); cout << "Moi ban nhap ki hieu nha san xuat moi : ";
    cin >> s1;
    while(this->getManufacturers(s1) != "") {
        Functions::gotoxy(75 , 7); cout << "                                                                                           ";
        Functions::gotoxy(75 , 7); cout << "Ki hieu ban nhap da co san , moi ban nhap lai : "; 
        cin >> s1;
    }
    Functions::gotoxy(75 , 9); cout << "Moi ban nhap ten nha san xuat moi : ";
    cin >> s2;
    temp.setManufacturer(s1);
    temp.setNameMF(s2);
    mf.push_back(temp);
    ofstream fileOut;
    fileOut.open("Manufacturers.txt" , ios::app);
    fileOut << "\t" << left << setw(12) << s1 << ":" << "   " << s2 << '\n';
    fileOut.close();
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
    return this->kho.getSups();
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
                    for (int j = 0; j < this->kho.getSups().getSize(); ++j)
                        if (this->kho.getSups()[j].getSuppliesCode() == st)
                            break;
                        else
                            count++;
                    if (count == this->kho.getSups().getSize())
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
            (*this).kho.addSups(su);
        }
        n++;
    }
    inputFile3.close();
    this->kho.updateStorage();
    this->updateListEd();
}

void SuppliesManage::deleteSupplies(string st)
{
    this->kho.checkSupplies(st);
    for (int i = 0; i < this->kho.getSups().getSize(); ++i)
        if (this->kho.getSups()[i].getSuppliesCode() == st)
        {
            this->kho.getSups().erase(i);
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
    this->kho.updateStorage();
    this->updateListEd();
}

void SuppliesManage::deleteSupplies100()
{
    int i = 0;
    int check = 0;
    do
    {
        int size = this->kho.getSups().getSize();
        while (i < size)
        {
            if (this->kho.getSups()[i].getAmount() > 100)
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
                            if (this->kho.getSups()[i].getSuppliesCode() == this->ed[j].getSup()[k].getSuppliesCode())
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
                this->kho.getSups().erase(i);
                i = 0;
                break;
            }
            i++;
        }
        if (i != 0 || size == 0)
            check = 0;

    } while (check == 1);
    this->kho.updateStorage();
    this->updateListEd();
}

void SuppliesManage::FindSupplies()
{
    string yourChoice;
    int pos = this->kho.checkSupplies(yourChoice);
    Functions::gotoxy(75, 12); cout << "Duoi day la cac thong tin ve Vat Tu " << yourChoice << " !!!";
    Functions::gotoxy(75, 14); cout << "Ma Vat Tu   : " << yourChoice << endl;
    Functions::gotoxy(75, 16); cout << "Ten Vat Tu  : " << kho.getSups()[pos].getSuppliesName() << endl;
    string str = this->kho.getSups()[pos].getKOSupplies();
    Functions::gotoxy(75, 18); cout << "Loai Vat Tu : " << this->getKindOfSupps(this->kho.getSups()[pos].getKOSupplies()) << endl;
    Functions::gotoxy(75, 20); cout << "So luong    : " << kho.getSups()[pos].getAmount() << endl;
    Functions::gotoxy(75, 22); cout << "Gia         : " << kho.getSups()[pos].getSuppliesPrice() << endl;
    Functions::gotoxy(75, 24); cout << "Don vi      : " << this->getUnitOfSupps(this->kho.getSups()[pos].getSuppliesUnit()) << endl;
    Functions::gotoxy(75, 26); cout << "Cac nha san xuat cung cap vat tu " << yourChoice << " la : ";
    Vector<string> tmp;
    string s;
    int lap = 0;
    int count = 0;
    for(int i = 0 ; i < this->ed.getSize() ; ++i) {
        for(int j = 0 ; j < this->ed[i].getSup().getSize() ; ++j) {
            int check = 0;
            if(this->ed[i].getSup()[j].getSuppliesCode() == yourChoice) {
                for(int k = 0 ; k < mf.getSize() ; ++k)
                    if(this->ed[i].getSup()[k].getSuppliesMa() == mf[k].getManufacturer()) {
                        s = this->ed[i].getSup()[k].getSuppliesMa();
                        for(int l = 0; l < tmp.getSize(); l++)
                        { 
                            if(tmp[l] == s) {
                                lap = 1;
                                break;
                            }
                        }
                        if(lap == 1) {
                            lap = 0;
                            break;
                        }
                        else 
                        {
                            tmp.push_back(mf[k].getManufacturer());
                            if(count == 0) cout << mf[k].getNameMF();
                            else cout << ", " << mf[k].getNameMF();
                            check = 1;
                            count++;
                            break;
                        }
                    }
            }
            if(check == 1) break;
        }
    }
    Functions::gotoxy(75, 28);
}



void SuppliesManage::InsertStorage(Supplies su, int index, const int &x)
{   
    int currentX;
    int currentY = Functions::getY() + 1;
    while (index < 0 || index > this->kho.getSups().getSize())
    {
        Functions::gotoxy(75, currentY++); cout << "Ban da them vao vi tri qua do dai trong kho moi ban nhap lai : ";
        cin >> index;
    }
    this->kho.getSups().insert(su, index);
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
        this->kho.SortStorage(y, z, 0, this->kho.getSups().getSize() - 1);
    }
    this->kho.updateStorage();
    this->updateListEd();
}

void SuppliesManage::show()
{
    // in ra terminal
    int pos = 4;
    Functions::gotoxy(75, 3); cout << "|  Ma Vat Tu     |	 So Luong	  |	  Tong Tien	  |";
    for (int i = 0; i < this->kho.getSups().getSize(); ++i)
    {
        Functions::gotoxy(75, pos++);
        cout << "     " << setw(12) << left << this->kho.getSups()[i].getSuppliesCode();
        cout << "|       " << setw(14) << left << this->kho.getSups()[i].getAmount();
        cout << "|	   " << this->kho.getSups()[i].GetTotalCost();
    }
    Functions::gotoxy(75, pos++ + 5);
    ofstream fileOut;
    fileOut.open("Result.txt", ios::trunc);
    fileOut << "|  Mã vật tư	     |	Số lượng	  |	  Tổng tiền	  |" << '\n';
    for (int i = 0; i < this->kho.getSups().getSize(); ++i)
    {
        fileOut << "   " << setw(13) << left << this->kho.getSups()[i].getSuppliesCode();
        fileOut << "		   " << setw(10) << left << this->kho.getSups()[i].getAmount();
        fileOut << "	     " << this->kho.getSups()[i].GetTotalCost() << '\n';
    }
    fileOut.close();
}

void SuppliesManage::showAll()
{
    Functions::gotoxy(75, 3); cout << "Bang Vat Tu do CTTNHH2TV THAOTHANH phat trien\n";
    Functions::gotoxy(75, 4); cout << "|   Ma Vat Tu   |   Ten Vat Tu  |   Loai Vat Tu  |    So Luong    |   Don Gia  | Don Vi  |  Tong Tien  |";
    int pos = 5;
    for (int i = 0; i < this->kho.getSups().getSize(); ++i)
    {
        Functions::gotoxy(75, pos);
        cout << "|     " << left << setw(10) << this->kho.getSups()[i].getSuppliesCode() << "|";
        cout << left << "     " << setw(10) << this->kho.getSups()[i].getSuppliesName() << "|";
        cout << left << "" << setw(16) << this->getKindOfSupps(this->kho.getSups()[i].getKOSupplies()) << "|";
        cout << left << "      " << setw(10) << this->kho.getSups()[i].getAmount() << "|";
        cout << "    " << left << setw(8) << this->kho.getSups()[i].getSuppliesPrice() << "|";
        cout << "   " << left << setw(6) << this->getUnitOfSupps(this->kho.getSups()[i].getSuppliesUnit()) << "|";
        cout << "   " << left << setw(10) << this->kho.getSups()[i].GetTotalCost() << "|";
        pos++;
    }
    Functions::gotoxy(75, pos);
}

void SuppliesManage::exportSupplies(const string &SuppliesCode, int &amount, const int &p)
{
    if (this->kho.getSups()[p].getAmount() < amount || amount < 0)
    {
        int currentY = Functions::getY();
        int currentX = Functions::getX();
        cout << "Hien tai trong kho vat tu co ma " << this->kho.getSups()[p].getSuppliesCode() << " Chi co so luong la : " << this->kho.getSups()[p].getAmount();
        while (amount > this->kho.getSups()[p].getAmount())
        {
            Functions::gotoxy(currentX, currentY + 1); cout << "                                                                                                        ";
            Functions::gotoxy(currentX, currentY + 1); cout << "Ban da nhap qua so luong cho phep moi ban nhap lai : ";
            cin >> amount;
        }
    }
    this->kho.getSups()[p].setAmount(this->kho.getSups()[p].getAmount() - amount);
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
    for (int i = 0; i < this->kho.getSups().getSize(); ++i)
    {
        int check = 0;
        for (int j = 0; j < typeOfSupplies.getSize(); ++j)
            if (this->kho.getSups()[i].getKOSupplies() == typeOfSupplies[j].getKOSupplies())
            {
                typeOfSupplies[j].setAmount(typeOfSupplies[j].getAmount() + this->kho.getSups()[i].getAmount());
                typeOfSupplies[j].setSuppliesPrice(typeOfSupplies[j].getSuppliesPrice() + this->kho.getSups()[i].getSuppliesPrice() * this->kho.getSups()[i].getAmount());
                check = 1;
                break;
            }
        if (check == 0)
            typeOfSupplies.push_back(this->kho.getSups()[i]);
    }
    //in ra terminal
    int pst = 4;
    Functions::gotoxy(75, 3); cout << "|  Ma loai vat tu |    Tong so luong    |   Tong gia tien  |";
    for (int i = 0; i < typeOfSupplies.getSize(); ++i)
    {
        Functions::gotoxy(75, pst++); 
        cout << left << " " << setw(16) << this->getKindOfSupps(typeOfSupplies[i].getKOSupplies()) << " | ";
        cout << left << "    " << setw(15) << typeOfSupplies[i].getAmount() << " | ";
        cout << "    " << left << setw(13) << typeOfSupplies[i].getSuppliesPrice();
    }
    Functions::gotoxy(75, pst++ + 5);

    // file
    outFile.open("Bangthongke.txt", ios::trunc);
    outFile << "|  Mã Loại vật tư |    Tổng số lượng     |   Tổng giá tiền  |" << '\n';
    for (int i = 0; i < typeOfSupplies.getSize(); ++i)
    {
        outFile << left << " " << setw(16) << this->getKindOfSupps(typeOfSupplies[i].getKOSupplies()) << " , ";
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

string SuppliesManage::getKindOfSupps(const string& str)
{
    for(int i = 0; i < ko.getSize(); i++)
    {
        if(ko[i].getSuppliesCode() == str)
            return ko[i].getNameSup();
    }
    return "";
}

string SuppliesManage::getUnitOfSupps(const string& str)
{
    for(int i = 0; i < un.getSize(); i++)
    {
        if(un[i].getSuppliesUnit() == str)
            return un[i].getNameUnit();
    }
    return "";
}

string SuppliesManage::getManufacturers(const string& str)
{
    for(int i = 0; i < mf.getSize(); i++)
    {
        if(mf[i].getManufacturer() == str)
            return mf[i].getNameMF();
    }
    return "";
}

void SuppliesManage::editSup()
{   
    Functions::gotoxy(75, 3); cout << "Cac ma vat tu da co trong kho la : ";
    Functions::gotoxy(75, 4); cout << "|| ";
    for (int it = 0; it < this->kho.getSups().getSize(); ++it)
    {
        cout << this->kho.getSups()[it].getSuppliesCode() << " || ";
    }
    string yourChoice;
    int pos = this->kho.checkSupplies(yourChoice);
    int currentX = Functions::getX();
    int currentY = Functions::getY();
    Functions::gotoxy(75, ++currentY); cout << "Ban muon sua thong tin gi cua vat tu " << this->kho.getSups()[pos].getSuppliesCode() << " : ";
    Functions::gotoxy(75, ++currentY); cout << "1. Sua ten vat tu";
    Functions::gotoxy(75, ++currentY); cout << "2. Sua ma loai vat tu";
    Functions::gotoxy(75, ++currentY); cout << "3. Sua ma loai don vi";
    int choice = 0;
    while(choice < 1 || choice > 3) {
        Functions::gotoxy(75, currentY + 1); cout << "                                                                                                   "; 
        Functions::gotoxy(75, currentY + 1); cout << "Ban chon: "; cin >> choice;
    }
    currentY++;
    if(choice == 1) {
        string newName;
        int check = 0;
        Functions::gotoxy(75, ++currentY); cout << "Thay doi ten vat tu co ma " << this->kho.getSups()[pos].getSuppliesCode() << " "; 
        Functions::gotoxy(75, ++currentY); cout << "Moi ban nhap ten moi : "; cin >> newName;
        while(check == 0)
        {   
            for(int i = 0 ; i < this->kho.getSups().getSize() ; ++i) 
                if(newName != this->kho.getSups()[i].getSuppliesName()) {
                    check++;
                }
            if(check != this->kho.getSups().getSize()) {
                check = 0;
                Functions::gotoxy(75, currentY + 2); cout << "                                                                                                        ";
                Functions::gotoxy(75, currentY + 1); cout << "Ten vat tu ban vua nhap da co san trong kho !";
                Functions::gotoxy(75, currentY + 2); cout << "Moi ban nhap lai : ";
                cin >> newName;
            }
            else break;
        }
        currentY += 3;
        this->kho.getSups()[pos].setSuppliesName(newName);
    }
    if(choice == 2) {
        string newKO;
        int check = 0;
        Functions::gotoxy(75, ++currentY); cout << "Thay doi ma loai vat tu cua vat tu co ma " << this->kho.getSups()[pos].getSuppliesCode() << " "; 
        Functions::gotoxy(75, ++currentY); cout << "Moi ban nhap ma loai vat tu moi : "; cin >> newKO;
        while(check == 0)
        {   
            for(int i = 0 ; i < this->ko.getSize() ; ++i) 
                if(newKO != this->ko[i].getSuppliesCode()) {
                    check++;
                }
            if(check != this->ko.getSize()) {
                break;
            }
            else {
                check = 0;
                Functions::gotoxy(75, currentY + 2); cout << "                                                                                                        ";
                Functions::gotoxy(75, currentY + 1); cout << "Ma loai vat tu ban vua nhap khong co trong kho !";
                Functions::gotoxy(75, currentY + 2); cout << "Moi ban nhap lai : ";
                cin >> newKO;
            }
        }
        currentY += 3;
        this->kho.getSups()[pos].setKOSupplies(newKO);
    }
    if(choice == 3) {
        string newUnit;
        int check = 0;
        Functions::gotoxy(75, ++currentY); cout << "Thay doi ma loai don vi cua vat tu co ma " << this->kho.getSups()[pos].getSuppliesCode() << " "; 
        Functions::gotoxy(75, ++currentY); cout << "Moi ban nhap ma loai don vi moi : "; cin >> newUnit;
        while(check == 0)
        {   
            for(int i = 0 ; i < this->un.getSize() ; ++i) 
                if(newUnit != this->un[i].getSuppliesUnit()) {
                    check++;
                }
            if(check != this->ko.getSize()) {
                break;
            }
            else {
                check = 0;
                Functions::gotoxy(75, currentY + 2); cout << "                                                                                                        ";
                Functions::gotoxy(75, currentY + 1); cout << "Ma loai don vi ban vua nhap khong co trong kho !";
                Functions::gotoxy(75, currentY + 2); cout << "Moi ban nhap lai : ";
                cin >> newUnit;
            }
        }
        currentY += 3;
        this->kho.getSups()[pos].setSuppliesUnit(newUnit);
    }
}

void SuppliesManage::editUnit()
{
    string newNameU;
    int check = 0;
    int pos;
    Functions::gotoxy(75, 3); cout << "Bang ma don vi da co : ";
    int currentY = Functions::getY();
    Functions::gotoxy(75, ++currentY); cout << "| ";
    for(int i = 0 ; i < this->un.getSize() ; ++i) 
    {
        cout << this->un[i].getSuppliesUnit() << " | ";
    }
    string yourChoice;
    Functions::gotoxy(75, currentY + 1); cout << "Ban muon doi ten ma loai don vi : "; cin >> yourChoice;
    while(check == 0)
    {
        for(int i = 0 ; i < this->un.getSize() ; ++i) 
        {
            if(yourChoice == this->un[i].getSuppliesUnit()) {
                check = 1;
                pos = i;
                break;
            }
        }
        if(check == 0) {
            Functions::gotoxy(75, currentY + 1); cout << "                                                                                          ";
            Functions::gotoxy(75, currentY + 1); cout << "Ban muon doi ten ma loai don vi : "; cin >> yourChoice;
        }
    }
    currentY++;
    Functions::gotoxy(75, ++currentY); cout << "Thay doi ten don vi cua ma don vi " << this->un[pos].getSuppliesUnit() << " "; 
    Functions::gotoxy(75, ++currentY); cout << "Moi ban nhap ten don vi moi : "; cin >> newNameU;
    check = 0;
    while(check == 0)
    {   
        for(int i = 0 ; i < this->un.getSize() ; ++i) 
            if(newNameU != this->un[i].getNameUnit()) {
                check++;
            }
        if(check != this->un.getSize()) {
            check = 0;
            Functions::gotoxy(75, currentY + 2); cout << "                                                                                                        ";
            Functions::gotoxy(75, currentY + 1); cout << "Ten don vi bi trung vui long nhap lai!";
            Functions::gotoxy(75, currentY + 2); cout << "Moi ban nhap lai : ";
            cin >> newNameU;
        }
        else {
            break;
        }
    }
    currentY += 3;
    this->un[pos].setNameUnit(newNameU);
    ofstream fileOut;
    fileOut.open("Unit.txt" , ios::trunc);
    fileOut << "|   Mã đơn vị   |   Tên đơn vị tính  |" << '\n';
    for(int i = 0; i < this->un.getSize(); i++) {
        fileOut << "\t" << left << setw(12) << this->un[i].getSuppliesUnit() << ":" << left << "    " << this->un[i].getNameUnit() << '\n';
    }
    fileOut.close();
}

void SuppliesManage::editManufacturer()
{
    string newNameMf;
    int check = 0;
    int pos;
    Functions::gotoxy(75, 3); cout << "Bang ma nha san xuat da co : ";
    int currentY = Functions::getY();
    Functions::gotoxy(75, ++currentY); cout << "| ";
    for(int i = 0 ; i < this->mf.getSize() ; ++i) 
    {
        cout << this->mf[i].getManufacturer() << " | ";
    }
    string yourChoice;
    Functions::gotoxy(75, currentY + 1); cout << "Ban muon doi ten ma nha san xuat : "; cin >> yourChoice;
    while(check == 0)
    {
        for(int i = 0 ; i < this->mf.getSize() ; ++i) 
        {
            if(yourChoice == this->mf[i].getManufacturer()) {
                check = 1;
                pos = i;
                break;
            }
        }
        if(check == 0) {
            Functions::gotoxy(75, currentY + 1); cout << "                                                                                          ";
            Functions::gotoxy(75, currentY + 1); cout << "Ban muon doi ten ma nha san xuat : "; cin >> yourChoice;
        }
    }
    currentY++;
    Functions::gotoxy(75, ++currentY); cout << "Thay doi ten nha san xuat cua ma nha san xuat " << this->mf[pos].getManufacturer() << " "; 
    Functions::gotoxy(75, ++currentY); cout << "Moi ban nhap ten nha san xuat moi : "; cin >> newNameMf;
    check = 0;
    while(check == 0)
    {   
        for(int i = 0 ; i < this->mf.getSize() ; ++i) 
            if(newNameMf != this->mf[i].getNameMF()) {
                check++;
            }
        if(check != this->mf.getSize()) {
            check = 0;
            Functions::gotoxy(75, currentY + 2); cout << "                                                                                                        ";
            Functions::gotoxy(75, currentY + 1); cout << "Ten nha san xuat bi trung vui long nhap lai!";
            Functions::gotoxy(75, currentY + 2); cout << "Moi ban nhap lai : ";
            cin >> newNameMf;
        }
        else {
            break;
        }
    }
    currentY += 3;
    this->mf[pos].setNameMF(newNameMf);
    ofstream fileOut;
    fileOut.open("Manufacturers.txt" , ios::trunc);
    fileOut << "|	Mã NSX		|	Tên NSX		|" << '\n';
    for(int i = 0; i < this->mf.getSize(); i++) {
        fileOut << "\t" << left << setw(12) << this->mf[i].getManufacturer() << ":" << "   " << this->mf[i].getNameMF() << '\n';
    }
    fileOut.close();
}
void SuppliesManage::editKOsup()
{
    string newNameKO;
    int check = 0;
    int pos;
    Functions::gotoxy(75, 3); cout << "Bang ma loai vat tu da co : ";
    int currentY = Functions::getY();
    Functions::gotoxy(75, ++currentY); cout << "| ";
    for(int i = 0 ; i < this->ko.getSize() ; ++i) 
    {
        cout << this->ko[i].getSuppliesCode() << " | ";
    }
    string yourChoice;
    Functions::gotoxy(75, currentY + 1); cout << "Ban muon doi ten ma loai vat tu : "; cin >> yourChoice;
    while(check == 0)
    {
        for(int i = 0 ; i < this->ko.getSize() ; ++i) 
        {
            if(yourChoice == this->ko[i].getSuppliesCode()) {
                check = 1;
                pos = i;
                break;
            }
        }
        if(check == 0) {
            Functions::gotoxy(75, currentY + 1); cout << "                                                                                          ";
            Functions::gotoxy(75, currentY + 1); cout << "Ban muon doi ten ma loai vat tu : "; cin >> yourChoice;
        }
    }
    currentY++;
    Functions::gotoxy(75, ++currentY); cout << "Thay doi ten loai vat tu cua ma loai vat tu " << this->ko[pos].getSuppliesCode() << " "; 
    Functions::gotoxy(75, ++currentY); cout << "Moi ban nhap ten loai vat tu moi : "; cin >> newNameKO;
    check = 0;
    while(check == 0)
    {   
        for(int i = 0 ; i < this->ko.getSize() ; ++i) 
            if(newNameKO != this->ko[i].getNameSup()) {
                check++;
            }
        if(check != this->ko.getSize()) {
            check = 0;
            Functions::gotoxy(75, currentY + 2); cout << "                                                                                                        ";
            Functions::gotoxy(75, currentY + 1); cout << "Ten loai vat tu bi trung vui long nhap lai!";
            Functions::gotoxy(75, currentY + 2); cout << "Moi ban nhap lai : ";
            cin >> newNameKO;
        }
        else {
            break;
        }
    }
    currentY += 3;
    this->ko[pos].setNameSup(newNameKO);
    ofstream fileOut;
    fileOut.open("Supplies.txt" , ios::trunc);
    fileOut << "|	Loại vật tư	|	Tên loại vật tư		|" << '\n';
    for(int i = 0; i < this->ko.getSize(); i++) {
        fileOut << "\t" << left << setw(12) << this->ko[i].getSuppliesCode() << ":" << "   " << this->ko[i].getNameSup() << '\n';
    }
    fileOut.close();
}