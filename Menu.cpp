#include "SuppliesManage.h"

void Menu()
{   
    Functions::setcolor(3);
    for(int j = 2; j <= 69; j++) 
    {
        Functions::gotoxy(j, 25); cout << static_cast<char>(205);
    }
    for(int j = 2; j <= 69; j++) 
    {
        Functions::gotoxy(j, 3); cout << static_cast<char>(205);
    }
    for(int j = 2; j <= 69; j++) 
    {
        Functions::gotoxy(j, 53); cout << static_cast<char>(205);
    }
    for(int i = 4; i <= 52; i++) 
    {
        Functions::gotoxy(2, i); cout << static_cast<char>(186);
    }
    for(int i = 4; i <= 52; i++) 
    {
        Functions::gotoxy(69, i); cout << static_cast<char>(186);
    }
    Functions::setcolor(4);
    Functions::gotoxy(69, 3); cout << static_cast<char>(187);
    Functions::gotoxy(69, 53); cout << static_cast<char>(188);
    Functions::gotoxy(2, 3); cout << static_cast<char>(201);
    Functions::gotoxy(2, 53); cout << static_cast<char>(200);
    Functions::setcolor(7);
    Functions::gotoxy(3, 5); cout << "****************************>> MENU <<****************************";
    Functions::setcolor(6);
    Functions::gotoxy(5, 8); cout << "1. Nhap thong tin vat tu";
    Functions::gotoxy(5, 11); cout << "2. Xuat vat tu";
    Functions::gotoxy(5, 14); cout << "3. Xoa vat tu";
    Functions::gotoxy(5, 17); cout << "4. Sap xep vat tu trong kho";
    Functions::gotoxy(5, 20); cout << "5. Tra cuu thong tin cac vat tu trong kho";
    Functions::gotoxy(5, 23); cout << "6. Thoat";
    Functions::setcolor(2);
}

void Case6(SuppliesManage &s) {};

void Case7(SuppliesManage &s)
{
    int currentY;
    s.addNewData();
    currentY = Functions::getY() + 1;
    Functions::gotoxy(75, currentY); cout << "Thao tac thanh cong!!";
    system("pause");
    system("cls");
}

void Case8(SuppliesManage &s)
{
    int currentY;
    string st;
    currentY = Functions::getY() + 1;
    s.deleteSupplies(st);
    Functions::gotoxy(75, currentY + 1); cout << "Thao tac thanh cong!!";
    system("pause");
    system("cls");
}

void Case9(SuppliesManage &s)
{
    int currentX;
    int currentY;
    int position;
    int arrange;
    string supplies_code;
    string kind_of_supplies;
    string supplies_name;
    string manufacturers;
    double supplies_price;
    int amount;
    int supplies_unit;
    int check;
    Supplies su;
    Functions::gotoxy(75, 3); cout << "Cac ma vat tu da co trong kho la : ";
    Functions::gotoxy(75, 4); cout << "|| ";
    for (int it = 0; it < s.getSups().getSize(); ++it)
    {
        cout << s.getSups()[it].getSuppliesCode() << " || ";
    }
    Functions::gotoxy(75, 6); cout << "Moi ban nhap cac thong tin cua vat tu muon them vao kho !";
    Functions::gotoxy(75, 8); cout << "Ma vat tu : "; 
    currentY = Functions::getY() + 1;
    cin >> supplies_code;
    check = 0;
    while(check == 0)
    {   
        for(int i = 0 ; i < s.getSups().getSize() ; ++i) 
            if(supplies_code != s.getSups()[i].getSuppliesCode()) {
                check++;
            }
        if(check != s.getSups().getSize()) {
            check = 0;
            Functions::gotoxy(75, currentY + 1); cout << "                                                                                                        ";
            Functions::gotoxy(75, currentY); cout << "Ma vat tu ban vua nhap da co san trong kho !";
            Functions::gotoxy(75, currentY + 1); cout << "Moi ban nhap lai : ";
            cin >> supplies_code;
        }
        else break;
    }
    su.setSuppliesCode(supplies_code);
    currentX = Functions::getX();
    currentY = Functions::getY();
    Functions::gotoxy(75, currentY + 1); cout << "So luong : ";
    cin >> amount;
    su.setAmount(amount);
    currentY = Functions::getY();
    Functions::gotoxy(75, currentY + 1); cout << "Cac ma nha san xuat da co san la : ";
    currentY = Functions::getY() + 1;
    for (int i = 0; i < s.SizeMF; ++i) 
    {
        Functions::gotoxy(75, currentY++); cout << s.MarkMF[i] << "         :        " << s.NameMF[i];
    }
    Functions::gotoxy(75, currentY); cout << "ma nha san xuat : ";
    cin >> manufacturers;
    check = 0;
    currentY = Functions::getY() + 1;
    while(check == 0) {
        for(int i = 0 ; i < s.SizeMF ; ++i)
            if(s.MarkMF[i] == manufacturers) {
                check = 1;
                break;
            }
        if(check == 0) {
            Functions::gotoxy(75, currentY + 1); cout << "                                                                                                        ";
            Functions::gotoxy(75, currentY); cout << "Ma nha san xuat ban nhap khong co san trong kho !";
            Functions::gotoxy(75, currentY + 1); cout << "Moi ban nhap lai : ";
            cin >> manufacturers;
        }
    }
    su.setSuppliesMa(manufacturers);
    cin >> su;
    currentY = Functions::getY() + 1;
    Functions::gotoxy(75, currentY + 1); cout << "Nhap vi tri ban muon them vao : ";
    cin >> position;
    Functions::gotoxy(75, currentY + 3); cout << "Ban co muon sap xep lai vat tu trong kho khong ?";
    Functions::gotoxy(75, currentY + 4); cout << "nhan 1 neu muon nguoc lai nhan 0 : ";
    cin >> arrange;
    s.InsertStorage(su, position - 1, arrange);
    currentY = Functions::getY() + 1;
    Functions::gotoxy(75, currentY + 1); cout << "Thao tac thanh cong!!";
    system("pause");
    system("cls");
}

void Case10(SuppliesManage &s)
{
    s.deleteSupplies100();
    Functions::gotoxy(75, 3); cout << "Thao tac thanh cong!!";
    system("pause");
    system("cls");
}

void Case11(SuppliesManage &s)
{
    int y, z;
    Functions::gotoxy(75, 3); cout << "- Sap xep theo ma vat tu nhap phim 1";
    Functions::gotoxy(75, 5); cout << "- Sap xep theo ten vat tu nhap phim 2";
    Functions::gotoxy(75, 7); cout << "- Sap xep theo loai vat tu nhap phim 3";
    Functions::gotoxy(75, 9); cout << "- Sap xep theo so luong vat tu nhap phim 4";
    Functions::gotoxy(75, 11); cout << "- Sap xep theo gia vat tu nhap phim 5";
    Functions::gotoxy(75, 13); cout << "Moi ban nhap : ";
    cin >> y;
    Functions::gotoxy(75, 16); cout << "Ban muon sap xep giam dan hay tang dan ?" << '\n';
    Functions::gotoxy(75, 18); cout << " - Nhap phim 1 neu muon tang dan" << '\n';
    Functions::gotoxy(75, 20); cout << " - Nhap phim 2 neu muon giam dan" << '\n';
    Functions::gotoxy(75, 22); cout << "Moi ban nhap : ";
    cin >> z;
    s.SortStorage(y, z, 0, s.getSups().getSize() - 1);
    s.updateStorage();
    Functions::gotoxy(75, 24); cout << "Thao tac thanh cong!!";
    system("pause");
    system("cls");
}

void Case12(SuppliesManage &s)
{
    s.show();
    cout << "Thao tac thanh cong!!";
    system("pause");
    system("cls");
}

void Case13(SuppliesManage &s)
{
    s.FindSupplies();
    system("pause");
    system("cls");
}

void Case14(SuppliesManage &s)
{
    s.showAll();
    system("pause");
    system("cls");
}

void Case15(SuppliesManage &s)
{
    int pst;
    int pos = 5;
    int n;
    string supplies_code;
    int amount;
    int check;
    ofstream outFile;
    EntryDate enDate;
    Vector<EntryDate> exportDates;
    exportDates = s.getExportDate();
    time_t time_now = time(NULL);
    struct tm *time_info = localtime(&time_now);             // Chuyển time_t sang struct tm.
    char buffer[80];                                         // Chuỗi ký tự để chứa ngày đã định dạng.
    strftime(buffer, sizeof(buffer), "%d/%m/%Y", time_info); // Định dạng ngày tháng.
    string date_str(buffer);                                 // Gán chuỗi ký tự vào std::string.
    Functions::gotoxy(75, 3); cout << "Moi ban nhap so luong vat tu muon xuat kho : ";
    cin >> n;
    Functions::gotoxy(75, 4); cout << "Cac ma vat tu co san trong kho la : " << '\n';
    for (int i = 0; i < s.getSups().getSize(); ++i)
    {   
        if (s.getSups()[i].getAmount() != 0)
        {
            Functions::gotoxy(75, pos);
            cout << "Ma vat tu : " << left << setw(8) << s.getSups()[i].getSuppliesCode() << " || "
                 << "Ten Vat tu : " << s.getSups()[i].getSuppliesName();
            pos++;
        }
    }
    for (int i = 1; i <= n; ++i)
    {   
        Functions::gotoxy(75, pos++); cout << "Moi ban nhap ma vat tu thu " << i << " : ";
        cin >> supplies_code;

        // Check coi có mã trong kho khong !
        int p = -1;
        pst = pos;
        while (p == -1)
        {
            for (int i = 0; i < s.getSups().getSize(); ++i)
                if (s.getSups()[i].getSuppliesCode() == supplies_code)
                {
                    p = i;
                    break;
                }
            if (p == -1)
            {
                Functions::gotoxy(75, pst + 1); cout << "                                                                                                        ";
                Functions::gotoxy(75, pst); cout << "Ma vat tu ban nhap khong co trong kho !" << '\n';
                Functions::gotoxy(75, pst + 1); cout << "Moi ban nhap lai ma vat tu : ";
                cin >> supplies_code;
            }
        }
        pos += 2;
        Functions::gotoxy(75, pos++); cout << "Moi ban nhap so luong xuat kho : ";
        cin >> amount;
        Functions::gotoxy(75, pos++);

        s.exportSupplies(supplies_code, amount, p);
        pos = Functions::getY() + 2;

        check = -1;
        for (int j = 0; j < exportDates.getSize(); ++j)
            if (exportDates[j].getTime() == date_str)
            {
                check = 0;
                for (int k = 0; k < exportDates[j].getSup().getSize(); ++k)
                    if (exportDates[j].getSup()[k].getSuppliesCode() == supplies_code)
                    {
                        int i;
                        for(i = 0 ; i < s.getSups().getSize() ; ++i) 
                            if(s.getSups()[i].getSuppliesCode() == supplies_code) break;
                        exportDates[j].getSup()[k].setAmount(exportDates[j].getSup()[k].getAmount() + amount);
                        exportDates[j].getSup()[k].setSuppliesPrice(exportDates[j].getSup()[k].getSuppliesPrice() + Functions::getCostOfSupp(amount , s.getSups()[i].getSuppliesPrice()));
                        check = 1;
                        break;
                    }
                if (check == 1)
                    break;
                else
                {
                    int i;
                    for(i = 0 ; i < s.getSups().getSize() ; ++i) 
                            if(s.getSups()[i].getSuppliesCode() == supplies_code) break;
                    exportDates[j].getSup().push_back(Supplies(supplies_code, "", "", "",Functions::getCostOfSupp(amount , s.getSups()[i].getSuppliesPrice()), amount));
                    break;
                }
            }
        if (check == -1)
        {
            int i;
            for(i = 0 ; i < s.getSups().getSize() ; ++i) 
                if(s.getSups()[i].getSuppliesCode() == supplies_code) break;
            enDate.addSupplies(Supplies(supplies_code, "", "", "", Functions::getCostOfSupp(amount , s.getSups()[i].getSuppliesPrice()), amount));
            enDate.setTime(date_str);
            exportDates.push_back(enDate);
        }
    }
    outFile.open("ExportDate.txt", ios::trunc);
    outFile << "|   Ngày Xuất    |    Mã vật tư     |    Số lượng     |  Tổng giá tiền  |" << '\n';
    for (int i = 0; i < exportDates.getSize(); ++i)
    {
        if (exportDates[i].getSup().getSize() > 0)
        {
            for (int j = 0; j < exportDates[i].getSup().getSize(); ++j)
            {
                outFile << setw(15) << left << exportDates[i].getTime() << "  ,  ";
                outFile << setw(14) << left << exportDates[i].getSup()[j].getSuppliesCode() << "  ,  ";
                outFile << setw(13) << left << exportDates[i].getSup()[j].getAmount() << "   ,   ";
                outFile << setw(14) << left << exportDates[i].getSup()[j].getSuppliesPrice() << '\n';
            }
        }
    }
    outFile.close();
    s.updateStorage();
    cout << "Thao tac thanh cong!!";
    system("pause");
    system("cls");
}

void Case16(SuppliesManage &s)
{
    s.statisticsTypeofSupplies();
    cout << "Thao tac thanh cong!!";
    system("pause");
    system("cls");
}

void Case17(SuppliesManage &s) {
    s.addMarkUnit();
    int currentY = Functions::getY();
    Functions::gotoxy(75, currentY + 2);
    cout << "Thao tac thanh cong!!";
    Functions::gotoxy(75, currentY + 4);
    system("pause");
    system("cls");
}

void Case18(SuppliesManage &s) {
    s.addMarkTypeOFSupp();
    int currentY = Functions::getY();
    Functions::gotoxy(75, currentY + 2);
    cout << "Thao tac thanh cong!!";
    Functions::gotoxy(75, currentY + 4);
    system("pause");
    system("cls");
}


void Case19(SuppliesManage &s) {
    s.addMarkMK();
    int currentY = Functions::getY();
    Functions::gotoxy(75, currentY + 2);
    cout << "Thao tac thanh cong!!";
    Functions::gotoxy(75, currentY + 4);
    system("pause");
    system("cls");
}

void Case20(SuppliesManage &s) {
    s.showUnit();
    int currentY = Functions::getY();
    Functions::gotoxy(75, currentY + 2);
    cout << "Thao tac thanh cong!!";
    Functions::gotoxy(75, currentY + 4);
    system("pause");
    system("cls");
}

void Case21(SuppliesManage &s) {
    s.showKOSups();
    int currentY = Functions::getY();
    Functions::gotoxy(75, currentY + 2);
    cout << "Thao tac thanh cong!!";
    Functions::gotoxy(75, currentY + 4);
    system("pause");
    system("cls");
}

void Case1(SuppliesManage &s)
{   
    Functions::gotoxy(5, 29); cout << "1.1. Cap nhat du lieu tu file Input";
    Functions::gotoxy(5, 31); cout << "1.2. Them 1 vat tu moi vao kho";
    Functions::gotoxy(5, 33); cout << "1.3. Them ki hieu don vi";
    Functions::gotoxy(5, 35); cout << "1.4. Them ki hieu loai vat tu";
    Functions::gotoxy(5, 37); cout << "1.5. Them ki hieu nha san xuat";
    Functions::gotoxy(5, 39); cout << "1.6. Tro lai Menu";
    int choice;
    Functions::setcolor(2);
    Functions::gotoxy(5, 50); cout << "                                               ";
    Functions::gotoxy(5, 50); cout << "Nhap lua chon cua ban: ";
    cin >> choice;
    while(choice < 1 || choice > 6)
    {   
        Functions::gotoxy(5, 50); cout << "                                               ";
        Functions::gotoxy(5, 50); cout << "Nhap lua chon cua ban: "; cin >> choice;
    }
    switch(choice) {
        case 1:
            Case7(s);
            break;
        case 2:
            Case9(s);
            break;
        case 3:
            Case17(s);
            break;
        case 4:
            Case18(s);
            break;
        case 5:
            Case19(s);
            break;  
        case 6:
            break;
    }
}

void Case2(SuppliesManage &s) 
{
    Functions::gotoxy(5, 29); cout << "2.1. Xuat vat tu ra khoi kho";
    Functions::gotoxy(5, 31); cout << "2.2. Tro lai Menu";
    int choice;
    Functions::setcolor(2);
    Functions::gotoxy(5, 50); cout << "                                               ";
    Functions::gotoxy(5, 50); cout << "Nhap lua chon cua ban: ";
    cin >> choice;
    while(choice < 1 || choice > 2)
    {   
        Functions::gotoxy(5, 50); cout << "                                               ";
        Functions::gotoxy(5, 50); cout << "Nhap lua chon cua ban: "; cin >> choice;
    }
    switch(choice) {
        case 1:
            Case15(s);
            break; 
        case 2:
            break;
    }
};

void Case3(SuppliesManage &s) 
{
    Functions::gotoxy(5, 29); cout << "3.1. Xoa 1 vat tu bat ki";
    Functions::gotoxy(5, 31); cout << "3.2. Xoa vat tu co so luong tren 100";
    Functions::gotoxy(5, 33); cout << "3.3. Tro lai Menu";
    int choice;
    Functions::setcolor(2);
    Functions::gotoxy(5, 50); cout << "                                               ";
    Functions::gotoxy(5, 50); cout << "Nhap lua chon cua ban: ";
    cin >> choice;
    while(choice < 1 || choice > 3)
    {   
        Functions::gotoxy(5, 50); cout << "                                               ";
        Functions::gotoxy(5, 50); cout << "Nhap lua chon cua ban: "; cin >> choice;
    }
    switch(choice) {
        case 1:
            Case8(s);
            break;
        case 2:
            Case10(s);
            break;
        case 3:
            break;
    }
};

void Case4(SuppliesManage &s) 
{
    Functions::gotoxy(5, 29); cout << "4.1. Sap xep vat tu trong kho";
    Functions::gotoxy(5, 31); cout << "4.2. Tro lai Menu";
    int choice;
    Functions::setcolor(2);
    Functions::gotoxy(5, 50); cout << "                                               ";
    Functions::gotoxy(5, 50); cout << "Nhap lua chon cua ban: ";
    cin >> choice;
    while(choice < 1 || choice > 2)
    {   
        Functions::gotoxy(5, 50); cout << "                                               ";
        Functions::gotoxy(5, 50); cout << "Nhap lua chon cua ban: "; cin >> choice;
    }
    switch(choice) {
        case 1:
            Case11(s);
            break;
        case 2:
            break;
    }
};

void Case5(SuppliesManage &s) 
{
    Functions::gotoxy(5, 29); cout << "5.1. Bang tong gia tien cac vat tu trong kho";
    Functions::gotoxy(5, 31); cout << "5.2. Tra cuu 1 vat tu trong kho";
    Functions::gotoxy(5, 33); cout << "5.3. Bang thong tin chi tiet cac vat tu trong kho";
    Functions::gotoxy(5, 35); cout << "5.4. Thong ke vat tu theo loai vat tu";
    Functions::gotoxy(5, 37); cout << "5.5. Bang ma loai vat tu";
    Functions::gotoxy(5, 39); cout << "5.6. Bang don vi vat tu";
    Functions::gotoxy(5, 41); cout << "5.7. Tro lai Menu";
    int choice;
    Functions::setcolor(2);
    Functions::gotoxy(5, 50); cout << "                                               ";
    Functions::gotoxy(5, 50); cout << "Nhap lua chon cua ban: ";
    cin >> choice;
    while(choice < 1 || choice > 7)
    {   
        Functions::gotoxy(5, 50); cout << "                                               ";
        Functions::gotoxy(5, 50); cout << "Nhap lua chon cua ban: "; cin >> choice;
    }
    switch(choice) {
        case 1:
            Case12(s);
            break;
        case 2:
            Case13(s);
            break;
        case 3:
            Case14(s);
            break;
        case 4:
            Case16(s);
            break;
        case 5:
            Case21(s);
            break;
        case 6:
            Case20(s);
            break;
        case 7:
            break;
    }
};

bool checkStorage(SuppliesManage &s) {
    if(s.getSups().getSize() == 0) return true;
    else return false;
}