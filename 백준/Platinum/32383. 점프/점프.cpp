#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N,z,m=1e9+7,sub[500001]{},ans=0;
vector<vector<pair<int, ll>>> V(500001);

ll dfs(int n, ll d){
	sub[n] = 1;
	for(auto &[i,c]:V[n]){
		sub[n] += dfs(i,d+1);
		ans = (ans + c * sub[i] % m * (N-sub[i]) % m) % m;
	}
	return sub[n];
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	cin>>N>>z;
	stack<pair<int, ll>> S;
	S.emplace(1,z);
	bitset<500001> B;
	for(int i=2;i<=N;i++){
		ll a;
		cin>>a;
		stack<pair<int, ll>> temp;
		while(!S.empty() && S.top().second < a){
			temp.emplace(S.top());
			S.pop();
		}
		S.emplace(i,a);
		int p = i;
		while(!temp.empty()){
			auto [n,b] = temp.top();
			temp.pop();
			ll v = (a-b)*(a-b)%m;
			V[p].emplace_back(n,v);
			B[n] = 1;
			p = n, a = b;

		}

	}
	if(!S.empty()){
		auto [p,a] = S.top();
		S.pop();
		while(!S.empty()){
			auto [n,b] = S.top();
			S.pop();
			ll v = (a-b)*(a-b)%m;
			V[n].emplace_back(p,v);
			B[p] = 1;
			p = n, a = b;
		}
	}
	for(int i=1;i<=N;i++){
		if(!B[i]){
			dfs(i,0);
			break;
		}
	}
	cout<<ans;

}