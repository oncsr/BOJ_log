#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    char _;
    int N,K;
    cin>>N>>K;
    vector<int> A(N);
    cin>>A[0];
    for(int i=1;i<N;i++)    cin>>_>>A[i];
    while(K--){
        vector<int> B;
        for(int i=0;i<N-1;i++)  B.push_back(A[i+1]-A[i]);
        N--;
        A = B;
    }
    cout<<A[0];
    for(int i=1;i<A.size();i++) cout<<','<<A[i];


}