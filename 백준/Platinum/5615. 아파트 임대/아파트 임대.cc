#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

const ll chk[3] = {2,7,61};

ll power(ll a, ll p, ll m){
    if(p == 0)  return 1;
    if(p == 1)  return a;
    ll v = power(a, p>>1, m) % m;
    return (p&1)?v*v%m*a%m:v*v%m;
}

int miller_rabin(ll n)
{
	// Small or Even number case
	if(n <= 1)	return 0;
	if(n <= 3)	return 1;
	if(!(n&1))	return 0;

	for(int i=0;i<3;i++){

		uint64_t c = n-1;
		if(n == chk[i])	return 1;
		int isPrime = 0;

		// c = 2^(k-1)*q  ~  q
		while(!(c&1)){
			c >>= 1;
			if(power(chk[i], c, n) == n-1){isPrime = 1;break;}
		}
		if(power(chk[i], c, n) == 1)	isPrime = 1;

		// If n is composite number, than return immediately
		if(!isPrime)	return 0;
	}
	return 1;
	
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n, ans = 0;
    for(cin>>n;n--;){
        uint64_t N;
        cin>>N;
        N = 2*N+1;
        ans += miller_rabin(N);
    }
    cout<<ans;

}