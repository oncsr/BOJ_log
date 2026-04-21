#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int N, K;
    cin>>N>>K;
    int arr[250000]{};
    int Q[250001]{};
    for(int i=0;i<N;i++)    cin>>arr[i];
    for(int i=0;i<K;i++){
        int a,b,c;
        cin>>a>>b>>c;
        Q[a] -= c;
        Q[b+1] += c;
    }
    int s = 0;
    for(int i=0;i<N;i++){
        s += Q[i];
        cout<<arr[i]+s<<' ';
    }
}