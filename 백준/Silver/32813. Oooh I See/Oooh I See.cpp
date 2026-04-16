#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int N, M;
    cin>>N>>M;
    char a[52][52]{};
    for(int i=1;i<=N;i++)for(int j=1;j<=M;j++)  cin>>a[i][j];
    int cnt = 0, X,Y;
    int dx[8]={1,1,1,0,0,-1,-1,-1};
    int dy[8]={1,0,-1,1,-1,1,0,-1};
    for(int i=1;i<=N;i++)for(int j=1;j<=M;j++){
        if(a[i][j] == 'O')  continue;
        int k = 0;
        for(int d=0;d<8;d++){
            int x=i+dx[d], y=j+dy[d];
            k += a[x][y] == 'O';
        }
        if(k == 8)  cnt++, X=i,Y=j;
    }
    if(cnt == 0)    cout<<"Oh no!";
    else if(cnt == 1)   cout<<X<<' '<<Y;
    else    cout<<"Oh no! "<<cnt<<" locations";

}