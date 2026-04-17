#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int gcd(int a, int b){
	if(a<b)	swap(a,b);
	return a%b?gcd(b,a%b):b;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll F[100004] = {0,1,1}, mod = 1e9+7, ans = 0;
	for(int i=3;i<=100002;i++)	F[i] = (F[i-1] + F[i-2])%mod;

	int N;
	cin>>N;
	for(int i=1;i<=N;i++){
		ans += F[gcd(i+1, N+1)];
		ans %= mod;
	}
	cout<<ans;

}