#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;

char arr[3125][3125]{};

int N;

void solve(ii s, int n){
    if(n == 0)  {arr[s.first][s.second] = '*';return;}
    int G = 1;
    for(int i=1;i<n;i++)    G *= 5;
    solve({s.first,s.second + 2*G}, n-1);
    solve({s.first+G,s.second + 2*G}, n-1);
    for(int i=0;i<5;i++){
        solve({s.first+2*G,s.second+i*G},n-1);
    }
    for(int i=1;i<4;i++){
        solve({s.first+3*G,s.second+i*G},n-1);
    }
    solve({s.first+4*G,s.second+G},n-1);
    solve({s.first+4*G,s.second+3*G},n-1);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N;
    int G = 1;
    for(int i=0;i<N;i++)    G *= 5;
    solve({0,0}, N);
    for(int i=0;i<G;i++){
        for(int j=0;j<G;j++)    cout<<(arr[i][j] == '*'?'*':' ');
        cout<<'\n';
    }
}