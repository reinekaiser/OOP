#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Member{
public:
    string ten;
    float hp;
    float atk;
    float def;
    int type;
    virtual void nhap(){
        cin >> ten;
        cin >> hp;
        cin >> atk;
        cin >> def;
    }
    void xuat(){
        cout <<ten<<" "<<hp<<endl;
    }
    virtual void tinh_atk(int num){}
};
//----------
class NhanLoai : public Member{
public:
    string job;
    virtual void nhap(){
        Member::nhap();
        cin >> job;
    }
};
class Human : public NhanLoai{
public:
    Human(){
        type = 1;
    }
    void nhap(){
        NhanLoai::nhap();
    }
};
class Elf : public NhanLoai{
public:
    Elf(){
        type = 2;
    }
    void nhap(){
        NhanLoai::nhap();
        def = def + 0.5*def;
    }
};
//----------
class BanNhan : public Member{
public:
    string racial;
    virtual void nhap(){
        Member::nhap();
        cin >> racial;
    }
};
class Orc : public BanNhan{
public:
    Orc(){
        type = 3;
        
    }
    void nhap(){
        BanNhan::nhap();
        hp = hp + 0.5*hp;
    }
};
class Golbin : public BanNhan{
public:
    Golbin(){
        type = 4;
        
    }
    void nhap(){
        BanNhan::nhap();
        atk = atk + 0.1*atk;
    }
};
//---------
class DiHinh : public Member{
public:
    virtual void nhap(){
        Member::nhap();
    }
};
class Vampire : public DiHinh{
public:
    Vampire(){
        type = 5;
    }
    void nhap(){
        DiHinh::nhap();
    }
    void tinh_atk(int num_human){
        hp = hp + 0.1*hp*num_human;
    }
};
class Devil : public DiHinh{
public:
    Devil(){
        type = 6;
    }
    void nhap(){
        DiHinh::nhap();
    }
    void tinh_atk(int num_devil){
        atk = atk + 0.1*atk*num_devil;
        def = def + 0.1*def*num_devil;
    }
};
class Boss{
public:
    string ten;
    float hp;
    float atk;
    float def;
    
    void nhap(){
        cin >> ten;
        cin >> hp;
        cin >> atk;
        cin >> def;
    }
    void xuat(){
        cout <<ten<<" "<<hp;
    }
};
class Guild{
public:
    vector<Member*> g;
    Boss b;
    int sl;
    int num_dan;
    int num_del;
    
    void nhap(){
        int loai;
        cin >> sl;
        for (int i=0; i<sl; i++){
            cin >> loai;
            if (loai==1){
                Member* a = new Human;
                a->nhap();
                g.push_back(a);
            }
            else if (loai==2){
                Member* a = new Elf;
                a->nhap();
                g.push_back(a);
            }
            else if (loai==3){
                Member* a = new Orc;
                a->nhap();
                g.push_back(a);
            }
            else if (loai==4){
                Member* a = new Golbin;
                a->nhap();
                g.push_back(a);
            }
            else if (loai==5){
                Member* a = new Vampire;
                a->nhap();
                g.push_back(a);
            }
            else if (loai==6){
                Member* a = new Devil;
                a->nhap();
                g.push_back(a);
            }
        }
        b.nhap();
    }
    
    void tinh(){
        num_dan=0;
        num_del=0;
        for (int i=0; i<sl; i++){
            if (g[i]->type==1) num_dan++;
            if (g[i]->type==6) num_del++;
        }
        
        for (int i=0; i<sl; i++){
            if (g[i]->type==5) g[i]->tinh_atk(num_dan);
            if (g[i]->type==6) g[i]->tinh_atk(num_del);
        }
    }
    void sort(){
        for (int i=0; i<sl-1; i++){
            int min = i;
            for (int j=i+1; j<sl; j++)
                if (g[j]->hp<g[min]->hp) min = j;
            swap(g[i], g[min]);
        }
    }
    
    void xuat(){
        for (int i=0; i<sl; i++){
            g[i]->xuat();
        }
    }
    void battle(){
        int i=0;
        while (i<sl && b.hp>0){
            for(int i=0; i<sl; i++){
                if (g[i]->atk>b.def && g[i]->hp>0) b.hp = b.hp - (g[i]->atk-b.def);
            }
            if (b.hp<=0){
                b.hp = 0;
                break;
            }
            if (b.atk>g[i]->def) g[i]->hp = g[i]->hp - (b.atk - g[i]->def);
            if (g[i]->hp<=0){
                g[i]->hp=0;
                i++;
            }
        }
        if (i==sl){
            b.xuat();
            return;
        }
        else if (i<sl){
            for (int i=0; i<sl; i++){
                if (g[i]->hp!=0)
                    g[i]->xuat();
                
            }
        }
    }
};
int main(){
    Guild a;
    a.nhap();
    a.tinh();
    a.sort();
//    cout <<endl;
//    a.xuat();
//    cout <<endl;
    a.battle();
    
}

