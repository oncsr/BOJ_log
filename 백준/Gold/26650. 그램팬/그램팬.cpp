#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	string s;
	cin>>s;
	ll ans = 0;
	int prev = 'A'-1;
	ll cnt = 0;
	for(char i:s){
		if(i == prev){
			if(i == 'A')	cnt++;
			if(i == 'Z')	ans += cnt;
			continue;
		}
		if(i == prev+1){
			if(i == 'A')	cnt++;
			if(i == 'Z')	ans += cnt;
			prev = i;
		}
		else{
			cnt = 0;
			prev = 'A'-1;
			if(i == 'A')	prev = i, cnt++;
		}
	}
	cout<<ans;

}