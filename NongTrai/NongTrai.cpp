#include <iostream>
#include <vector>
using namespace std;

class giaSuc{
public:
    int soluong;
    int litSua;
    
    giaSuc() : soluong(0), litSua(0) {}
    void nhap(){
        cin >> soluong;
    }
    virtual void xuat(){
        return;
    }
    virtual void SL_LS(int luot) {
        return;
    }
};

class bo : public giaSuc{
public:
    void nhap(){
        giaSuc::nhap();
    }
    void SL_LS(int luot) {
        int a[] = {0, 0, 0, 0};
        for (int i=1; i<=luot; i++){
            soluong = soluong+a[3];
            a[3] = a[2];
            a[2] = a[1];
            a[1] = a[0];
            a[0] = soluong/2;
            litSua = litSua+soluong*10;
        }
        soluong = soluong + a[0] + a[1] + a[2] + a[3];
    }
    
    void xuat(){
        cout <<"Bo: "<<soluong<<","<<litSua<<endl;
    }
};

class cuu : public giaSuc{
public:
    void nhap(){
        giaSuc::nhap();
    }
    void SL_LS(int luot) {
        int a[] = {0, 0, 0, 0};
        for (int i=1; i<=luot; i++){
            soluong = soluong+a[3];
            a[3] = a[2];
            a[2] = a[1];
            a[1] = a[0];
            a[0] = soluong/2;
            litSua = litSua+soluong*5;
        }
        soluong = soluong + a[0] + a[1] + a[2] + a[3];
    }
    void xuat(){
        cout <<"Cuu: "<<soluong<<","<<litSua<<endl;
    }
};

class de : public giaSuc{
public:
    void nhap(){
        giaSuc::nhap();
    }
    void SL_LS(int luot) {
        int a[] = {0, 0, 0, 0};
        for (int i=1; i<=luot; i++){
            soluong = soluong+a[3];
            a[3] = a[2];
            a[2] = a[1];
            a[1] = a[0];
            a[0] = soluong/2;
            litSua = litSua+soluong*8;
        }
        soluong = soluong + a[0] + a[1] + a[2] + a[3];
    }
    void xuat(){
        cout <<"De: "<<soluong<<","<<litSua<<endl;
    }
};
class tho : public giaSuc{
public:
    void nhap(){
        giaSuc::nhap();
    }
    void SL_LS(int luot) {
        int a[] = {0, 0};
        for (int i=1; i<=luot; i++){
            soluong = soluong+a[1];
            a[1] = a[0];
            a[0] = soluong/2;
            //litSua = litSua+soluong*10;
        }
        soluong = soluong + a[0] + a[1];
    }
    void xuat(){
        cout <<"Tho: "<<soluong<<","<<litSua<<endl;
    }
};

class quanly{
public:
    bo a;
    cuu b;
    de c;
    tho d;
    
    void nhap(){
        a.nhap();
        b.nhap();
        c.nhap();
        d.nhap();
    }
    void solve(int luot){
        a.SL_LS(luot);
        b.SL_LS(luot);
        c.SL_LS(luot);
        d.SL_LS(luot);
    }
    void xuat(){
        a.xuat();
        b.xuat();
        c.xuat();
        d.xuat();
    }
};
int main(){
    quanly farm;
    farm.nhap();
    int luot; cin >> luot;
    farm.solve(luot);
    farm.xuat();
    return 0;
}