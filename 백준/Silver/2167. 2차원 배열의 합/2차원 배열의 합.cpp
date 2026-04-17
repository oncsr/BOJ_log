#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int N, M, arr[301][301]{};
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>arr[i][j];
            arr[i][j] += arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
        }
    }
    int K;
    for(cin>>K;K--;){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        cout<<arr[c][d] - arr[a-1][d] - arr[c][b-1] + arr[a-1][b-1]<<'\n';
    }
}