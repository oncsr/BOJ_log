#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin>>N;
	ll S = 0, arr[200000]{}, cnt[200000]{};
	for(int i=0;i<N;i++)	cin>>arr[i], cnt[arr[i]]++;
	for(int i=0;i<N;i++)	S += arr[arr[i]];

	int Q;
	for(cin>>Q;Q--;){
		int x,v;
		cin>>x>>v;
		int p = arr[x];
		set<int> T = {p,x,v};
		for(int i:T)	S -= cnt[i]*arr[i];
		cnt[p]--;
		cnt[v]++;
		arr[x] = v;
		for(int i:T)	S += cnt[i]*arr[i];
		cout<<S<<'\n';
	}

}