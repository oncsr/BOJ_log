#include <bits/stdc++.h>
using namespace std;

int main(){
    string a, b;
    cin>>a>>b;
    int i=0;
    for(;i<min(a.size(), b.size());i++)
        if(a[i] != b[i])    break;
    cout<<a.size() - i + b.size() - i;
}