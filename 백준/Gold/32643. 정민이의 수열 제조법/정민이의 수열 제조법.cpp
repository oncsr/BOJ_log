#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
	int N,M,A[5000001];
	cin>>N>>M;
	bitset<5000001> B;
	for(int i=2;i*i<=N;i++)if(!B[i])for(int j=i*i;j<=N;j+=i)	B.set(j);
	for(int i=1;i<=N;i++)	A[i] = A[i-1] + !B[i];
	for(int a,b;M--;cout<<A[b]-A[a-1]<<'\n')	cin>>a>>b;
}