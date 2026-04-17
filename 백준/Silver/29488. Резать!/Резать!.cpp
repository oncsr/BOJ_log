#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int n,m,k;
    cin>>n>>m>>k;
    if(n*m%k){cout<<-1;return 0;}
    int num = 1, cnt = 0;
    int arr[100][100]{};
    for(int i=0;i<n;i++){
        if(i&1){
            for(int j=m-1;j>=0;j--){
                arr[i][j] = num;
                cnt++;
                if(cnt == k)    cnt = 0, num++;
            }
        }
        else{
            for(int j=0;j<m;j++){
                arr[i][j] = num;
                cnt++;
                if(cnt == k)    cnt = 0, num++;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)    cout<<arr[i][j]<<' ';
        cout<<'\n';
    }
    
}