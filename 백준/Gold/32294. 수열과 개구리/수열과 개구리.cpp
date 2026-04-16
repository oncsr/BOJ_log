#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin>>N;
	vector<int> A(N+1), B(N+1);
	for(int i=1;i<=N;i++) cin>>A[i];
	for(int i=1;i<=N;i++) cin>>B[i];

	vector<vector<pair<int, int>>> V(N+1);
	for(int i=1;i<=N;i++){
		V[max(i-A[i], 0)].emplace_back(i, B[i]);
		V[i+A[i]>N?0:i+A[i]].emplace_back(i, B[i]);
	}

	vector<ll> D(N+1, -1);
	D[0] = 0;
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> Q;
	Q.emplace(0, 0);
	while(!Q.empty()){
		auto [d, n] = Q.top(); Q.pop();
		if(d > D[n]) continue;
		for(auto [i, c] : V[n]){
			if(D[i] == -1 || D[i] > d+c){
				D[i] = d+c;
				Q.emplace(d+c, i);
			}
		}
	}

	for(int i=1;i<=N;i++) cout<<D[i]<<' ';


}