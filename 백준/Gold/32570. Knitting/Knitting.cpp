#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	
	int N, K, P, M;
	cin>>N>>K>>P>>M;
	vector<int> ans;
	vector<int> cnt(K+1);
	vector<int> idx(K+1);
	for(int i=1,a;i<=M;i++){
		cin>>a;
		cnt[a]++;
		if(idx[a] && i-idx[a] < P)	return cout<<"impossible", 0;
		idx[a] = i;
		ans.push_back(a);
	}

	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> Q;
	for(int i=1;i<=K;i++)	Q.emplace(cnt[i], idx[i] ? idx[i] + P : 0, i);

	while(!Q.empty()){
		if(ans.size() == N)	break;
		auto [c,x,n] = Q.top();	Q.pop();
		if(ans.size() + 1 < x)	return cout<<"impossible", 0;
		ans.push_back(n);
		Q.emplace(++cnt[n], ans.size()+P, n);
	}
	for(int &i:ans)	cout<<i<<' ';

}