#include <bits/stdc++.h>
using namespace std;

long double b,c,p,q;

int main(){
	cin.tie(0)->sync_with_stdio(0);

	cin>>b>>c>>p>>q;
    cout.precision(10);
    cout<<(b + sqrtl(b*b + 4*c)) / 2;

}