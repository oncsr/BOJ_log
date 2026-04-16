#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int N,Q;
    cin>>N>>Q;
    vector<int> V(N), L(300001,1e9), H(300001,-1);
    for(int &i:V)   cin>>i;
    sort(V.begin(),V.end());
    for(int i=1;i<=300000;i++){
        for(int p=0;p<=V.back()+i;p+=i){
            auto q = lower_bound(V.begin(),V.end(),p);
            if(q != V.end())  L[i] = min(L[i],(*q)%i);
            if(q != V.begin())    H[i] = max(H[i],(*(--q))%i);
        }
    }
    for(int m;Q--;cout<<L[m]<<' '<<H[m]<<'\n')  cin>>m;

}