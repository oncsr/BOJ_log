#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> A(n);
    for(int &i:A)cin>>i;
    sort(A.begin(),A.end());
    vector<int> R;
    for(int i=1;i<n;i++)for(int k=A[i-1]+1;k<A[i];k++)R.push_back(k);
    cout<<R.size()<<'\n';
    for(int i:R)cout<<i<<' ';
}