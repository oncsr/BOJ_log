#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin>>N;
	vector<int> A(N-2), D(N+1,1);
	for(int &a:A)	cin>>a, D[a]++;

	vector<pair<int, int>> E = { {1,A.back()} };
	priority_queue<int> Q;
	for(int i=1;i<=N;i++)	if(D[i] == 1)	Q.push(i);

	for(int &a:A){
		int b = Q.top();	Q.pop();
		E.emplace_back(min(a,b),max(a,b));
		D[a]--,D[b]--;
		if(D[a] == 1)	Q.push(a);
	}

	sort(E.begin(), E.end());
	for(auto &[a,b]:E)	cout<<a<<' '<<b<<'\n';

}