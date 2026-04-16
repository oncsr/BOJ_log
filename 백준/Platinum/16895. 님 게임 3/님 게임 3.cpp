#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int N, arr[1000]{}, s = 0;
    cin>>N;
    for(int i=0;i<N;i++)    cin>>arr[i], s ^= arr[i];

    int ans = 0;
    for(int i=0;i<N;i++){
        for(int j=1;j<=arr[i];j++){
            if(!(s^arr[i]^(arr[i]-j))) ans++;
        }
    }
    cout<<ans;

}