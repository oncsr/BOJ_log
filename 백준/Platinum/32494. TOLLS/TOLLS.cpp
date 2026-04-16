#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {	
	cin.tie(0)->sync_with_stdio(0);

	int N, Q;
	cin>>N>>Q;
	vector<tuple<int, int, int>> edge(N-1);
	for(auto &[c,a,b]:edge)	cin>>a>>b>>c;
	sort(edge.begin(), edge.end());

	vector<int> root(N+1);
	vector<int> cnt(N+1, 1);
	iota(root.begin(), root.end(), 0);
	function<int(int)> find = [&](int x) -> int {
		if(root[x] == x)	return x;
		return root[x] = find(root[x]);
	};

	vector<pair<int, ll>> V;
	for(auto &[c,a,b]:edge){
		int x = find(a), y = find(b);
		V.emplace_back(c, (ll)cnt[x] * cnt[y]);
		cnt[y] += cnt[x];
		root[x] = y;
	}

	sort(V.begin(), V.end());
	vector<int> I = {0};
	vector<ll> J = {0};
	for(auto &[c,v]:V)	I.push_back(c), J.push_back(c*v+J.back());
	
	for(;Q--;){
		int a,b;
		cin>>a>>b;
		int l = lower_bound(I.begin(), I.end(), a) - I.begin();
		int r = upper_bound(I.begin(), I.end(), b) - I.begin();
		cout<<J[r-1] - J[l-1]<<'\n';
	}

}