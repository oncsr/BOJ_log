#include <bits/stdc++.h>
using namespace std;
using ld = long double;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, C, x[2000]{}, y[2000]{};
	cin>>N>>C;
	for(int i=0;i<N;i++)	cin>>x[i]>>y[i];

	vector<tuple<int, int, int>> edge;
	for(int i=0;i<N;i++)	for(int j=i+1;j<N;j++){
		int dx = x[i] - x[j], dy = y[i] - y[j];
		int cost = dx*dx + dy*dy;
		if(cost >= C)	edge.emplace_back(cost, i, j);
	}

	sort(edge.begin(), edge.end());
	int root[2000]{};
	iota(root, root+N, 0);
	function<int(int)> find = [&](int x) -> int {
		if(x == root[x])	return x;
		return root[x] = find(root[x]);
	};
	int s = 0, m = 0;
	for(auto &[c,a,b]:edge){
		int x = find(a), y = find(b);
		if(x == y)	continue;
		root[x] = y;
		s += c;
		m++;
	}
	if(m != N-1)	cout<<-1;
	else 	cout<<s;

}