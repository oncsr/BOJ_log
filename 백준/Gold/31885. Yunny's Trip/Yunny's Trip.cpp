#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int N, K;
    cin>>N>>K;
    vector<pair<ll,ll>> A(N);
    map<ll, set<ll>> M;
    for(auto &[a,b]:A)  cin>>a>>b, M[a].insert(b);
    ll EX, EY;
    cin>>EX>>EY;

    if(abs(EX) + abs(EY) == 1)  return cout<<1,0;
    if(K == 1)  return cout<<-1,0;
    if(abs(EX) + abs(EY) == 2)  return cout<<2,0;
    for(auto &[a,b]:A)  if(EX == a && EY == b)  return cout<<2,0;
    if(K == 2)  return cout<<-1,0;
    if(abs(EX) + abs(EY) == 3)  return cout<<3,0;
    for(auto &[a,b]:A){
        if((EX == a-1 && EY == b) || (EX == a+1 && EY == b) || (EX == a && EY == b-1) || (EX == a && EY == b+1))    return cout<<3,0;
    }
    if(K == 3)  return cout<<-1,0;
    if(abs(EX) + abs(EY) == 4)  return cout<<4,0;
    for(auto &[a,b]:A){
        for(int x=-2;x<=2;x++)  for(int y=-2;y<=2;y++){
            if(abs(x) + abs(y) != 2)    continue;
            if(EX == a+x && EY == b+y)  return cout<<4,0;
        }
        ll x = EX-a, y = EY-b;
        if(M[x].count(y))   return cout<<4,0;
    }
    if(K == 4)  return cout<<-1,0;
    if(abs(EX) + abs(EY) == 5)  return cout<<5,0;
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    for(auto &[a,b]:A){
        for(int x=-3;x<=3;x++)  for(int y=-3;y<=3;y++){
            if(abs(x) + abs(y) != 3)    continue;
            if(EX == a+x && EY == b+y)  return cout<<5,0;
        }
        for(int k=0;k<4;k++){
            ll x = EX-a+dx[k], y = EY-b+dy[k];
            if(M[x].count(y))   return cout<<5,0;
        }
    }
    cout<<-1;

}