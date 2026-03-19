#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b){// tim ucln
    while(b!=0){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;

}

bool kiemtra(string s){//ham kiem tra dinh dang phan so nhap vao
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

void rutgon(int &a, int &b){//ham rut gon phan so
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
        rutgon(x,y);
        rutgon(m,n);
        // so sanh phan so
        if(x*n > m*y){
            cout << a << "/" << b;
        }
        else if(x*n < m*y){
            cout << c << "/" << d;
        }
        else{
            cout <<"hai phan so bang nhau";
        }
        break;
    }
    return 0;
}

