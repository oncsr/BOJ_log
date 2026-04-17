#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M;
	cin>>N>>M;
	vector<pair<int, int>> S, E;
	for(int i=0;i<N;i++){
		int l,r,c;
		cin>>l>>r>>c;
		S.emplace_back(l,c);
		E.emplace_back(r,c);
	}
	sort(S.begin(), S.end());
	sort(E.begin(), E.end());

	int ans = 0, cnt = 0;
	int i = 0, j = 0;
	map<int, int> P;
	for(int e=1;e<=1000000;e++){
		while(j < S.size() && S[j].first <= e){
			P[S[j].second]++;
			if(P[S[j].second] == 2)	cnt++;
			j++;
		}
		int s = max(0, e-M);
		while(i < E.size() && E[i].first <= s){
			P[E[i].second]--;
			if(P[E[i].second] == 1)	cnt--;
			i++;
		}
		ans = max(ans, cnt);
	}
	cout<<ans;


}