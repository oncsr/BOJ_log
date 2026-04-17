#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll N, a, b;
	for(cin>>N;N;cin>>N){
		
		cin>>a>>b;
		if(a == 0){
			cout<<N-1<<'\n';
			continue;
		}
		ll x = 0, cnt = N;
		vector<ll> V;
		set<ll> S;
		do{
			if(!S.count(x)){
				S.insert(x);
				V.emplace_back(x);
				x = (a*x%N*x%N+b%N)%N;
			}
			else{
				int cnt = 0;
				for(int i=0;i<V.size();i++){
					if(V[i] == x)	break;
					cnt++;
				}
				cout<<N-V.size()+cnt<<'\n';
				break;
			}
			
		}while(1);

	}

}