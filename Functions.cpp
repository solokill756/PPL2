#include "Functions.h"
int Functions::Change(const string &s)
{
    int sum = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] >= '0' && s[i] <= '9')
            sum = sum * 10 + int(s[i]) - 48;
    }
    return sum;
}

int Functions::conpare(string s1, string s2)
{
    s1 = s1 + '/';
    s2 = s2 + '/';
    int i = 0;
    string temp1 = "", temp2 = "";
    int d1, m1, y1, d2, m2, y2;
    int count = 0;
    while (i < s1.size() && i < s2.size())
    {
        if (s1[i] != '/')
        {
            temp1 = temp1 + s1[i];
            temp2 = temp2 + s2[i];
        }
        else if (s1[i] == '/')
        {
            // cout << temp1 << " " << temp2 << endl;
            if (count == 0)
            {
                d1 = Functions::Change(temp1);
                d2 = Functions::Change(temp2);
                count++;
                temp1 = "";
                temp2 = "";
            }
            else if (count == 1)
            {
                m1 = Functions::Change(temp1);
                m2 = Functions::Change(temp2);
                count++;
                temp1 = "";
                temp2 = "";
            }
            else
            {
                y1 = Functions::Change(temp1);
                y2 = Functions::Change(temp2);
                count++;
                temp1 = "";
                temp2 = "";
            }
        }
        i++;
    }
    // cout << d1 << " " << d2 << endl;
    if (y1 > y2)
        return 1;
    else if (y1 < y2)
        return 2;
    else
    {
        if (m1 > m2)
            return 1;
        else if (m1 < m2)
            return 2;
        else
        {
            if (d1 > d2)
                return 1;
            else if (d1 < d2)
                return 2;
            else
                return 0;
        }
    }
    return 0;
}

int Functions::compareString(const string &s1, const string &s2)
{
    if (s1.size() > s2.size())
        return 1;
    else if (s1.size() < s2.size())
        return 2;
    else
    {
        if (s1 > s2)
            return 1;
        else if (s1 < s2)
            return 2;
        else
            return 0;
    }
}

void Functions::gotoxy(int x, int y)
{
    COORD coordinate;
    coordinate.X = x;
    coordinate.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
}

void Functions::setcolor(int color)
{
	WORD wColor;
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          wColor = (csbi.wAttributes & 0xF0) + (color & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
}

int Functions::getX()
{   
    int currentX;
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if (GetConsoleScreenBufferInfo(consoleHandle, &csbi)) 
        currentX = csbi.dwCursorPosition.X;
    return currentX;
}

int Functions::getY()
{
    int currentY;
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if (GetConsoleScreenBufferInfo(consoleHandle, &csbi)) 
        currentY = csbi.dwCursorPosition.Y;
    return currentY;
}

void Functions::newTerminal()
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    GetConsoleScreenBufferInfo(console, &bufferInfo);
    SMALL_RECT rect;
    rect.Left = 0;
    rect.Top = 0;
    rect.Right = 179;  // Đặt chiều rộng mới là 80 ký tự (đếm từ 0)
    rect.Bottom = 48; // Đặt chiều cao mới là 25 dòng (đếm từ 0)

    SetConsoleWindowInfo(console, TRUE, &rect);
}

void Functions::setConsoleSize(int columns, int rows)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD bufferSize;
    bufferSize.X = columns;
    bufferSize.Y = rows;
    SetConsoleScreenBufferSize(console, bufferSize);
}

long long Functions::getCostOfSupp(long long sl , long long money)
{
    if (sl > 200)
    {
        return sl * money * 0.75;
    }
    else if (sl > 100 && sl <= 200)
    {
        return sl * money * 0.9;
    }
    else
    {
        return sl * money;
    }
}

string Functions::getKindOfSupps(const string& str)
{
    ifstream fileInput;
    fileInput.open("Supplies.txt", ios::in);
    string s;
    int size = 50;
    string mark[size + 1];
    string name[size + 1];
    int p = 0;
    int n = 0;
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
                    // cout << s[j] << '\n';
                    st = st + s[j];
                }
                j++;
            }
            if (j < s.size())
                mark[p] = st;
            else
                name[p] = st;
            i = j + 1;
        }
        p++;
    }
    fileInput.close();
    for (int j = 0; j < size; ++j)
    {
        if (str == mark[j])
        {
            return name[j];
        }
    }
    return "";
}

string Functions::getUnitOfSupps(const string& str)
{
    ifstream fileInput;
    fileInput.open("Unit.txt", ios::in);
    string s;
    int size = 50;
    string mark[size + 1];
    string name[size + 1];
    int p = 0;
    int n = 0;
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
                    // cout << s[j] << '\n';
                    st = st + s[j];
                }
                j++;
            }
            if (j < s.size())
                mark[p] = st;
            else
                name[p] = st;
            i = j + 1;
        }
        p++;
    }
    fileInput.close();
    for (int j = 0; j < size; ++j)
    {
        if (str == mark[j])
        {
            return name[j];
        }
    }
    return "";
}


string Functions::getManufacturers(const string& str)
{
    ifstream fileInput;
    fileInput.open("Manufacturers.txt", ios::in);
    string s;
    int size = 50;
    string mark[size + 1];
    string name[size + 1];
    int p = 0;
    int n = 0;
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
                    // cout << s[j] << '\n';
                    st = st + s[j];
                }
                j++;
            }
            if (j < s.size())
                mark[p] = st;
            else
                name[p] = st;
            i = j + 1;
        }
        p++;
    }
    fileInput.close();
    for (int j = 0; j < size; ++j)
    {
        if (str == mark[j])
        {
            return name[j];
        }
    }
    return "";
}