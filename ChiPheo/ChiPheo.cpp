#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const double Pi = 3.14;
class Hinh
{
private:
    double chieucao;
    double S;
    double V;

public:
    Hinh()
    {
        chieucao = 0;
        S = 0;
        V = 0;
    }
    virtual void Nhap()
    {
        cin >> chieucao;
    }
    virtual void Xuat()
    {
        cout << chieucao << " ";
    }
    double getChieucao()
    {
        return chieucao;
    }
    virtual double DienTich()
    {
        return S;
    }
    virtual double TheTich()
    {
        return V;
    }
};

class Hinh_tru_tron : public Hinh
{
private:
    double ban_kinh;

public:
    Hinh_tru_tron()
    {
        ban_kinh = 0;
    }
    void Nhap()
    {
        Hinh::Nhap();
        cin >> ban_kinh;
    }
    void Xuat()
    {
        Hinh::Xuat();
        cout << ban_kinh << endl;
    }
    double DienTich()
    {
        return 2 * ban_kinh * Pi * Hinh::getChieucao();
    }
    double TheTich()
    {
        return Pi * ban_kinh * ban_kinh * getChieucao();
    }
};

class Hinh_hop_ChuNhat : public Hinh
{
private:
    // chieu cao x
    double chieudai;
    double chieurong;

public:
    Hinh_hop_ChuNhat()
    {
        chieudai = 0;
        chieurong = 0;
    }
    void Nhap()
    {
        Hinh::Nhap();
        cin >> chieudai >> chieurong;
    }
    void Xuat()
    {
        Hinh::Xuat();
        cout << chieudai << " " << chieurong << endl;
    }
    double DienTich()
    {
        return (chieudai + chieurong) * 2 * getChieucao() + chieudai * chieurong * 2;
    }
    double TheTich()
    {
        return chieudai * chieurong * getChieucao();
    }
};

class Hinh_LapPhuong : public Hinh
{
private:
    // chieu cao x
public:
    Hinh_LapPhuong() {}
    void Nhap()
    {
        Hinh::Nhap();
    }
    void Xuat()
    {
        Hinh::Xuat();
        cout << endl;
    }
    double DienTich()
    {
        return getChieucao() * 4 * getChieucao() + getChieucao() * getChieucao() * 2;
    }
    double TheTich()
    {
        return getChieucao() * getChieucao() * getChieucao();
    }
};

class Quanly
{

    int sl;
    double Tong_S;
    double Tong_V;
    Hinh **h;

public:
    Quanly()
    {
        sl = 0;
        Tong_S = 0;
        Tong_V = 0;
    }
    void Nhap()
    {
        cin >> sl;
        h = new Hinh *[sl];
        int type;
        for (int i = 0; i < sl; i++)
        {
            cin >> type;
            if (type == 1)
            {
                h[i] = new Hinh_tru_tron;
            }
            else if (type == 2)
            {
                h[i] = new Hinh_hop_ChuNhat;
            }
            else if (type == 3)
            {
                h[i] = new Hinh_LapPhuong;
            }

            h[i]->Nhap();
            Tong_S += h[i]->DienTich();
            Tong_V += h[i]->TheTich();
        }
    }
    void Xuat()
    {
        cout << "Dien tich chai vo: " << Tong_S << endl;
        cout << "Luong nuoc tren mat dat: " << Tong_V * 0.1;
    }
};

int main()
{
   // freopen("lap4.inp", "r", stdin);
    Quanly ql;
    ql.Nhap();
    ql.Xuat();
}