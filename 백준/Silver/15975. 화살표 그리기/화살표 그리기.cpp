#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin>>N;
	vector<vector<ll>> A(N+1);

	for(int i=0;i<N;i++){
		int a,b;
		cin>>a>>b;
		A[b].push_back(a);
	}

	ll ans = 0;
	for(int i=1;i<=N;i++){
		if(A[i].size() <= 1)	continue;
		sort(A[i].begin(),A[i].end());
		for(int j=0;j<A[i].size();j++){
			ll mn = 1e18;
			if(j>0)	mn = min(mn,A[i][j]-A[i][j-1]);
			if(j<A[i].size()-1)	mn = min(mn,A[i][j+1]-A[i][j]);
			ans += mn;
		}
	}
	cout<<ans;

}