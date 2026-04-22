#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int n;
    cin>>n;
    map<string, int> M;
    for(int i=1;i<=n;i++){
        string a;
        cin>>a;
        M[a] = i;
    }
    string arr[2500]{};
    int ans = 0;
    for(int i=0;i<n;i++)    cin>>arr[i];
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(M[arr[i]] < M[arr[j]]) ans++;
        }
    }
    cout<<ans<<'/'<<n*(n-1)/2;
}