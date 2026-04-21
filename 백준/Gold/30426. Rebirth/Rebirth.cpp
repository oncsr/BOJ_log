#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int N, M, K;
    cin>>N>>M>>K;
    vector<pair<int, int>> Q;
    for(int i=0;i<K;i++){
        int a, b;
        cin>>a>>b;
        Q.push_back({a,b});
    }

    int L, no[3001]{};
    for(cin>>L;L--;){
        int a;
        cin>>a;
        no[a]++;
    }

    int arr[3002][3002]{};
    arr[0][M] = 1;
    for(int i=0;i<K;i++){
        int a = Q[i].first, b = Q[i].second;
        for(int j=0;j<N;j++){
            if(!arr[i][j])  continue;
            if(!no[(j+a)%N])    arr[i+1][(j+a)%N] = 1;
            if(!no[(j+b)%N])    arr[i+1][(j+b)%N] = 1;
        }
    }
    if(arr[K][0])   cout<<"utopia";
    else    cout<<"dystopia";
}