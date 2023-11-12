#include <iostream>
#include <vector>

using namespace std;

class matTham{
protected:
    int loai;
    int power;
public:
    matTham(){
        loai = 0;
        power = 0;
    }
    virtual void nhap(){
        //cin >> loai;
        cin >> power;
    }
    virtual int getLo(){
        return 0;
    }
    virtual int getPo(){
        return 0;
    }
    virtual void setPo(int p){
        power = p;
    }
    virtual int st(){ return 0;}
    virtual void xuat(){}
    virtual void du2loai(){}
    virtual void du2loai_1(){}
    virtual void tinhPower(int luot){}
    virtual void tinhPower_2(int luot){}
};

class shaco : public matTham{
public:
    int satThuong = 0;
    int st(){
        return satThuong;
    }
    int getLo(){
        return loai;
    }
    int getPo(){
        return power;
    }
    void setPo(int p){
        power = p;
    }
    void nhap(){
        loai = 1;
        matTham::nhap();
    }
    void xuat(){
        cout <<"Shaco - "<<satThuong;
        //cout <<"-" <<power;
        cout <<endl;
    }
    void du2loai(){
        power = power +10;
    }
    void du2loai_1(){
        satThuong = satThuong +10;
    }
    void tinhPower(int luot){
        for (int i=0;  i< luot; i++)
            satThuong = satThuong + power*2;
    }
    void tinhPower_2(int luot){
        for (int i=0;  i< luot; i++)
            satThuong = satThuong + (power+10)*2;
    }
    
};
class zed : public matTham{
public:
    int satThuong =0;
    int st(){
        return satThuong;
    }
    int getLo(){
        return loai;
    }
    int getPo(){
        return power;
    }
    void setPo(int p){
        power = p;
    }
    void nhap(){
        loai = 2;
        matTham::nhap();
    }
    void xuat(){
        cout <<"Zed - "<<satThuong;
        //cout <<"-" <<power;
        cout <<endl;
    }
    void du2loai(){
        power = power+10;
    }
    void du2loai_1(){
        satThuong = satThuong +10;
    }
    void tinhPower(int luot){
        int x=1;
        while (luot>0){
            if (x==3){
                satThuong = satThuong + power*3;
                x = 1;
            }
            else{
                satThuong = satThuong + power;
                x++;
            }
            luot--;
        }
    }
    void tinhPower_2(int luot){
        int x=1;
        while (luot>0){
            if (x==3){
                satThuong = satThuong + (power+10)*3;
                x = 1;
            }
            else{
                satThuong = satThuong + (power+10);
                x++;
            }
            luot--;
        }
    }
};
int main(){
    int n; cin >> n;
    int luot; cin >> luot;
    matTham** a = new matTham*[n];
    int loai;
    int loai1=0;
    int loai2=0;
    for (int i=0; i<n; i++){
        cin >> loai;
        if (loai == 1){
            loai1++;
            a[i] = new shaco();
        }
        if (loai == 2){
            loai2++;
            a[i] = new zed();
        }
        a[i]->nhap();
    }
//    if (loai1!=0 && loai2!=0){
//        for (int i=0; i<n; i++){
//            a[i]->du2loai();
//        }
//    }
    
    
    
    int sao2 = loai1/3;
    matTham** s2 = new matTham*[sao2];
    
    int sao3 = sao2/3;
    matTham** s3 = new matTham*[sao3];
    
    
    if (loai1<3){
        if (loai1!=0 && loai2!=0){
            for (int i=0; i<n; i++){
                if (a[i]->getLo()==1) a[i]->tinhPower_2(luot);
            }
        }
        else {
            for (int i=0; i<n; i++){
                if (a[i]->getLo()==1) a[i]->tinhPower(luot);
            }
        }
    }
    else {
        int d=0; int tong=0;
        int i,j=0;
        for (int t=0; t<sao2; t++){
            for (i=j; i<n; i++){
                if (d==3) {
                    d=0;
                    break;
                }
                if (a[i]->getLo()==1){
                    tong = tong + a[i]->getPo();
                    d++;
                    //a[i] = NULL;
                    a[i]->setPo(0);
                }
            }
            j=i;
            s2[t] = new shaco();
            s2[t]->setPo(tong*2);
            if (loai2!=0) s2[t]->tinhPower_2(luot);
            else s2[t]->tinhPower(luot);
            tong=0;
        }
        
        if (sao2>=3){
            int d=0; int tong=0;
            int i,j=0;
            for (int t=0; t<sao3; t++){
                for (i=j; i<sao2; i++){
                    if (d==3) {
                        d=0;
                        break;
                    }
                    tong = tong + s2[i]->getPo();
                    d++;
                    //s2[i] = NULL;
                    s2[i]->setPo(0);
                }
                j=i;
                s3[t] = new shaco();
                s3[t]->setPo(tong*3);
                if (loai2!=0) s3[t]->tinhPower_2(luot);
                else s3[t]->tinhPower(luot);
                tong=0;
            }
        }
        
    }
    
    
    
    int sao2_2 = loai2/3;
    matTham** s2_2 = new matTham*[sao2_2];
    int sao3_2 = sao2/3;
    matTham** s3_2 = new matTham*[sao3_2];
    if (loai2<3){
        if (loai1!=0 && loai2!=0){
            for (int i=0; i<n; i++){
                if (a[i]->getLo()==2) a[i]->tinhPower_2(luot);
            }
        }
        else {
            for (int i=0; i<n; i++){
                if (a[i]->getLo()==2) a[i]->tinhPower(luot);
            }
        }
    }
    else {
        int d=0; int tong=0;
        int i,j=0;
        for (int t=0; t<sao2_2; t++){
            for (i=j; i<n; i++){
                if (a[i]->getLo()==2){
                    if (d==3) {
                        d=0;
                        break;
                    }
                    tong = tong + a[i]->getPo();
                    d++;
                    //a[i] = NULL;
                    a[i]->setPo(0);
                }
                
            }
            j=i;
            s2_2[t] = new zed();
            s2_2[t]->setPo(tong*2);
            if (loai1!=0) s2_2[t]->tinhPower_2(luot);
            else s2_2[t]->tinhPower(luot);
            tong=0;
        }
        if (sao2>=3){
            int d=0; int tong=0;
            int i,j=0;
            for (int t=0; t<sao3_2; t++){
                for (i=j; i<sao2_2; i++){
                    if (d==3) {
                        d=0;
                        break;
                    }
                    tong = tong + s2_2[i]->getPo();
                    d++;
                    //s2[i] = NULL;
                    s2_2[i]->setPo(0);
                    
                }
                j=i;
                s3_2[t] = new zed();
                s3_2[t]->setPo(tong*3);
                if (loai1!=0) s3_2[t]->tinhPower_2(luot);
                else s3_2[t]->tinhPower(luot);
                tong=0;
            }
        }
        
    }
//    for (int i=0; i<sao2_2; i++){
//        s2_2[i]->xuat();
//    }
//    cout <<endl;
//    for (int i=0; i<sao3_2; i++){
//        s3_2[i]->xuat();
//    }
//    cout <<endl;
//    for (int i=0; i<n; i++){
//        a[i]->xuat();
//    }
//    cout <<endl;

    
    for (int i=0; i<n; i++){
        if (a[i]->getPo()!=0 && a[i]->st()==0)
            a[i]->tinhPower(luot);
    }
    
    int d=0;
    int dd=0;
    int ss1=0, ss2=0, ss3=0, ss4=0;
    for (int i=0; i<n; i++){
        
        if (a[i]->getPo()==0){
            if (a[i]->getLo()==1){
                d++;
            
            }
            if (a[i]->getLo()==2){
                dd++;
                
            }
        }
        else{
            a[i]->xuat();
        }
        
        if (d==3 && sao3>0){
            s3[ss1++]->xuat();
            d=0;
            sao3--;
        }
        if (dd==3 && sao3_2>0){
            s3_2[ss2++]->xuat();
            dd=0;
            sao3_2--;
        }
        if (d==3 && sao2>0){
            s2[ss3++]->xuat();
            d=0;
            sao2--;
        }
        if (dd==3 && sao2_2>0){
            s2_2[ss4++]->xuat();
            dd=0;
            sao2_2--;
        }
    }

    return 0;
}