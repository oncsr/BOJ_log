#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int e[100001]{};
    for(int i=2;i*i<=100000;i++){
        if(!e[i]){
            for(int j=i*i;j<=100000;j+=i){
                e[j] = 1;
            }
        }
    }
    vector<int> prime;
    for(int i=2;i<=100000;i++){
        if(!e[i])   prime.push_back(i);
    }
    int P, Q;
    cin>>P>>Q;

    ll phi[100001]{};
    phi[1] = phi[2] = 1;
    for(int i=3;i<=Q/P;i++){
        if(!e[i]){
            phi[i] = i-1;
            continue;
        }
        phi[i] = i;
        int T = i;
        for(int j:prime){
            if(j*j > T) break;
            if(T%j) continue;
            while(T%j == 0) T/=j;
            phi[i] *= (j-1);
            phi[i] /= j;
        }
        if(T > 1){
            phi[i] *= (T-1);
            phi[i] /= T;
        }
    }

    ll sum = 1;
    for(int i=1;i<=Q/P;i++) sum += phi[i];
    cout<<sum;

}