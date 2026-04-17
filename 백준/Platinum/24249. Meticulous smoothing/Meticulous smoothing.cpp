#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	ll n, ans = 0;
	cin>>n;
	vector<ll> arr(n);
	for(int i=0;i<n;i++)	cin>>arr[i];
	for(int i=0;i<n;i++){
		ll val = 0;
		if(i)	val = max(val, arr[i] - arr[i-1] - 1);
		if(i != n-1)	val = max(val, arr[i] - arr[i+1] - 1);
		arr[i] -= val;
		ans += val;
	}
	for(int i=n-1;i>=0;i--){
		ll val = 0;
		if(i)	val = max(val, arr[i] - arr[i-1] - 1);
		if(i != n-1)	val = max(val, arr[i] - arr[i+1] - 1);
		arr[i] -= val;
		ans += val;
	}
	cout<<ans;
}