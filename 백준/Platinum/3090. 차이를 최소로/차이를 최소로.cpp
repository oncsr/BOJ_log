#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	ll n, t;
	cin>>n>>t;
	vector<ll> arr(n);
	ll mx = 0, mn = 1e9;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		mn = min(mn, arr[i]);
		if(i)	mx = max(mx, abs(arr[i] - arr[i-1]));
	}
	ll s = 0, e = mx, m = (s+e)>>1;
	while(s < e){
		ll chance = t;
		vector<ll> temp = arr;
		for(int i=0;i<n;i++){
			ll val = 0;
			if(i){
				val = max(val, temp[i] - temp[i-1] - m);
			}
			if(i != n-1){
				val = max(val, temp[i] - temp[i+1] - m);
			}
			temp[i] -= val;
			chance -= val;
		}
		for(int i=n-1;i>=0;i--){
			ll val = 0;
			if(i){
				val = max(val, temp[i] - temp[i-1] - m);
			}
			if(i != n-1){
				val = max(val, temp[i] - temp[i+1] - m);
			}
			temp[i] -= val;
			chance -= val;
		}
		if(chance < 0)	s = m+1;
		else 	e = m;
		m = (s+e)>>1;
	}
	vector<ll> temp = arr;
	for(int i=0;i<n;i++){
		ll val = 0;
		if(i){
			val = max(val, temp[i] - temp[i-1] - m);
		}
		if(i != n-1){
			val = max(val, temp[i] - temp[i+1] - m);
		}
		temp[i] -= val;
	}
	for(int i=n-1;i>=0;i--){
		ll val = 0;
		if(i){
			val = max(val, temp[i] - temp[i-1] - m);
		}
		if(i != n-1){
			val = max(val, temp[i] - temp[i+1] - m);
		}
		temp[i] -= val;
	}
	for(int i=0;i<n;i++)	cout<<temp[i]<<' ';
}