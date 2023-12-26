#include <iostream>
#include "Menu.cpp"

using namespace std;

int main() {
    //Functions::newTerminal();
    //Functions::setConsoleSize(179, 48);
    SuppliesManage s;
    int yourChoice;
    while(1)
    {
        system("cls");
        Menu();
        Functions::setcolor(2);
        Functions::gotoxy(5, 50); cout << "Nhap lua chon cua ban: ";
        cin >> yourChoice;
        switch(yourChoice) {
        case 1:
            Case1(s);
            break;
        case 2: // xuat vat tu
             if(checkStorage(s)) {
                Functions::gotoxy(75 , Functions::getY() + 1); cout << "Kho dang rong xin moi ban quay lai sao !" << '\n';
                Functions::gotoxy(75 , Functions::getY() + 1); system("pause");
                system("cls");
                break;
            }
            Case2(s);
            break;
        case 3: // xoa vat tu
            if(checkStorage(s)) {
                Functions::gotoxy(75 , Functions::getY() + 1); cout << "Kho dang rong xin moi ban quay lai sao !" << '\n';
                Functions::gotoxy(75 , Functions::getY() + 1); system("pause");
                system("cls");
                break;
            }
            Case3(s);
            break;
        case 4: // Sap xep vat tu
            if(checkStorage(s)) {
                Functions::gotoxy(75 , Functions::getY() + 1); cout << "Kho dang rong xin moi ban quay lai sao !" << '\n';
                Functions::gotoxy(75 , Functions::getY() + 1); system("pause");
                system("cls");
                break;
            }
            Case4(s);
            break;
        case 5: // Tra cuu thong tin
            if(checkStorage(s)) {
                Functions::gotoxy(75 , Functions::getY() + 1); cout << "Kho dang rong xin moi ban quay lai sao !" << '\n';
                Functions::gotoxy(75 , Functions::getY() + 1); system("pause");
                system("cls");
                break;
            }
            Case5(s);
            break;
        case 6:
            system("cls");
            exit(0);  
        default:
            Functions::gotoxy(5, 50); std::cout << "Lua chon ban nhap khong hop le" << '\n';
            Functions::gotoxy(5, 51); system("pause");
            break;
        }
    }
    return 0;
}