#include <bits/stdc++.h>
using namespace std;

bitset<1000001> e;
int N;
vector<int> p;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    for(int i=2;i*i<=1000000;i++) if(!e[i]) for(int j=i*i;j<=1000000;j+=i) e[j] = 1;
    for(int i=2;i<=1000000;i++) if(!e[i]) p.push_back(i);
    for(cin>>N;N--;) {
        int a,b;
        cin>>a>>b;
        int l = lower_bound(p.begin(), p.end(), a) - p.begin();
        int r = --upper_bound(p.begin(), p.end(), b) - p.begin();
        cout<<(l>r || (r-l)%2 ? -1 : p[(l+r)/2])<<'\n';
    }

}