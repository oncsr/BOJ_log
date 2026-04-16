#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int N, K;
    cin>>N>>K;
    int ans = K;
    vector<int> A(N);
    for(int &i:A)cin>>i;
    for(int i=0;i<=N-K;i++){
        int le = 0, ri = 0;
        if(i)   le++;
        if(i+K<N)   ri++;
        for(int j=i-2;j>=0;j--){
            if(A[j] < A[j+1])   le++;
            else    break;
        }
        for(int j=i+K;j<N-1;j++){
            if(A[j] < A[j+1])   ri++;
            else    break;
        }
        int L = 0, R = 0;
        for(int j=i;j<i+K;j++){
            if(!i || A[j] > A[i-1])  L++;
            if(i+K==N || A[j] < A[i+K])  R++;
        }
        if(L == R && L == K)    le += ri + R;
        else    le += L, ri += R;
        ans = max({ans, le, ri});
    }
    cout<<ans;

}