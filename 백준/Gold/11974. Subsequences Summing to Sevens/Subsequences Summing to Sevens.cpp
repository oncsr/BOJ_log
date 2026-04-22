#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin>>n;
    vector<int> a(7,-1);
    vector<int> b(7,-1);
    int s = 0;
    a[0] = 0;
    for(int i=1;i<=n;i++){
        int g;
        cin>>g;
        s = (s+g)%7;
        if(a[s] == -1)  a[s] = i;
        else    b[s] = i;
    }
    int mx = 0;
    for(int i=0;i<7;i++){
        if(b[i] == -1)  continue;
        mx = max(mx, b[i] - a[i]);
    }
    cout<<mx;
}