#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int N;
    cin>>N;
    vector<int> arr(N+1);
    vector<int> idx(N+1);
    for(int i=1;i<=N;i++)   cin>>arr[i], idx[arr[i]] = i;

    

    int M;
    cin>>M;
    for(int i=0;i<M;i++){
        int L, R;
        cin>>L>>R;

        vector<int> people;
        for(int j=L;j<=R;j++){
            people.push_back(idx[j]);
        }
        sort(people.begin(), people.end());
        vector<int> ans = arr;
        for(int i:people){
            ans[i] = L++;
        }

        for(int i=1;i<=N;i++)   cout<<ans[i]<<' ';
        cout<<'\n';

    }
    
}