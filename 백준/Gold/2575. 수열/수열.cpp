#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
	int M;
	cin>>M;
	int a = (M-1)/3 + 1, b = M == 1;
	while(M%4 == 0){
		b++;
		M/=4;
	}
	for(int i=2;i*i<=M;i++){
		while(M%i == 0){
			b++;
			M/=i;
		}
	}
	if(M > 1) b++;
	cout<<a<<' '<<b;
    
}