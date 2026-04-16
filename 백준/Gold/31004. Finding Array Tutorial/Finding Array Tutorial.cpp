#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	bitset<1001> B;
	int N;
	cin>>N;
	int prev, now;
	cout<<"? 1 "<<N<<endl;
	cin>>prev;
	for(int i=N-1;i>=1;i--){
		cout<<"? 1 "<<i<<endl;
		cin>>now;
		if(now + 1 != prev)	B[i+1] = 1;
		prev = now;
	}
	cout<<"? 1 "<<N<<endl;
	cin>>prev;
	for(int i=2;i<=N;i++){
		cout<<"? "<<i<<' '<<N<<endl;
		cin>>now;
		if(now + 1 != prev)	B[i-1] = 1;
		prev = now;
	}
	vector<int> V;
	for(int i=1;i<=N;i++){
		if(!B[i])	V.push_back(i);
	}
	cout<<"! "<<V.size()<<' ';
	for(int i:V)	cout<<i<<' ';
	cout<<endl;

}