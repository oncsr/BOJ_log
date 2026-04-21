#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int n, m;
    cin>>n>>m;
    int arr[50][50]{}, row[51]{}, col[51]{};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char a;
            cin>>a;
            arr[i][j] = a == 'X';
            if(a == 'X')    row[i] = col[j] = 1;
        }
    }
    
    int ans = 0;
    for(int i=0;i<n;i++){
        if(row[i])  continue;
        int j = 0;
        for(;j<m;j++){
            if(col[j])  continue;
            break;
        }
        ans++;
        row[i] = col[j] = 1;
    }
    for(int j=0;j<m;j++){
        if(col[j])  continue;
        int i=0;
        for(;i<n;i++){
            if(row[i])  continue;
            break;
        }
        ans++;
        row[i] = col[j] = 1;
    }
    cout<<ans;

}