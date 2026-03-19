#include <bits/stdc++.h>
#include <numeric>
using namespace std;
int gcd(int a, int b){// tim ucln
    while(b!=0){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;

}
bool kiemtra(string s){// kiem tra xem ki tu nhap vao phai so khong
    int i = 0;

    if(s[0] == '-') {
            if(s.length() == 1) return false;//cho co dau am
            i = 1; // bo qua dau am
    }
    for(; s[i] != '\0'; i++){
        if(s[i] < '0' || s[i] > '9') return false;
    }

    return true;
}
int main()
{
    string a,b;

    while(1){
        cout<<"nhap tu so: ";
        cin>>a;
        cout<<"nhap mau so: ";
        cin>>b;
        if(!kiemtra(a)||!kiemtra(b)){
        cout<<"yeu cau nhap lai "<<endl;
        continue;
    }
    int x= stoi(a);
    int y= stoi(b);
    if(y == 0){
        cout << "yeu cau nhap lai";
        continue;
    }

    int g = gcd(x,y);
        x /= g;
        y /= g;
    if(y < 0){
        x = -x;
        y = -y; //dinh dang lai dau am o tu
    }
    if (x==0){
        cout<<"0";
        break;
    }
    if (x%y==0){
        cout<< x/y;
        break;
    }
    cout << x << "/" << y;
    break;
    }
    return 0;
}

