#include <bits/stdc++.h>
using namespace std;
using ll = long long;
deque<ll> V = {1,1};

ll ans = 0;
map<ll,int> ex;
void bck(ll now, int pos){
	if(now == 1)	{ans++;return;}
	for(int i=pos;i<V.size();i++){
		if(now % V[i])	continue;
		if(V[i]*V[i] > now){
			if(ex.find(now) != ex.end())	ans++;
			break;
		}
		bck(now/V[i], i);
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	while(V.back() <= 1e18)	V.push_back(V.back() + V[V.size()-2]);
	V.pop_back();
	for(ll i:V)	ex[i]=1;
	V.pop_front();	V.pop_front();
	

	int T;
	for(cin>>T;T--;ans = 0){
		ll n;
		cin>>n;
		bck(n,0);
		cout<<ans<<'\n';
	}

}