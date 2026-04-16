#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T;
	for(cin>>T;T--;){
		ll N, K;
		cin>>N>>K;
		vector<ll> ans;
		while(K){
			ll g = 1, s = 0;
			for(int i=0;i<N;i++){
				s += g;
				g *= 10;
			}
			if(K < s)	{N--;continue;}
			ll p=0;
			while(s * p <= K && p < 10)	p++;
			p--;
			if(s*p)	ans.push_back(s*p);
			K-=s*p;
			N = log10(K) + 1;
		}
		cout<<ans.size()<<'\n';
		for(ll i:ans)	cout<<i<<' ';
		cout<<'\n';
	}

}