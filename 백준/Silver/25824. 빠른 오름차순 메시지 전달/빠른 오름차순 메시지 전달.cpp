#include <bits/stdc++.h>
using namespace std;

int arr[13][13]{};
int mn = 12001;

void solve(int num, int cnt, int n, int time){
    if(num == 7){
        mn = min(mn, time);
        return;
    }
    if(cnt){
        solve(num+1, 0, (num+1)*2-1, time+arr[n][(num+1)*2-1]);
        solve(num+1, 0, (num+1)*2, time + arr[n][(num+1)*2]);
    }
    else{
        solve(num, 1, (n&1)?n+1:n-1, time+arr[n][(n&1)?n+1:n-1]);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    for(int i=1;i<=12;i++){
        for(int j=1;j<=12;j++){
            cin>>arr[i][j];
        }
    }
    solve(1, 0, 1, 0);
    solve(1, 0, 2, 0);
    cout<<mn;

}