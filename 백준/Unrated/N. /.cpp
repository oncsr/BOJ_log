#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	ll N, a, temp;
	cin>>N>>a;
	ll ans = 2*N + 3*a;
	temp = a;
	for(int i=1;i<N;i++){
		cin>>a;
		ans += a * 2;
		ans += abs(a - temp);
		temp = a;
	}
	ans += a;
	cout<<ans;

}