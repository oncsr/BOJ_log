#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N,L,R;
    cin>>N>>L>>R;
    vector<int> A(N);
    for(int &i:A)   cin>>i;
    auto B = A;
    sort(A.begin()+L-1, A.begin()+R);
    sort(B.begin(), B.end());
    cout<<int(A == B);
}