#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll N, M;
	cin>>N>>M;
	priority_queue<pair<ll,ll>> Q;
	vector<int> A(N), B(N);
	for(int &i:A)	cin>>i;
	for(int &i:B)	cin>>i;
	for(int i=0;i<N;i++){
		int a = A[i],b = B[i];
		if(b-a > 0)	Q.emplace(-a,b-a);
	}

	while(!Q.empty()){
		auto [need, v] = Q.top();	Q.pop();
		if(M < -need)	break;
		M += v;
	}
	cout<<M;

}