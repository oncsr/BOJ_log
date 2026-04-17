#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll C[19] = { 1 };

void solve(ll c, ll k){
	ll cnt = 0;
	for(int i=0;i<c;i++){
		cnt += C[i] * C[c-1-i];
		if(cnt >= k){
			cnt -= C[i] * C[c-1-i];
			k -= cnt;
			if(i){
				cout<<'(';
				solve(i, (k-1)/C[c-1-i] + 1);
				cout<<')';
			}
			cout<<'X';
			if(c-1-i){
				cout<<'(';
				solve(c-1-i, k%C[c-1-i] ? k%C[c-1-i] : C[c-1-i]);
				cout<<')';
			}
			break;
		}
	}

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	ll cnt = 0;
	for (ll i = 1; i <= 18; i++) {
		for (ll j = 0; j < i; j++)
			C[i] += C[j] * C[i - 1 - j];
		cnt += C[i];
	}

	ll n;
	for(cin>>n;n;cin>>n){
		cnt = 0;
		for(int i=1;i<19;i++){
			cnt += C[i] ;
			if(cnt >= n){
				cnt -= C[i];
				solve(i,n-cnt);
				break;
			}
		}
		cout<<endl;
	}

}