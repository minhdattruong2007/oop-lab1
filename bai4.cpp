#include <bits/stdc++.h>
using namespace std;

bool kiemtra(string s){ // kiem tra chuoi co phai so khong
    int i = 0;
    if(s[0] == '-'){
        if(s.length() == 1) return false;
        i = 1;
    }
    for(; s[i] != '\0'; i++){
        if(s[i] < '0' || s[i] > '9') return false;
    }
    return true;
}
bool namnhuan(int y){ // kiem tra nam nhuan
    if((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0))
        return true;
    return false;
}
int songay(int m, int y){ // tra ve so ngay trong thang
    if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
        return 31;

    if(m==4||m==6||m==9||m==11)
        return 30;

    if(m==2){
        if(namnhuan(y))
            return 29;
        else
            return 28;
    }
    return 0;
}
int main(){
    string d,m,y;
    while(1){
        cin >> d >> m >> y;
        // kiem tra dinh dang so
        if(!kiemtra(d) || !kiemtra(m) || !kiemtra(y)){
            cout<<"yeu cau nhap lai"<<endl;
            continue;
        }
        int day = stoi(d);
        int month = stoi(m);
        int year = stoi(y);

        // kiem tra thang hop le
        if(month < 1 || month > 12){
            cout<<"yeu cau nhap lai"<<endl;
            continue;
        }
        int maxday = songay(month,year);
        // kiem tra ngay hop le
        if(day < 1 || day > maxday){
            cout<<"yeu cau nhap lai"<<endl;
            continue;
        }
        // tim ngay ke tiep
        day++;
        // neu vuot qua so ngay cua thang thi sang thang moi
        if(day > maxday){
            day = 1;
            month++;
            // neu vuot qua thang 12 thi sang nam moi
            if(month > 12){
                month = 1;
                year++;
            }
        }
        cout<<day<<" "<<month<<" "<<year;
        break;
    }
    return 0;
}
