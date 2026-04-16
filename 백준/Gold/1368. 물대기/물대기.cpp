#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin>>N;
	vector<tuple<int, int, int>> L;
	for(int i=0;i<N;i++){
		int a;
		cin>>a;
		L.emplace_back(a,i,0);
	}
	for(int i=0;i<N;i++)	for(int j=0;j<N;j++){
		int a;
		cin>>a;
		if(j <= i)	continue;
		L.emplace_back(a,i,j);
	}

	sort(L.begin(), L.end());

	int root[300]{}, water[300]{};
	iota(root, root+N, 0);
	function<int(int)> find = [&](int x) -> int {
		if(x == root[x])	return x;
		int p = find(root[x]);
		water[x] = water[p];
		return root[x] = p;
	};
	int ans = 0;
	for(auto &[c,a,b]:L){
		int x = find(a);
		if(!b){
			if(water[x])	continue;
			ans += c;
			water[x] = 1;
		}
		else{
			int y = find(b);
			if(x == y)	continue;
			if(water[x] && water[y])	continue;
			if(water[x] || water[y])	water[y] = 1;
			root[x] = y;
			ans += c;
		}
	}
	cout<<ans;

}