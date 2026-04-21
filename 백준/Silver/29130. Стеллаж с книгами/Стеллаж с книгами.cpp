#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int s = (1+2*i)%5;
        if(!s)  s = 5;
        for(int j=0;j<m;j++){
            int g = (s+j)%5 == 0 ? 5 : (s+j)%5;
            cout<<g<<' ';
        }
        cout<<'\n';
    }
}