#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int N, M;
    cin>>N>>M;
    vector<int> pre(M);
    vector<char> kind(N);
    vector<vector<int>> arr(N, vector<int>(M));
    for(int i=0;i<N;i++){
        char a;
        cin>>a;
        kind[i] = a;
        int m = a=='L'?-1:1;
        for(int j=0;j<M;j++){
            cin>>a;
            arr[i][j] = (a-'0')*m;
            pre[j] += arr[i][j];
        }
    }
    for(int i=1;i<M;i++)    pre[i] += pre[i-1];

    int mn = 1e9, id = 0;
    for(int i=0;i<N;i++){
        int g = 0, m = kind[i]=='L'?1:-1;
        int mx = 0;
        for(int j=0;j<M;j++){
            if(arr[i][j])   g += m;
            mx = max(mx, abs(pre[j] + g));
        }
        if(mx < mn) mn = mx, id = i+1;
    }
    cout<<id<<'\n'<<mn;

}