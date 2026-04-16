#include <bits/stdc++.h>
using namespace std;

int main(){
    int c,k,p,s=0;
    cin>>c>>k>>p;
    for(int i=0;i<=c;i++) s+=k*i+p*i*i;
    cout<<s;
}