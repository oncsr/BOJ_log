#include <bits/stdc++.h>
using namespace std;

int D[1<<20]{}, N, H, S[20]{}, W[20]{}, F[20]{};

int sol(int k){
    if(D[k] != -2) return D[k];
    int &r = D[k];
    for(int i=0;i<N;i++){
        if(!(k&(1<<i))) continue;
        int v = sol(k-(1<<i));
        if(v < W[i])    v = -1;
        else    v -= W[i];
        r = max(r, min(v, F[i]));
    }
    return r;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    fill(D, D+(1<<20), -2);
    cin>>N>>H;
    for(int i=0;i<N;i++)    cin>>S[i]>>W[i]>>F[i], D[1<<i] = F[i];
    sol((1<<N)-1);

    int ans = -1;
    for(int x=1;x<(1<<N);x++){
        int p = 0, h = 0;
        for(int i=0;i<N;i++){
            if(!(x & (1<<i)))   continue;
            h += S[i];
            if(h >= H)  {p=1;break;}
        }
        if(p)   ans = max(ans, D[x]);   
    }
    if(ans == -1)   cout<<"Mark is too tall";
    else    cout<<ans;

}