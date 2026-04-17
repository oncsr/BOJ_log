#include <bits/stdc++.h>
using namespace std;

int arr[100001]{};
int mn = 1e9;
vector<vector<int>> V(100001);

pair<int, int> dfs(int n, int p){
	pair<int, int> res = {-1, -1};
	if(arr[n] == 1)	res.first = 0;
	if(arr[n] == 2)	res.second = 0;
	for(int i:V[n]){
		if(i == p)	continue;
		auto [ca, cb] = dfs(i,n);
		if(ca != -1){
			ca++;
			if(res.first == -1)	res.first = ca;
			else 	res.first = min(res.first, ca);
		}
		if(cb != -1){
			cb++;
			if(res.second == -1)	res.second = cb;
			else 	res.second = min(res.second, cb);
		}
	}
	if(res.first != -1 && res.second != -1)	mn = min(mn, res.first + res.second);
	return res;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);

	int n, k;
	cin>>n>>k;
	int _1 = 0, _2 = 0, start;
	for(int i=1;i<=n;i++){
		cin>>arr[i], _1 += (arr[i] == 1), _2 += (arr[i] == 2);
		if(arr[i] == 1)	start = i;
	}
	if(k == 1){cout<<(!_1 ? -1:0);return 0;}
	if(!_1 || !_2)	{cout<<-1;return 0;}

	for(int i=1;i<n;i++){
		int a,b;
		cin>>a>>b;
		V[a].push_back(b);
		V[b].push_back(a);
	}

	dfs(start, 0);
	cout<<mn;

}