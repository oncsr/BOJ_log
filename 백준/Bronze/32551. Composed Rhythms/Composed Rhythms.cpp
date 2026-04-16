#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin>>N;
	if(N%3 == 0)	for(cout<<N/3<<'\n';N;N-=3)	cout<<"3 ";
	else	for(cout<<N/3+1<<"\n2 "<<(N%3 == 1 ? "2 " : "");N>4;N-=3)	cout<<"3 ";
}