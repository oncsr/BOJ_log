#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll N, M, K;
	cin>>N>>M>>K;
	vector<ll> A(N);
	for(ll &i:A)	cin>>i;
	sort(A.begin(), A.end());
	
	vector<ll> B(K);
	int ans = -1;
	for(int i=0;i<N;i++){
		B[i%K] += A[i];
		if(B[i%K] <= M)	ans = i;
	}
	cout<<ans+1;

}