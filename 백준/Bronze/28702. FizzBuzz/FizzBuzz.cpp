#include <bits/stdc++.h>
using namespace std;

int main(){
    string a;
    for(int i=3;i>0;i--){
        cin>>a;
        if(48<=a[0]&&a[0]<=57){
            int r=stoi(a)+i;
            if(r%15==0)return cout<<"FizzBuzz",0;
            if(r%3==0)return cout<<"Fizz",0;
            if(r%5==0)return cout<<"Buzz",0;
            return cout<<r,0;
        }
    }
}