#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int a,b,c;
	cin>>a>>b>>c;
	if(c == 0)	cout<<int(sqrt(a+b));
	else 	cout<<c*c-(a+b);

}