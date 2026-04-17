#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin>>N;
	int mx = 0, mx2 = 0;
	int benefit[300000]{};
	for(int i=0;i<N;i++){
		int a;
		cin>>a;
		benefit[i] = a;
		if(a > mx)	mx2 = mx, mx = a;
		else if(a > mx2)	mx2 = a;
	}
	for(int i=0;i<N;i++){
		int b = benefit[i], p;
		cin>>p;
		cout<<b - (b == mx ? mx2 : mx)<<' ';
	}

}