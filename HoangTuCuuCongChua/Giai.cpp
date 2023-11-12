#include <iostream>
#include <vector>
using namespace std;

class gate{
protected:
    int loai;
public:
    gate(){
        loai = 0;
    }
    virtual void nhap(){
        cin >> loai;
    }
    int getloai(){
        return loai;
    }
    virtual int traVe(){
        return 0;
    }
};

class business_g : public gate{
protected:
    int donGia;
    int soHang;
public:
    business_g() {
        donGia = 0;
        soHang = 0;
    }
    
    void nhap(){
        //gate::nhap();
        loai = 1;
        cin >> donGia >> soHang;
    }
    int traVe(){
        return donGia*soHang;
    }
};
class academic_g : public gate{
protected:
    int triTue;
public:
    academic_g(){
        triTue = 0;
    }
    void nhap(){
        //gate::nhap();
        loai = 2;
        cin >> triTue;
    }
    int traVe(){
        return triTue;
    }
};
class power_g : public gate{
protected:
    int sucManh;
public:
    power_g(){
        sucManh=0;
    }
    void nhap(){
        //gate::nhap();
        loai = 3;
        cin >> sucManh;
    }
    int traVe(){
        return sucManh;
    }
};
class prince{

public:
    
    int tien;
    int triTue;
    int sucManh;
    
    prince() : tien(0), triTue(0), sucManh(0) {}
    bool kt(){
        if (tien>0 && triTue>0 && sucManh>0) return 1;
        return 0;
    }
    void nhap(){
        cin >> tien >> triTue >> sucManh;
    }
    void xuat(){
        cout << tien <<" "<< triTue <<" "<< sucManh<<endl;
    }
};
int main(){
    int n, loai;
    cin >> n;
    gate** g = new gate*[n];
    for (int i=0; i<n; i++){
        cin >> loai;
        if (loai==1){
            g[i] = new business_g();
        }
        else if (loai==2){
            g[i] = new academic_g();
        }
        else if (loai==3){
            g[i] = new power_g();
        }
        g[i]->nhap();
    }
    prince p;
    p.nhap();
    int j=0;
    while (p.kt()==1 && j<n){
        if (g[j]->getloai()==1){
            p.tien = p.tien - g[j]->traVe();
            if (p.tien<0) {
                cout <<-1;
                return 0;
            }
        }
        if(g[j]->getloai()==2){
            if (p.triTue<g[j]->traVe()){
                cout <<-1;
                return 0;
            }
        }
        if(g[j]->getloai()==3){
            p.sucManh = p.sucManh - g[j]->traVe();
            if (p.sucManh<0){
                cout <<-1;
                return 0;
            }
        }
        j++;
    }
    p.xuat();
    return 0;
}
