#include <bits/stdc++.h>
using namespace std;

int N, K, ans = 1e9, A[20]{};

void sol(int pos, int cnt, int x, int y){
    if(pos == K)    {ans = min(ans, cnt);return;}
    sol(pos+1, cnt+abs(x-A[pos]),A[pos],y);
    sol(pos+1, cnt+abs(y-A[pos]),x,A[pos]);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int x, y;
    cin>>N>>x>>y>>K;
    for(int i=0;i<K;i++)    cin>>A[i];
    sol(0,0,x,y);
    cout<<ans;

}