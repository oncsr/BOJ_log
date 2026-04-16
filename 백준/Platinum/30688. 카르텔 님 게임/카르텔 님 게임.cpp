#include <bits/stdc++.h>
using namespace std;

int main() {

	string a = "A and B win", c = "C win";
	int n,k;
	cin>>n>>k;
	if(n == k)	cout<<a;
	else if(n <= k+2)	cout<<c;
	else if(n > 2*k + 1)	cout<<c;
	else 	cout<<a;

}