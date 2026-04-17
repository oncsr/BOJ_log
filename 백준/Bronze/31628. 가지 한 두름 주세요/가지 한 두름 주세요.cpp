#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    string arr[10][10]{};
    for(int i=0;i<10;i++)   for(int j=0;j<10;j++)   cin>>arr[i][j];
    for(int i=0;i<10;i++){
        int cnt = 1;
        for(int j=1;j<10;j++)   if(arr[i][j] == arr[i][j-1])    cnt++;
        if(cnt == 10){cout<<1;return 0;}
    }
    for(int i=0;i<10;i++){
        int cnt = 1;
        for(int j=1;j<10;j++)   if(arr[j][i] == arr[j-1][i])    cnt++;
        if(cnt == 10){cout<<1;return 0;}
    }
    cout<<0;

}