#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    int T;
    cin>>T;
    for(int tc=1;tc<=T;tc++){
        int N;
        cin>>N;
        int arr[10][10]{};
        int X[101]{}, Y[101]{};
        for(int i=0;i<N;i++)    for(int j=0;j<N;j++){
            cin>>arr[i][j];
            X[arr[i][j]] = i, Y[arr[i][j]] = j;
        }
        int s = 1;
        int ans = 0, pos = 0;
        while(s <= N*N){
            int fir = s;
            int x = X[s], y = Y[s];
            bool F = 1;
            while(s <= N*N && F){
                F = 0;
                for(int j=0;j<4;j++){
                    int xx = x+dx[j], yy = y+dy[j];
                    if(xx<0 || xx>=N || yy<0 || yy>=N || arr[xx][yy] != s+1)    continue;
                    F = 1;
                    s++;
                    x = X[s], y = Y[s];
                    break;
                }
            }
            if(s > N*N) s--;
            if(s - fir + 1 > ans)   ans = s-fir+1, pos = fir;
            s++;
        }
        cout<<"Case #"<<tc<<": "<<pos<<' '<<ans<<'\n';
    }

}