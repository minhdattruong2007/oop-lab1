#include <bits/stdc++.h>
using namespace std;

bool kiemtra(string s){
    // kiem tra chuoi co phai so khong (cho phep dau cham)
    int dot = 0;

    for(int i = 0; i < s.length(); i++){
        if(s[i] == '.'){
            dot++;
            if(dot > 1) return false;
        }
        else if(s[i] < '0' || s[i] > '9'){
            return false;
        }
    }

    return true;
}

int main(){

    string hoten;
    string toan, van;

    while(1){

        // nhap ho ten
        getline(cin, hoten);

        // nhap diem
        cin >> toan >> van;

        // kiem tra diem co phai so khong
        if(!kiemtra(toan) || !kiemtra(van)){
            cout<<"yeu cau nhap lai"<<endl;
            cin.ignore();
            continue;
        }

        float d_toan = stof(toan);
        float d_van = stof(van);

        // kiem tra diem hop le
        if(d_toan < 0 || d_toan > 10 || d_van < 0 || d_van > 10){
            cout<<"yeu cau nhap lai"<<endl;
            cin.ignore();
            continue;
        }

        // tinh diem trung binh
        float dtb = (d_toan + d_van) / 2;

        // xuat ket qua
        cout<<"Ho ten: "<<hoten<<endl;
        cout<<"Diem trung binh: "<<dtb;

        break;
    }

    return 0;
}

