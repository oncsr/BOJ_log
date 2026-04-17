#include <bits/stdc++.h>
using namespace std;

int seg[1048577]{};

void upt(int s, int e, int i, int n){
    if(s == e) { seg[n]++; return; }
    int m=(s+e)>>1;
    if(i <= m)  upt(s,m,i,n*2);
    else    upt(m+1,e,i,n*2+1);
    seg[n] = seg[n*2] + seg[n*2+1];
}

int find(int s, int e, int l, int r, int n){
    if(l>r || l>e || r<s)   return 0;
    if(l <= s && e <= r)    return seg[n];
    int m=(s+e)>>1;
    return find(s,m,l,r,n*2) + find(m+1,e,l,r,n*2+1);
}

int main(){
    int N;
    cin>>N;
    vector<pair<int, int>> arr(N);
    for(int i=1;i<=N;i++){
        cin>>arr[i-1].first;
        arr[i-1].second = i;
    }
    sort(arr.begin(), arr.end(), greater<>());

    long long ans = 0;
    for(int i=0;i<N;i++){
        auto [a,b] = arr[i];
        vector<int> w;
        while(i < N && arr[i].first == a){
            ans += find(1,N,1,arr[i].second-1,1);
            w.push_back(arr[i].second);
            i++;
        }
        i--;
        for(int j:w)    upt(1,N,j,1);
    }
    cout<<ans;

}