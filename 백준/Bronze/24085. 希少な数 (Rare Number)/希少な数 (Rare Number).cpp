#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin>>N;
    int arr[101]{}, cnt[2001]{};
    for(int i=0;i<N;i++){
        int a;
        cin>>a;
        cnt[a]++;
        arr[i] = a;
    }
    int c = 101, ans = -1;
    for(int i=0;i<N;i++){
        if(cnt[arr[i]] < c || (cnt[arr[i]] == c && arr[i] < ans))    ans = arr[i], c = cnt[arr[i]];
    }
    cout<<ans;

}