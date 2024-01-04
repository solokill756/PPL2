#include "EntryDate.h"
#include<ctime>
#include<iomanip>
const int N = 50;
class SuppliesManage
{
    public:
        int SizeMF;
        string MarkMF[N + 1];
        string NameMF[N + 1];
    protected:
        Vector<Supplies> sups; // Nhà kho chứa vật tư
        Vector<EntryDate> ed;  // Ngày nhập
    public:
        SuppliesManage();
        ~SuppliesManage();
        void PutMark();
        void addSups(Supplies);
        void addEd(EntryDate);

        Vector<Supplies>& getSups();
        Vector<EntryDate>& getEd();
        int checkSupplies(string&); // check ma tu phu hop cung nhu tim kiem vi tri vat tu do
        void addTestEnDate(Vector<string>&);
        void updateListEd(); // cập nhật lại EntryDate.txt
        void input(); // nhập thêm vật tư
        void currentStorage(); // nhập dữ liệu nhà kho hiện tại (có sẵn trong text)
        void currentEntryDate(); // nhập dữ liệu lịch sử nhập vật tư hiện tại (có sẵn trong text)
        void addNewData(); // thêm dữ liệu mới từ input
        void updateStorage(); // cập nhật lại Storage.txt
        void deleteSupplies(string); // Xóa vật tư nhập từ bàn phím
        void deleteSupplies100(); // xóa vật tư có số lượng hơn 100
        // sắp xếp theo thứ tự ??
        void SortStorage(const int& , const int& , int , int); // Sắp xếp lại kho
        void InsertStorage(Supplies , int , const int&); // chèm vật tư vào kho
        void show(); //Loại vật tư | Số lượng | Tổng tiền
        void FindSupplies(); // Tìm kiếm ?
        Vector<EntryDate> getExportDate(); // Get các ngày xuất vào vector
        void statisticsTypeofSupplies(); // thông kê theo loại vật tư
        void exportSupplies(const string& , int& , const int&); // Xuất các loại vật tư ra khỏi kho
        void addMarkUnit(); // Them ki hieu don vi
        void addMarkTypeOFSupp(); // Them ki hieu loai vat tu
        void addMarkMK();
        void showAll(); //in hết thông tin các vật tư
        void showUnit();
        void showKOSups();
};