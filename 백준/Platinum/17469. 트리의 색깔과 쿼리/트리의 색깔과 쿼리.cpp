#include <bits/stdc++.h>
using namespace std;
using t6 = tuple<int, int, int, int, int, int>;

int root[100001]{}, par[100001]{};
set<int> S[100001]{};
int find(int x){
	if(x == root[x])	return x;
	return root[x] = find(root[x]);
}

int main(){
	cin.tie(0)->sync_with_stdio(0);

	int N, Q;
	cin>>N>>Q;
	iota(root, root+N+1, 0);
	stack<pair<int, int>> query;
	for(int i=2;i<=N;i++){
		int a;
		cin>>a;
		par[i] = a;
	}
	for(int i=1;i<=N;i++){
		int a;
		cin>>a;
		S[i].insert(a);
	}
	Q += N-1;
	for(;Q--;){
		int o, a;
		cin>>o>>a;
		query.emplace(o, a);
	}

	stack<int> ans;
	while(!query.empty()){
		auto [o, a] = query.top();
		query.pop();
		if(o == 2)	ans.push(S[find(a)].size());
		else{
			int x = find(a), y = find(par[a]);
			if(S[x].size() < S[y].size())	swap(S[x], S[y]);
			for(int i:S[y])	S[x].insert(i);
			S[y].clear();
			root[y] = x;
		}
	}

	while(!ans.empty())	cout<<ans.top()<<'\n', ans.pop();

}