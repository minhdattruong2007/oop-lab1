#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){ // tim ucln
    while(b != 0){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
bool kiemtra(string s){ // kiem tra xem co phai so khong
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
void rutgon(int &a, int &b){
    int g = gcd(a,b);
    a /= g;
    b /= g;

    if(b < 0){
        a = -a;
        b = -b;
    }
}
int main(){
    string a,b,c,d;

    while(1){
        cout << "nhap tu so va mau so cua phan so thu nhat: ";
        cin >> a >> b;
        cout << "nhap tu so va mau so cua phan so thu hai: ";
        cin >> c >> d;
         if(!kiemtra(a) || !kiemtra(b) || !kiemtra(c) || !kiemtra(d)){
            cout << "yeu cau nhap lai" << endl;
            continue;
        }
        int x = stoi(a);
        int y = stoi(b);
        int m = stoi(c);
        int n = stoi(d);
        if(y == 0 || n == 0){
            cout << "yeu cau nhap lai" << endl;
            continue;
        }

        // Tong
        int t1 = x*n + y*m;
        int m1 = y*n;
        rutgon(t1,m1);

        // Hieu
        int t2 = x*n - y*m;
        int m2 = y*n;
        rutgon(t2,m2);

        // Tich
        int t3 = x*m;
        int m3 = y*n;
        rutgon(t3,m3);

        // Thuong
        int t4 = x*n;
        int m4 = y*m;
        rutgon(t4,m4);
        cout << "Tong: " << t1 << "/" << m1 << endl;
        cout << "Hieu: " << t2 << "/" << m2 << endl;
        cout << "Tich: " << t3 << "/" << m3 << endl;
        cout << "Thuong: " << t4 << "/" << m4 << endl;
        break;
    }
    return 0;
}

