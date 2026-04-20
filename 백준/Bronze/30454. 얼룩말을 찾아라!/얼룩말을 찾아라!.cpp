#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int mx=0, cnt=0;
    for(int i=0;i<n;i++){
        int c=0;
        char t=' ';
        for(int j=0;j<k;j++){
            char a;
            cin>>a;
            if(t!=a && a=='1') c++;
            t=a;
        }
        if(c>mx) mx=c, cnt=1;
        else if(c==mx) cnt++;
    }
    cout<<mx<< ' '<<cnt;
}