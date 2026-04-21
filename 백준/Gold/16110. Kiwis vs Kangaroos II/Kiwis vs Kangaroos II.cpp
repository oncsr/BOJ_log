#include <bits/stdc++.h>
using namespace std;



int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n, m, k;
    cin>>n>>m>>k;
    vector<vector<int>> ans1(n+1, vector<int>(n+1));
    vector<vector<int>> ans2(n+1, vector<int>(n+1));
    vector<pair<int, int>> fir(m+1);
    for(int i=1;i<=m;i++)   cin>>fir[i].first, fir[i].second = i;
    sort(fir.begin()+1, fir.end(), greater<>());

    int row = 1, col = 1;
    for(int i=1;i<=m;i++){
        int num = fir[i].second;
        for(;fir[i].first--;){
            ans1[row][(col+row-1)%n ? (col+row-1)%n : n] = num;
            row++;
            if(row > n) row = 1, col++;
        }
    }

    fir = vector<pair<int, int>>(k+1);
    for(int i=1;i<=k;i++)   cin>>fir[i].first, fir[i].second = i;
    sort(fir.begin()+1, fir.end(), greater<>());
    row = 1, col = 1;
    for(int i=1;i<=k;i++){
        int num = fir[i].second;
        for(;fir[i].first--;){
            ans2[row][(col+row-1)%n ? (col+row-1)%n : n] = num;
            row++;
            if(row > n) row = 1, col++;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)   cout<<ans1[i][j]<<'v'<<ans2[i][j] <<' ';
        cout<<'\n';
    }

}