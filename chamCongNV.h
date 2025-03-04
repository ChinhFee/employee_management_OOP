#include "lyLichNV.h"

class chamCongNV : public lyLichNV
{
private:
    int soNgayNghiCoPhep;
    int soNgayNghiKhongPhep;
    int soNgayLamThem;
    string ketQuaCongViec;
    double luongThucLinh;

public:
    // Hàm khởi tạo
    chamCongNV(string maNV, string tenNV, char tinhTrangGD, int soCon, string trinhDoVH, int luongCB,
               int soNgayNghiCoPhep, int soNgayNghiKhongPhep, int soNgayLamThem, string ketQuaCongViec)
        : lyLichNV(maNV, tenNV, tinhTrangGD, soCon, trinhDoVH, luongCB)
    {
        this->soNgayNghiCoPhep = soNgayNghiCoPhep;
        this->soNgayNghiKhongPhep = soNgayNghiKhongPhep;
        this->soNgayLamThem = soNgayLamThem;
        this->ketQuaCongViec = ketQuaCongViec;
        tinhLuongThucLinh();
    }

    // Hàm tính lương thực lĩnh
    void tinhLuongThucLinh()
    {
        float phuTroi = 0;
        if (lyLichNV::soCon > 2)
        {
            phuTroi = 0.05 * lyLichNV::luongCB;
        }
        if (lyLichNV::trinhDoVH == "CH")
        {
            phuTroi = 0.1 * lyLichNV::luongCB;
        }
        if (soNgayLamThem > 0 && soNgayLamThem <= 28)
        {
            phuTroi = 0.04 * lyLichNV::luongCB * soNgayLamThem;
        }
        if (soNgayNghiKhongPhep > 0 && soNgayNghiKhongPhep <= 28)
        {
            phuTroi = -0.05 * lyLichNV::luongCB * soNgayNghiKhongPhep;
        }
        luongThucLinh = lyLichNV::luongCB + phuTroi;
    }

    // Hàm lấy giá trị (getter)
    double getLuongThucLinh()
    {
        return luongThucLinh;
    }

    int getSoNgayNghiCoPhep()
    {
        return soNgayNghiCoPhep;
    }

    int getSoNgayNghiKhongPhep()
    {
        return soNgayNghiKhongPhep;
    }

    int getSoNgayLamThem()
    {
        return soNgayLamThem;
    }

    string getKetQuaCongViec()
    {
        return ketQuaCongViec;
    }

    // Hàm sửa giá trị (setter)
    void setSoNgayNghiCoPhep(int soNgayNghiCoPhep)
    {
        this->soNgayNghiCoPhep = soNgayNghiCoPhep;
    }

    void setSoNgayNghiKhongPhep(int soNgayNghiKhongPhep)
    {
        this->soNgayNghiKhongPhep = soNgayNghiKhongPhep;
    }

    void setSoNgayLamThem(int soNgayLamThem)
    {
        this->soNgayLamThem = soNgayLamThem;
    }

    void setKetQuaCongViec(string ketQuaCongViec)
    {
        this->ketQuaCongViec = ketQuaCongViec;
    }

    void hienThiThongTin() override
    {
        cout << "Thong tin nhan vien:" << endl;
        lyLichNV::hienThiThongTin();
        cout << "Cham cong cua nhan vien:" << endl;
        cout << setw(5) << left << "CP";
        cout << setw(5) << left << "KP";
        cout << setw(5) << left << "LT";
        cout << setw(10) << left << "KQCV";
        cout << setw(10) << left << "LTL" << endl;
        cout << setfill('-');
        cout << setw(35) << "-" << endl;
        cout << setfill(' ');

        cout << setw(5) << left << soNgayNghiCoPhep;
        cout << setw(5) << left << soNgayNghiKhongPhep;
        cout << setw(5) << left << soNgayLamThem;
        cout << setw(10) << left << ketQuaCongViec;
        cout << setw(10) << left << luongThucLinh << endl;
    }
};