#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	ll N, Q, row = 1, col = 0, g = 0, t;
	cin>>N>>Q>>t;
	if(t != N)	return cout<<-1,0;
	g = t;
	vector<pair<char, int>> ans;
	ans.emplace_back('R',1);
	for(int i=1;i<Q;i++){
		ll a;
		cin>>a;
		if(a == g+N-2*col){
			if(row == N)	return cout<<-1,0;
			ans.emplace_back('R',++row);
		}
		else if(a == g+N-2*row){
			if(col == N)	return cout<<-1,0;
			ans.emplace_back('C',++col);
		}
		else if(a == g-N+2*col){
			if(!row)	return cout<<-1,0;
			ans.emplace_back('R',row--);
		}
		else if(a == g-N+2*row){
			if(!col)	return cout<<-1,0;
			ans.emplace_back('C',col--);
		}
		else 	return cout<<-1,0;
		g = a;
	}
	for(auto &[a,b]:ans)	cout<<a<<' '<<b<<'\n';

}