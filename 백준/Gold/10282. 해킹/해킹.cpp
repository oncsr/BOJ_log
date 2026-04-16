#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

int main(){
	cin.tie(0)->sync_with_stdio(0);

	int T;
	for(cin>>T;T--;) {
		int N, K, C;
		cin>>N>>K>>C;
		vector<vector<pair<int,int>>> v(N+1);
		for(int a,b,c;K--;v[b].emplace_back(a,c)) cin>>a>>b>>c;
		vector<int> D(N+1, INF);
		priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> q;
		q.emplace(0,C);
		D[C] = 0;
		int cnt = 0, last = 0;
		while(!q.empty()) {
			auto [d,n] = q.top();	q.pop();
			if(d > D[n]) continue;
			cnt++;
			last = d;
			for(auto [i,c]:v[n]) if(D[i] > d+c) {
				D[i] = d+c;
				q.emplace(D[i],i);
			}
		}
		cout<<cnt<<' '<<last<<'\n';
	}

}