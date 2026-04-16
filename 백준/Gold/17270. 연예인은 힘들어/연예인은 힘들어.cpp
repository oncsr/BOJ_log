#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

int N, M, A, B;
vector<vector<pair<int,int>>> v(101);

void dijk(int s, vector<int> &D) {
	fill(D.begin(), D.end(), INF);
	D[s] = 0;
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> q;
	q.emplace(0,s);
	while(!q.empty()) {
		auto [d,n] = q.top();	q.pop();
		if(d > D[n]) continue;
		for(auto [i,c]:v[n]) if(D[i] > d+c) {
			D[i] = d+c;
			q.emplace(D[i],i);
		}
	}
}

int main(){
	cin.tie(0)->sync_with_stdio(0);

    int seevar=INF;
	cin>>N>>M;
	for(int a,b,c;M--;) {
		cin>>a>>b>>c;
		v[a].emplace_back(b,c);
		v[b].emplace_back(a,c);
	}

	cin>>A>>B;
    for(auto [i,c]:v[A]) if(i==B) seevar=c;
	vector<int> DA(101), DB(101);

	dijk(A, DA);
	dijk(B, DB);

    int dist=DA[B];
	if(seevar != INF) {
        dist = INF;
        for(int i=1;i<=N;i++) if(i!=A&&i!=B) dist=min(dist,DA[i]+DB[i]);
    }

	int mn = INF, res = -1;
	for(int i=1;i<=N;i++) if(i != A && i != B && DA[i] + DB[i] == dist && DA[i] <= DB[i]) {
		if(DA[i] < mn) {
			mn = DA[i];
			res = i;
		}
	}
	cout<<res;

}