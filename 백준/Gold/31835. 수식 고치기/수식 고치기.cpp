#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	char d, e;
	cin>>N>>d;
	int a = d == 'T', b, p;
	for(int i=1;i<N;i+=2){
		cin>>d>>e;
		b = e == 'T';
		p = a;
		if(d == '&')	a = (a & b);
		else 	a = (a | b);
	}
	cin>>e;
	int c = e == 'T';
	if(N == 1)	return cout<<int(a != c), 0;
	if(c == a)	return cout<<0, 0;
	if(d == '&'){
		if(c)	cout<<int(p==0)+int(b==0);
		else 	cout<<1;
		return 0;
	}
	if(c)	cout<<1;
	else 	cout<<int(p==1)+int(b==1);

}