#include "quanLyNV.h"

enum luaChon
{
    themNV = 1,
    xoaNV,
    suaNV,
    timNV,
    hienThiDS,
    hienThiBL,
};

int main()
{
    quanLyNV qlnv;

    int chon;

    while (true)
    {
        cout << "CHUONG TRINH QUAN LY NHAN VIEN:" << endl;
        cout << "1. Them nhan vien" << endl;
        cout << "2. Xoa nhan vien" << endl;
        cout << "3. Sua thong tin nhan vien" << endl;
        cout << "4. Tim nhan vien" << endl;
        cout << "5. Hien thi danh sach nhan vien" << endl;
        cout << "6. Hien thi bang luong" << endl;
        cout << "0. Thoat" << endl;
        cout << "Chon: ";
        cin >> chon;
        switch ((luaChon)chon)
        {
        case themNV:
        {
            qlnv.themNV();
            break;
        }
        case xoaNV:
        {
            string ma;
            cout << "Nhap ma nhan vien muon xoa: ";
            cin >> ma;
            qlnv.xoaNV(ma);
            break;
        }
        case suaNV:
        {
            string ma;
            cout << "Nhap ma nhan vien muon sua thong tin: ";
            cin >> ma;
            qlnv.suaNV(ma);
            break;
        }
        case timNV:
        {
            string ma;
            cout << "Nhap ma nhan vien muon tim thong tin: ";
            cin >> ma;
            qlnv.timNV(ma);
            break;
        }
        case hienThiDS:
        {
            qlnv.hienThiDanhSachNV();
            break;
        }
        case hienThiBL:
        {
            qlnv.hienThiBangLuong();
            break;
        }
        default:
            break;
        }
        if (chon == 0)
        {
            break;
        }
    }

    return 0;
}