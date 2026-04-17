#include <bits/stdc++.h>
using namespace std;

int main(){
    string n;
    int m;
    cin>>n>>m;
    int s = 0, c = 0;
    while(c++ < stoi(n) && s + n.size() <= m)    cout<<n, s += n.size();
    if(c == stoi(n)+1)    return 0;
    for(int i=0;i<m-s;i++)  cout<<n[i];
}