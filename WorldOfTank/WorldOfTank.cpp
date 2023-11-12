#include <iostream>
#include <string>
#include <vector>
using namespace std;


class ThapPhao{
public:
    float size;
    int num_ammos;
    
    virtual void nhap(){
        cin >> num_ammos;
    }
};
class ML20S : public ThapPhao{
public:
    void nhap(){
        size = 152;
        ThapPhao::nhap();
    }
};
class F34 : public ThapPhao{
public:
    void nhap(){
        size = 76.2;
        ThapPhao::nhap();
    }
};
class D25T : public ThapPhao{
public:
    void nhap(){
        size = 122;
        ThapPhao::nhap();
    }
};
class M65L : public ThapPhao{
public:
    void nhap(){
        size = 130;
        ThapPhao::nhap();
    }
};

class DongCo{
public:
    int hp;
    float xang;
    void nhap(){
        cin >> xang;
    }
};
class V2 : public DongCo {
public:
    V2(){
        hp = 500;
    }
};
class V2K : public DongCo {
public:
    V2K(){
        hp = 600;
    }
};
class a_2DG8M : public DongCo {
public:
    a_2DG8M(){
        hp=1000;
    }
};

class XeTang{
public:
    string type;
    int weight;
    int num_crews;
    ThapPhao* tp;
    DongCo* dc;
    double damage;
    double xangConLai;
    float hieuXuat;
    virtual void nhap(){
        cin >> weight;
        cin >> num_crews;
    }
    virtual void tinh_damge(int dan){};
    virtual void tinh_HieuXuat(int danBan){};
    virtual void xuat(){
        cout <<type<<", weight: "<<weight<<", number of crews: "<<num_crews<<", damage: "<<damage<<", performance: "<<hieuXuat<<"%"<<endl;
    }
};

class SU152 : public XeTang{
public:
    SU152(){
        type = "SU152";
    }
    void nhap(){
        XeTang::nhap();
        tp = new ML20S;
        tp->nhap();
        dc = new V2K;
        dc->nhap();
    }
    void tinh_damge(int dan){
        damage = (num_crews/4.0)*1.0*tp->size*1.0*(tp->num_ammos-dan);
    }
    void tinh_HieuXuat(int danBan){
        hieuXuat = 100*(tp->num_ammos-danBan)/(1.0*tp->num_ammos);
        if (hieuXuat<0) hieuXuat = 0;
    }
    
};
class KV2: public XeTang{
public:
    KV2(){
        type = "KV2";
    }
    void nhap(){
        XeTang::nhap();
        tp = new F34;
        tp->nhap();
        dc = new V2;
        dc->nhap();
    }
    void tinh_damge(int dan){
        damage = 3.0*tp->size*(tp->num_ammos-dan);
    }
    void tinh_HieuXuat(int danBan){
        hieuXuat = 100*(tp->num_ammos-danBan)/(1.0*tp->num_ammos);
        if (hieuXuat<0) hieuXuat = 0;
    }
    
};
class IS: public XeTang{
public:
    IS(){
        type = "IS";
    }
    void nhap(){
        XeTang::nhap();
        tp = new D25T;
        tp->nhap();
        dc = new V2K;
        dc->nhap();
    }
    void tinh_damge(int dan){
        damage = 3.0*tp->size*(tp->num_ammos-dan);
    }
    void tinh_xangConLai(int km_di){
        double xang_100km;
        xang_100km = 450.0/weight;
        xangConLai = 1.0*dc->xang - (km_di/100.0)*xang_100km;
    }
    void tinh_HieuXuat(int danBan){
        tinh_xangConLai(danBan);
        hieuXuat = 100*(1.0*xangConLai)/dc->xang;
    }
};
class Object279: public XeTang{
public:
    Object279(){
        type = "Object279";
    }
    void nhap(){
        XeTang::nhap();
        tp = new M65L;
        tp->nhap();
        dc = new a_2DG8M;
        dc->nhap();
    }
    void tinh_damge(int dan){
        damage = (1.0*num_crews/4.0)*tp->size*(tp->num_ammos-dan);
    }
    void tinh_HieuXuat(int danBan){
        hieuXuat = 100*num_crews/4.0;
    }
};

class DSxeTang{
public:
    vector<XeTang*> dsxt;
    int sl, loai;
    int km, dan;
    
    void nhap(){
       //cout <<"sl: ";
        cin >> sl;
        
        for (int i=0; i<sl; i++){
            //cout <<"loai: ";
            cin >> loai;
            if (loai==1){
                XeTang* a = new SU152;
                a->nhap();
                dsxt.push_back(a);
            }
            else if (loai==2){
                XeTang* a = new KV2;
                a->nhap();
                dsxt.push_back(a);
            }
            else if (loai==3){
                XeTang* a = new IS;
                a->nhap();
                dsxt.push_back(a);
            }
            else if (loai==4){
                XeTang* a = new Object279;
                a->nhap();
                dsxt.push_back(a);
            }
        }
        //cout <<"km va dan: ";
        cin >> km >> dan;
    }
    void tinh(){
        for (int i=0; i<sl; i++){
            dsxt[i]->tinh_damge(dan);
            if (dsxt[i]->type=="SU152" || dsxt[i]->type=="KV2")
                dsxt[i]->tinh_HieuXuat(dan);
            else if (dsxt[i]->type=="IS")
                dsxt[i]->tinh_HieuXuat(km);
            else if (dsxt[i]->type=="Object279")
                dsxt[i]->tinh_HieuXuat(0);
        }
        
    }
    void xuat(){
        for (int i=0; i<sl; i++){
            dsxt[i]->xuat();
        }
    }
};
int main(){
    DSxeTang a;
    a.nhap();
    a.tinh();
    a.xuat();
}