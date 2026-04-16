#include <iostream>
#include <bitset>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin>>N;
    bitset<2200001> A, B;
    for(int a;N--;A[a]=B[a]=1) cin>>a;
    if(!A[0]) return cout<<0,0;
    for(int i=1;i<=2200000;i++){
        if(!B[i]) return cout<<i,0;
        for(int j=i;j<=2200000;j+=i) B[j] = B[j] | (A[i]&A[j/i]);
    }

}