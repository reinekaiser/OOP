#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Phong{
public:
    int loai;
    string ten;
    int tang;
    int soPhong;
    int sucChua;
    
    virtual void nhap(){
        cin >> ten;
        cin >> tang;
        cin >> soPhong;
        cin >> sucChua;
    }
    virtual void xuat(){
        cout <<ten<<" "<<tang<<" "<<soPhong<<" "<<sucChua<<" ";
    }
};
class LyThuyet : public Phong{
public:
    bool isMayLanh;
    
    void nhap(){
        loai = 1;
        Phong::nhap();
        cin >> isMayLanh;
    }
    void xuat(){
        Phong::xuat();
        cout <<isMayLanh<<endl;
    }
};
class ThucHanh : public Phong{
public:
    int soMay;
    
    void nhap(){
        loai = 2;
        Phong::nhap();
        cin >> soMay;
    }
    void xuat(){
        Phong::xuat();
        cout <<soMay<<endl;
    }
};
class GiangDuong : public Phong{
public:
    int soMayChieu;
    
    void nhap(){
        loai = 3;
        Phong::nhap();
        cin >> soMayChieu;
    }
    void xuat(){
        Phong::xuat();
        cout <<soMayChieu<<endl;
    }
};

class DSphong {
public:
    vector<Phong*> dsp;
    int sl;
    int k;
    void nhap(){
        int loai;
        cin >> sl;
        for (int i=0; i<sl; i++){
            cin >> loai;
            if (loai==1){
                Phong* a = new LyThuyet;
                a->nhap();
                dsp.push_back(a);
            }
            else if (loai==2){
                Phong* a = new ThucHanh;
                a->nhap();
                dsp.push_back(a);
            }
            else if (loai==3){
                Phong* a = new GiangDuong;
                a->nhap();
                dsp.push_back(a);
            }
        }
        cin >> k;
    }
    int tinh_tongSucChua(){
        int s=0;
        for (int i=0; i<sl; i++){
            s = s + dsp[i]->sucChua;
        }
        return s;
    }
    void xuat_PhongKhitNhat(){
        Phong* kk = new Phong;
        kk = NULL;
        for (int i=0; i<sl; i++){
            if (dsp[i]->sucChua<k) continue;
            else {
                kk = dsp[i];
                break;
            }
        }
        //
        //cout <<kk->ten<<endl;
        //
        if (kk==NULL) {cout <<"NULL"; return;}
        for (int i=0; i<sl; i++){
            if (dsp[i]->sucChua<kk->sucChua && dsp[i]->sucChua>=k) kk = dsp[i];
            else if (dsp[i]->sucChua==kk->sucChua){
                if (dsp[i]->tang==kk->tang){
                    if (dsp[i]->soPhong<kk->soPhong) kk = dsp[i];
                }
                else if (dsp[i]->tang<kk->tang) kk = dsp[i];
            }
        }
        if (kk==NULL) cout <<"NULL";
        else cout <<kk->ten;
    }
    
};
int main(){
    DSphong A;
    A.nhap();
    cout << A.tinh_tongSucChua()<<endl;
    A.xuat_PhongKhitNhat();
}