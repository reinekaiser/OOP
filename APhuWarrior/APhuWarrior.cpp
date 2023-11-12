#include <iostream>
#include <string>
#include <vector>
using namespace std;

class VuKhi{
public:
    float satThuong_moiluot;
    float csst;
    int slsd;
    int type;
    virtual void nhap(){
        cin >> csst;
        cin >> slsd;
    }
    virtual void tinh_st(){}
    virtual void xuat(){
        cout <<type<<" csst "<<csst<<" slsd "<<slsd;
    }
};
class Dao : public VuKhi{
public:
    float chieuDai;
    
    Dao(){
        type = 1;
    }
    void nhap(){
        VuKhi::nhap();
        cin >> chieuDai;
    }
    void tinh_st(){
        satThuong_moiluot = csst*chieuDai;
    }
    void xuat(){
        VuKhi::xuat();
        cout<<" chieudai "<< chieuDai<<endl;
    }
    
};
class CungTen : public VuKhi{
public:
    int soMuiTen;
    
    CungTen(){
        type = 2;
    }
    void nhap(){
        VuKhi::nhap();
        cin >> soMuiTen;
    }
    void tinh_st(){
        satThuong_moiluot = csst*(soMuiTen/2.0);
    }
    void xuat(){
        VuKhi::xuat();
        cout<<" somuiten "<<soMuiTen<<endl;
    }
};
class TayKhong : public VuKhi{
public:
    TayKhong(){
        type = 3;
    }
    friend class APhu;
};


class ThuDu{
public:
    float hp;
    float csst;
    int type;
    float satThuong_moiluot;
    virtual void nhap(){
        cin >> hp;
        cin >> csst;
    }
    virtual void tinh_st(){}
    virtual void tinh_hp(float atk){}
    virtual void xuat(){
        cout <<type<<" hp "<<hp<<" csst "<<csst<<" ";
    }
    virtual bool isALive(){
        return 0;
    }
};

class BoTot : public ThuDu{
public:
    int slcd;
    BoTot(){
        type = 1;
    }
    void nhap(){
        ThuDu::nhap();
        cin >> slcd;
    }
    void tinh_st(){
        satThuong_moiluot = csst;
    }
    void tinh_hp(float atk){
        hp = hp - atk;
        --slcd;
    }
    bool isALive(){
        if (hp>0 && slcd>0) return 1;
        return 0;
    }
    void xuat(){
        ThuDu::xuat();
        cout<<"slcd "<<slcd<<endl;
    }
};
class Ho : public ThuDu{
public:
    Ho(){
        type=2;
    }
    void nhap(){
        ThuDu::nhap();
    }
    void tinh_st(){
        satThuong_moiluot = 1.5*csst;
    }
    void tinh_hp(float atk){
        hp = hp - atk;
    }
    void xuat(){
        ThuDu::xuat();
        cout <<endl;
    }
    bool isALive(){
        if (hp>0) return 1;
        return 0;
    }
};
class APhu{
public:
    float hp;
    float cp_hp;
    int n;
    vector<VuKhi*> dsvk;
    
    void nhap(){
        int loai;
        cin >> hp;
        cp_hp = hp;
        cin >> n;
        for (int i=0; i<n; i++){
            cin >> loai;
            if (loai==1){
                VuKhi* a = new Dao;
                a->nhap();
                dsvk.push_back(a);
            }
            else if (loai==2){
                VuKhi* a = new CungTen;
                a->nhap();
                dsvk.push_back(a);
            }
        }
    }
    void xuat(){
        cout <<"hp aphu "<<hp<<" n "<<n<<endl;
        for (int i=0; i<dsvk.size(); i++){
            dsvk[i]->xuat();
        }
    }
    float st_taykhong(){
        int satThuong_moiluot;
        satThuong_moiluot = 0.1*cp_hp;
        hp = hp - satThuong_moiluot;
        return satThuong_moiluot;
    }
    void tinh_hp(float atk){
        hp = hp - atk;
    }
};
class QuanLy{
public:
    APhu a;
    vector<ThuDu*> dstd;
    int sl_thudu;
    void nhap(){
        int loai;
        a.nhap();
        cin >> sl_thudu;
        for (int i=0; i<sl_thudu; i++){
            cin >> loai;
            if (loai==1){
                ThuDu* x = new BoTot;
                x->nhap();
                dstd.push_back(x);
            }
            else if (loai==2){
                ThuDu* x = new Ho;
                x->nhap();
                dstd.push_back(x);
            }
        }
    }
    void xuat_all(){
        a.xuat();
        for (int i=0; i<sl_thudu; i++){
            dstd[i]->xuat();
        }
    }
    void battle(){
        int i=0;
        int vk=0;
        while (a.hp>0 && i<sl_thudu){
            
            if (a.dsvk.size()==0 && a.hp>0){
                
                int tk = a.st_taykhong();
                //cout <<tk<<endl;
                dstd[i]->tinh_hp(tk);
            }
            else{
                
                a.dsvk[vk]->tinh_st();
                //cout <<a.dsvk[vk]->satThuong_moiluot<<endl;
                dstd[i]->tinh_hp(a.dsvk[vk]->satThuong_moiluot);
                if (a.dsvk[vk]->type==1) a.dsvk[vk]->slsd = a.dsvk[vk]->slsd -1;
                else if (a.dsvk[vk]->type==2) a.dsvk[vk]->slsd = a.dsvk[vk]->slsd -2;
                if (a.dsvk[vk]->slsd<=0){
                    a.dsvk.erase(a.dsvk.begin()+vk);
                }
            }
            
            if(dstd[i]->isALive()==1){
                dstd[i]->tinh_st();
                a.tinh_hp(dstd[i]->satThuong_moiluot);
            }
            else if(dstd[i]->isALive()==0) i++;
        }
    }
    void kq(){
        if (a.hp>0) {
            cout <<"A Phu chien thang, hp con lai: "<<a.hp;
            cout <<", so vu khi con lai: "<<a.dsvk.size()<<endl;
        }
        else {
            int tdcl=0;
            for (int i=0; i<dstd.size(); i++){
                if (dstd[i]->isALive()==1) tdcl++;
            }
            cout <<"A Phu that bai, so thu du con lai: "<<tdcl<<endl;
        }
    }
};
int main(){
    QuanLy a;
    a.nhap();
    a.battle();
   // a.xuat_all();
    a.kq();
}

