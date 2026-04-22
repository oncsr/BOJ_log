#include <iostream>
using namespace std;
using ll = long long;

int main(){
	ll d, m, c[2001] = {1};
	cin>>d>>m;
	d/=2;
	for(int i=1;i<=d;i++){
		for(int j=0;j<i;j++){
			c[i] = (c[i] + c[j]*c[i-j-1])%m;
		}
	}
	cout<<c[d-1]%m;
}