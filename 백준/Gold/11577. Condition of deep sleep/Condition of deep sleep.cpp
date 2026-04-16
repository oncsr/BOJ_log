#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll N, K, s = 0, arr[100001]{}, ans = 0, a;
	cin>>N>>K;
	for(int i=0;i<N;i++){
		cin>>a;
		s += arr[i];
		a += s;
		if(a&1)	{
			if(i+K <= N)	s++, arr[i+K]--, ans++;
			else 	return cout<<"Insomnia", 0;
		}
	}
	cout<<ans;

}