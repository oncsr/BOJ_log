#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M, Q;
	cin>>N>>M>>Q;
	vector<pair<int, int>> edge[5];
	for(;M--;){
		int a,b;
		char c;
		cin>>a>>b>>c;
		edge[c-'A'].emplace_back(a,b);
	}

	vector<int> A = {0,1,2,3,4};
	int root[50001]{};
	function<int(int)> find = [&](int x) -> int {
		if(x == root[x])	return x;
		return root[x] = find(root[x]);
	};

	vector<vector<int>> S;
	vector<vector<int>> info;
	do{
		
		S.emplace_back(A);
		iota(root, root+N+1, 0);
		vector<int> T(5);
		for(int i:A){
			int c = 0;
			for(auto &[a,b]:edge[i]){
				int x = find(a), y = find(b);
				if(x == y)	continue;
				c++;
				root[x] = y;
			}
			T[i] = c;
		}
		info.emplace_back(T);

	}while(next_permutation(A.begin(), A.end()));

	for(;Q--;){
		vector<pair<int, int>> q(5);
		int c = 0;
		for(auto &[a,b]:q)	cin>>a, b = c++;
		sort(q.begin(), q.end());
		vector<int> R;
		for(auto &[a,b]:q)	R.push_back(b);
		
		int d = 0;
		while(d < 120 && S[d] != R)	d++;
		ll ans = 0;
		c = 0;
		for(int i:R)	ans += ll(info[d][i]) * q[c++].first;
		cout<<ans<<'\n';
	}

}