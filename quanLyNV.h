#include <vector>

#include "chamCongNV.h"

using namespace std;

class quanLyNV
{
private:
    vector<chamCongNV> danhSachNV;
    enum thongTinNV
    {
        tenNV = 1,
        tinhTrangGD,
        soCon,
        trinhDoVH,
        luongCB,
        soNgayNghiCoPhep,
        soNgayNghiKhongPhep,
        soNgayLamThem,
        ketQuaCongViec,
    };

public:
    // Hàm thêm nhân viên
    void themNV()
    {
        string ma;
        string ten;
        char GD;
        int Con;
        string VH;
        int CB;
        int CP;
        int KP;
        int LT;
        string KQ;
        do
        {
            cout << "Nhap ma nhan vien (8 ky tu): ";
            cin >> ma;
            if (ma.length() > 8)
            {
                cout << "Ma nhan vien phai co 8 ky tu. Nhap lai." << endl;
            }
        } while (ma.length() > 8);

        cin.ignore();
        do
        {
            cout << "Nhap ten nhan vien (toi da 20 ky tu): ";
            getline(cin, ten);
            if (ten.length() > 20)
            {
                cout << "Ten nhan vien khong duoc qua 20 ky tu. Nhap lai." << endl;
            }
        } while (ten.length() > 20);

        do
        {
            cout << "Nhap tinh trang gia dinh (M/S): ";
            cin >> GD;
            if (GD != 'M' && GD != 'S')
            {
                cout << "Tinh trang gia dinh chi co the la 'M' hoac 'S'. Nhap lai." << endl;
            }
        } while (GD != 'M' && GD != 'S');

        do
        {
            cout << "Nhap so con: ";
            cin >> Con;
            if (Con < 0 || Con > 20)
            {
                cout << "So con phai thoa 0 < X < 20. Nhap lai." << endl;
            }
        } while (Con < 0 || Con > 20);

        do
        {
            cout << "Nhap trinh do van hoa (C1/C2/C3/DH/CH): ";
            cin >> VH;
            if (VH != "C1" && VH != "C2" && VH != "C3" && VH != "DH" && VH != "CH")
            {
                cout << "Trinh do van hoa chi co the la 'C1', 'C2', 'C3', 'DH', hoac 'CH'. Nhap lai." << endl;
            }
        } while (VH != "C1" && VH != "C2" && VH != "C3" && VH != "DH" && VH != "CH");

        do
        {
            cout << "Nhap luong co ban: ";
            cin >> CB;
            if (CB < 0 || CB > 1000000)
            {
                cout << "Luong co ban phai thoa 0 < X < 1000000. Nhap lai." << endl;
            }
        } while (CB < 0 || CB > 1000000);

        do
        {
            cout << "Nhap so ngay nghi CP, nghi KP, LT: ";
            cin >> CP >> KP >> LT;
            if ((CP < 0 || CP > 28) || (KP < 0 || KP > 28) || (LT < 0 || LT > 28))
            {
                cout << "So ngay nghi CP, nghi KP, LT phai thoa 0 < X < 28. Nhap lai." << endl;
            }
        } while ((CP < 0 || CP > 28) || (KP < 0 || KP > 28) || (LT < 0 || LT > 28));

        do
        {
            cout << "Nhap ket qua cong viec (T/TB/K): ";
            cin >> KQ;
            if (KQ != "T" && KQ != "TB" && KQ != "K")
            {
                cout << "Ket qua cong viec chi co the la 'T', 'TB', hoac 'K'. Nhap lai." << endl;
            }
        } while (KQ != "T" && KQ != "TB" && KQ != "K");

        chamCongNV nv(ma, ten, GD, Con, VH, CB, CP, KP, LT, KQ);
        danhSachNV.push_back(nv);
        cout << "Da them nhan vien co ma " << nv.getMaNV() << " vao danh sach" << endl;
        cout << "*******************************************************" << endl;
    }

    // Hàm xóa nhân viên
    void xoaNV(string maNV)
    {
        for (size_t i = 0; i < danhSachNV.size(); i++)
        {
            if (danhSachNV[i].getMaNV() == maNV)
            {
                danhSachNV.erase(danhSachNV.begin() + i);
                cout << "Da xoa nhan vien co ma " << maNV << " trong danh sach" << endl;
                cout << "*******************************************************" << endl;
                return;
            }
        }
    }

    // Hàm sửa thông tin nhân viên
    void suaNV(string maNV)
    {
        unsigned int i;
        for (i = 0; i < danhSachNV.size(); i++)
        {
            if (danhSachNV[i].getMaNV() == maNV)
            {
                break;
            }
        }

        if (i == danhSachNV.size())
        {
            cout << "Khong co ma nhan vien " << maNV << " trong danh sach" << endl;
            cout << "*******************************************************" << endl;
            return;
        }

        int thongTin;

        while (true)
        {
            cout << "Chon thong tin can sua:" << endl;
            cout << "1. Ten nhan vien" << endl;
            cout << "2. Tinh trang gia dinh" << endl;
            cout << "3. So con" << endl;
            cout << "4. Trinh do van hoa" << endl;
            cout << "5. Luong co ban" << endl;
            cout << "6. So ngay nghi co phep" << endl;
            cout << "7. So ngay nghi khong phep" << endl;
            cout << "8. So ngay lam them" << endl;
            cout << "9. Ket qua cong viec" << endl;
            cout << "0. Thoat" << endl;
            cout << "Chon: ";
            cin >> thongTin;
            switch ((thongTinNV)thongTin)
            {
            case tenNV:
            {
                string tenNV;
                cout << "Nhap ten moi: ";
                cin.ignore();
                getline(cin, tenNV);
                danhSachNV[i].setTenNV(tenNV);
                cout << "-------------------------------------------------------------" << endl;
                break;
            }
            case tinhTrangGD:
            {
                char tinhTrangGD;
                cout << "Nhap tinh trang gia dinh (updated): ";
                cin >> tinhTrangGD;
                danhSachNV[i].setTinhTrangGD(tinhTrangGD);
                cout << "-------------------------------------------------------------" << endl;
                break;
            }
            case soCon:
            {
                int soCon;
                cout << "Nhap so con (updated): ";
                cin >> soCon;
                danhSachNV[i].setSoCon(soCon);
                cout << "-------------------------------------------------------------" << endl;
                break;
            }
            case trinhDoVH:
            {
                string trinhDoVH;
                cout << "Nhap trinh do (updated): ";
                cin >> trinhDoVH;
                danhSachNV[i].setTrinhDoVH(trinhDoVH);
                cout << "-------------------------------------------------------------" << endl;
                break;
            }
            case luongCB:
            {
                int luongCB;
                cout << "Nhap luong co ban (updated): ";
                cin >> luongCB;
                danhSachNV[i].setLuongCB(luongCB);
                cout << "-------------------------------------------------------------" << endl;
                break;
            }
            case soNgayNghiCoPhep:
            {
                int soNgayNghiCoPhep;
                cout << "Nhap so ngay nghi co phep (updated): ";
                cin >> soNgayNghiCoPhep;
                danhSachNV[i].setSoNgayNghiCoPhep(soNgayNghiCoPhep);
                cout << "-------------------------------------------------------------" << endl;
                break;
            }
            case soNgayNghiKhongPhep:
            {
                int soNgayNghiKhongPhep;
                cout << "Nhap so ngay nghi khong phep (updated): ";
                cin >> soNgayNghiKhongPhep;
                danhSachNV[i].setSoNgayNghiKhongPhep(soNgayNghiKhongPhep);
                cout << "-------------------------------------------------------------" << endl;
                break;
            }
            case soNgayLamThem:
            {
                int soNgayLamThem;
                cout << "Nhap so ngay lam them (updated): ";
                cin >> soNgayLamThem;
                danhSachNV[i].setSoNgayLamThem(soNgayLamThem);
                cout << "-------------------------------------------------------------" << endl;
                break;
            }
            case ketQuaCongViec:
            {
                string ketQuaCongViec;
                cout << "Nhap ket qua cong viec (updated): ";
                cin.ignore();
                getline(cin, ketQuaCongViec);
                danhSachNV[i].setKetQuaCongViec(ketQuaCongViec);
                cout << "-------------------------------------------------------------" << endl;
                break;
            }
            default:
                break;
            }
            if (thongTin == 0)
            {
                cout << "Da sua thong tin nhan vien co ma " << maNV << endl;
                cout << "*******************************************************" << endl;
                break;
            }
        }
    }

    // Hàm tìm thông tin nhân viên
    void timNV(string maNV)
    {
        for (size_t i = 0; i < danhSachNV.size(); i++)
        {
            if (danhSachNV[i].getMaNV() == maNV)
            {
                danhSachNV[i].hienThiThongTin();
                cout << "*******************************************************" << endl;
                return;
            }
        }
        cout << "Khong tim thay nhan vien co ma " << maNV << endl;
        cout << "*******************************************************" << endl;
    }

    // Hàm hiển thị danh sách nhân viên
    void hienThiDanhSachNV()
    {
        cout << "Danh sach nhan vien:" << endl;
        cout << setw(7) << left << "Ma NV";
        cout << setw(25) << left << "Ten NV";
        cout << setw(5) << left << "GD";
        cout << setw(5) << left << "Con";
        cout << setw(10) << left << "Trinh do";
        cout << setw(13) << left << "Luong CB";
        cout << setw(5) << left << "CP";
        cout << setw(5) << left << "KP";
        cout << setw(5) << left << "LT";
        cout << setw(10) << left << "KQCV";
        cout << setw(10) << left << "LTL" << endl;
        cout << setfill('-');
        cout << setw(100) << "-" << endl;
        cout << setfill(' ');

        for (size_t i = 0; i < danhSachNV.size(); i++)
        {
            cout << setw(7) << left << danhSachNV[i].getMaNV();
            cout << setw(25) << left << danhSachNV[i].getTenNV();
            cout << setw(5) << left << danhSachNV[i].getTinhTrangGD();
            cout << setw(5) << left << danhSachNV[i].getSoCon();
            cout << setw(10) << left << danhSachNV[i].getTrinhDoVH();
            cout << setw(13) << left << danhSachNV[i].getLuongCB();
            cout << setw(5) << left << danhSachNV[i].getSoNgayNghiCoPhep();
            cout << setw(5) << left << danhSachNV[i].getSoNgayNghiKhongPhep();
            cout << setw(5) << left << danhSachNV[i].getSoNgayLamThem();
            cout << setw(10) << left << danhSachNV[i].getKetQuaCongViec();
            cout << setw(10) << left << danhSachNV[i].getLuongThucLinh() << endl;
        }
        cout << "*******************************************************" << endl;
    }

    // Hàm hiển thị bảng lương
    void hienThiBangLuong()
    {
        cout << "Bang luong hang thang:" << endl;
        cout << setw(7) << left << "Ma NV";
        cout << setw(28) << left << "Ten NV";
        cout << setw(10) << left << "Luong TL" << endl;
        cout << setfill('-');
        cout << setw(45) << "-" << endl;
        cout << setfill(' ');

        for (size_t i = 0; i < danhSachNV.size(); i++)
        {
            cout << setw(7) << left << danhSachNV[i].getMaNV();
            cout << setw(28) << left << danhSachNV[i].getTenNV();
            cout << setw(10) << left << danhSachNV[i].getLuongThucLinh() << endl;
        }
        cout << "*******************************************************" << endl;
    }
};