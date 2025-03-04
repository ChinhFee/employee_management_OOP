#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class lyLichNV
{
protected:
    string maNV;
    string tenNV;
    char tinhTrangGD;
    int soCon;
    string trinhDoVH;
    int luongCB;

public:
    // Hàm khởi tạo
    lyLichNV(string maNV, string tenNV, char tinhTrangGD, int soCon, string trinhDoVH, int luongCB)
    {
        this->maNV = maNV;
        this->tenNV = tenNV;
        this->tinhTrangGD = tinhTrangGD;
        this->soCon = soCon;
        this->trinhDoVH = trinhDoVH;
        this->luongCB = luongCB;
    }

    // Hàm lấy giá trị (getter)
    string getMaNV()
    {
        return maNV;
    }
    string getTenNV()
    {
        return tenNV;
    }
    char getTinhTrangGD()
    {
        return tinhTrangGD;
    }
    int getSoCon()
    {
        return soCon;
    }
    string getTrinhDoVH()
    {
        return trinhDoVH;
    }
    int getLuongCB()
    {
        return luongCB;
    }

    // Hàm sửa giá trị (setter)
    void setMaNV(string maNV)
    {
        this->maNV = maNV;
    }
    void setTenNV(string tenNV)
    {
        this->tenNV = tenNV;
    }
    void setTinhTrangGD(char tinhTrangGD)
    {
        this->tinhTrangGD = tinhTrangGD;
    }
    void setSoCon(int soCon)
    {
        this->soCon = soCon;
    }
    void setTrinhDoVH(string trinhDoVH)
    {
        this->trinhDoVH = trinhDoVH;
    }
    void setLuongCB(int luongCB)
    {
        this->luongCB = luongCB;
    }

    // In thông tin
    virtual void hienThiThongTin()
    {
        cout << setw(7) << left << "Ma NV";
        cout << setw(25) << left << "Ten NV";
        cout << setw(5) << left << "GD";
        cout << setw(5) << left << "Con";
        cout << setw(10) << left << "Trinh do";
        cout << setw(13) << left << "Luong CB" << endl;
        cout << setfill('-');
        cout << setw(65) << "-" << endl;
        cout << setfill(' ');

        cout << setw(7) << left << maNV;
        cout << setw(25) << left << tenNV;
        cout << setw(5) << left << tinhTrangGD;
        cout << setw(5) << left << soCon;
        cout << setw(10) << left << trinhDoVH;
        cout << setw(13) << left << luongCB << endl;
    }
};
