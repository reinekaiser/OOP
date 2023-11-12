#include <iostream>
#include <string>
using namespace std;

class CPU{
public:
    string ma_cpu;
    int gia;
    int core;
    float xung;
    string hang;
    string loai;
    void nhap_cpu(){
        
        cin >> ma_cpu;
    }
};
class Alpha : public CPU{
public:
    Alpha(){
        loai = "Alpha";
        gia = 200;
        core = 2;
        xung = 1.8;
        hang = "Black";
    }
};
class Beta : public CPU{
public:
    Beta(){
        loai = "Beta";
        gia = 400;
        core = 4;
        xung = 2.46;
        hang = "Black";
    }
};
class Gamma : public CPU{
public:
    Gamma(){
        loai = "Gamma";
        gia = 600;
        core = 4;
        xung = 2.6;
        hang = "White";
    }
};
//----------------------------------------
class ManHinh{
public:
    string ma_mh;
    string hang;
    string phanGiai;
    int loa;
    int gia;
    ManHinh(){}
    ManHinh(string m, string h, int p, int l){
        ma_mh = m;
        hang = h;
        phanGiai = p;
        loa = l;
    }
};
class HD : public ManHinh{
public:
    HD(){
        gia = 200;
    };
    HD(string m, string h, int p){
        ma_mh = m;
        hang = h;
        phanGiai = "HD";
        gia = 200;
    }
    
};
class FullHD : public ManHinh{
public:
    FullHD(){}
    FullHD(string m, string h, int p, int l){
        ma_mh = m;
        hang = h;
        phanGiai = "FullHD";
        loa = l;
        if (loa==0){
            gia = 300;
        }
        else gia = 500;
    }
    
};
//----------------------------------------
class vo_Smartphone{
public:
    string ma_vo;
    string hang;
    string mau;
    string loai;
    int gia;
    
    virtual void nhap_vo(){
        
        cin >> ma_vo;
    }
};
class voNhom : public vo_Smartphone{
public:
    int m;
    voNhom(){
        loai = "Nhom";
    }
    void nhap_vo(){
        vo_Smartphone::nhap_vo();
        
        cin >> m;
        if (m==1){
            mau = "Do";
        }
        if (m==2){
            mau = "Den";
        }
        gia = 400;
        hang = "Black";
    }
};
class voNhua : public vo_Smartphone{
public:
    int m;
    voNhua(){
        loai = "Nhua";
    }
    void nhap_vo(){
        vo_Smartphone::nhap_vo();
        
        cin >> m;
        if (m==1){
            mau = "Do";
        }
        if (m==2){
            mau = "Den";
        }
        if (m==3){
            mau = "Xanh";
        }
        gia = 200;
        hang = "White";
    }
};
//----------------------------------------
class Smartphone{
public:
    string ma_sm;
    string dong;
    CPU* a;
    ManHinh* b;
    vo_Smartphone* c;
    int linhKien;
    double giaTien;
    virtual void nhap_sm(){
        
        cin >> ma_sm;
    }
    void gia_linhkien(){
        linhKien = c->gia + a->gia + b->gia;
    }
    virtual void tinh_giaTien(){}
    void xuat_sm(){
        cout <<"Smartphone: "<<ma_sm<<" "<<dong<<" "<<giaTien<<endl;
        cout <<"CPU: "<<a->ma_cpu<<" "<<a->loai<<" "<<a->hang<<" "<<a->core<<" "<<a->xung<<" "<<a->gia<<endl;
        cout <<"Man hinh: "<<b->ma_mh<<" "<<b->hang<<" "<<b->phanGiai<<" "<<b->gia<<" ";
        if (b->loa!=0) cout <<b->loa;
        cout <<endl;
        cout <<"Vo smartphone: "<<c->ma_vo<<" "<<c->loai<<" "<<c->hang<<" "<<c->mau<<" "<<c->gia<<endl;
    }
    
};
class Venus : public Smartphone{
public:
    Venus(){
        dong = "Venus";
    }
    void nhap_sm(){
        Smartphone::nhap_sm();
        int loai;
        
        
        cin >> loai;
        if (loai == 1){
            a = new Alpha();
        }
        if (loai == 2){
            a = new Beta();
        }
        a->nhap_cpu();
        
        string ma_mh1, hang1;
        
        cin >> ma_mh1;
        
        cin >> hang1;
        
        cin >> loai;
        if (loai == 1){
            b = new HD(ma_mh1, hang1, 1);
        }
        if (loai == 2){
            int loa;
            
            cin >> loa;
            b = new FullHD(ma_mh1, hang1, 2, loa);
        }
        
        cin >> loai;
        if (loai == 1){
            c = new voNhom();
        }
        if (loai == 2){
            c = new voNhua();
        }
        c->nhap_vo();
    }
    void tinh_giaTien(){
        gia_linhkien();
        giaTien = 1.3*linhKien;
    }
};
class Mars : public Smartphone{
public:
    Mars(){
        dong = "Mars";
    }
    void nhap_sm(){
        Smartphone::nhap_sm();
        int loai;
        
        
        cin >> loai;
        if (loai == 1){
            a = new Alpha();
        }
        if (loai == 2){
            a = new Beta();
        }
        if (loai == 3){
            a = new Gamma();
        }
        a->nhap_cpu();
        
        string ma_mh1, hang1;
        
        cin >> ma_mh1;
        
        cin >> hang1;
        int loa;
        
        cin >> loa;
        b = new FullHD(ma_mh1, hang1, 2, loa);
        
        c = new voNhom();
        c->nhap_vo();
    }
    void tinh_giaTien(){
        gia_linhkien();
        giaTien = 1.5*linhKien;
    }
};
class Jupiter : public Smartphone{
public:
    Jupiter(){
        dong = "Jupiter";
    }
    void nhap_sm(){
        Smartphone::nhap_sm();
        a = new Gamma();
        a->nhap_cpu();
        
        string ma_mh1, hang1;
        
        cin >> ma_mh1;
        
        cin >> hang1;
        b = new FullHD(ma_mh1, hang1, 2, 1);
        
        c = new voNhom();
        c->nhap_vo();
    }
    void tinh_giaTien(){
        gia_linhkien();
        giaTien = 1.8*linhKien;
    }
};


int main(){
    int n;
    
    cin >> n;
    Smartphone** s = new Smartphone*[n];
    for(int i=0; i<n; i++){
        int loai;
        
        cin >> loai;
        if (loai==1){
            s[i] = new Venus();
            s[i]->nhap_sm();
        }
        if (loai==2){
            s[i] = new Mars();
            s[i]->nhap_sm();
        }
        if (loai==3){
            s[i] = new Jupiter();
            s[i]->nhap_sm();
        }
    }
    
    for (int i=0; i<n; i++){
        s[i]->tinh_giaTien();
        s[i]->xuat_sm();
        
    }
}