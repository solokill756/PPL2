#include "Storage.h"
#include<ctime>
#include<iomanip>
#include "unit.h"
#include "Manufacturer.h"
#include "KOsupply.h"

const int N = 50;
class SuppliesManage : public Storage
{
    public:
        Vector<Manufacturer> mf;
        Vector<unit> un;
        Vector<KOsupply> ko;
    protected:
        Storage kho;
        Vector<EntryDate> ed;  // Ngày nhập
    public:
        SuppliesManage();
        ~SuppliesManage();

        void putUnit();
        void PutMark();
        void PutKOSupply();
        void addEd(EntryDate); 
        Storage& getStorage();

        Vector<Supplies>& getSups();
        Vector<EntryDate>& getEd();
        void addTestEnDate(Vector<string>&);
        void updateListEd(); // cập nhật lại EntryDate.txt
        void input(); // nhập thêm vật tư
        void currentEntryDate(); // nhập dữ liệu lịch sử nhập vật tư hiện tại (có sẵn trong text)
        void addNewData(); // thêm dữ liệu mới từ input
        void deleteSupplies(string); // Xóa vật tư nhập từ bàn phím
        void deleteSupplies100(); // xóa vật tư có số lượng hơn 100
        // sắp xếp theo thứ tự ??
        void InsertStorage(Supplies , int , const int&); // chèn vật tư vào kho
        void show(); //Loại vật tư | Số lượng | Tổng tiền
        void FindSupplies(); // Tìm kiếm ?
        Vector<EntryDate> getExportDate(); // Get các ngày xuất vào vector
        void statisticsTypeofSupplies(); // thông kê theo loại vật tư
        void exportSupplies(const string& , int& , const int&); // Xuất các loại vật tư ra khỏi kho
        void editSup(); // sửa thông tin vật tư
        void editUnit();
        void editManufacturer();
        void editKOsup();
        void addMarkUnit(); // Them ki hieu don vi
        void addMarkTypeOFSupp(); // Them ki hieu loai vat tu
        void addMarkMK();
        void showAll(); //in hết thông tin các vật tư
        void showUnit();
        void showKOSups();
        string getKindOfSupps(const string&);
        string getUnitOfSupps(const string&);
        string getManufacturers(const string&);
};
