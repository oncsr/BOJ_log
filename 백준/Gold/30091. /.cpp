#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    long long arr[2000]{}, N;
    cin>>N;
    for(int i=0;i<N;i++)    cin>>arr[i];
    vector<unordered_set<int>> M(2000);
    vector<long long> V(20000001);
    vector<int> L;
    long long mx = 0;
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            int G = arr[i] + arr[j];
            if(M[i].count(G) || M[j].count(G))  continue;
            M[i].insert(G);
            M[j].insert(G);
            V[G] += arr[i]*arr[j];
            mx = max(mx, V[G]);
        }
    }
    cout<<mx;
}