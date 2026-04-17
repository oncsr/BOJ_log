#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(0)->sync_with_stdio(0);

	int root[200001]{}, N, M, cnt[200001]{};
	vector<vector<int>> V(200001);
	for(cin>>N>>M;M--;){
		int a,b;
		cin>>a>>b;
		V[a].push_back(b);
		V[b].push_back(a);
	}
	stack<int> S;
	for(int i=1;i<=N;i++){
		int a;
		cin>>a;
		S.push(a);
		root[i] = i;
		cnt[i] = 1;
	}

	function<int(int)> find = [&](int x) -> int {
		if(x == root[x])	return x;
		return root[x] = find(root[x]);
	};

	vector<int> O(200001);
	stack<int> ans;
	int base = S.top(), sum = 0;
	while(!S.empty()){
		int now = S.top();
		S.pop();
		O[now] = 1;
		for(int i:V[now]){
			if(!O[i])	continue;
			int x = find(i), y = find(now);
			if(x == y)	continue;
			root[x] = y;
			cnt[y] += cnt[x];
		}
		ans.push(++sum == cnt[find(now)]);
	}
	while(!ans.empty())	cout<<(ans.top() ? "YES\n" : "NO\n"), ans.pop();
}