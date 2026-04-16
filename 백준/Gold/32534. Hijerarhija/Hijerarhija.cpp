#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin>>N;
	set<pair<int, int>> S;
	vector<int> D(N+1);
	int one = 0, zero = 0;
	for(int i=1;i<N;i++){
		int a,b;
		cin>>a>>b;
		S.emplace(a,b);
		D[b]++;
	}
	for(int i=1;i<=N;i++){
		if(!D[i])	zero++;
		else if(D[i] == 1)	one++;
	}

	if(zero == 1 && one == N-1)	cout<<"DA\n";
	else 	cout<<"NE\n";

	int Q;
	for(cin>>Q;Q--;){
		int a,b;
		cin>>a>>b;
		
		if(S.count(make_pair(b,a)))	swap(a,b);

		D[a]++;
		if(D[a] > 1)	one--;
		else if(D[a] == 1)	zero--, one++;

		D[b]--;
		if(D[b] == 1)	one++;
		else if(D[b] == 0)	one--, zero++;
		
		S.erase(make_pair(a,b));
		S.emplace(b,a);

		if(zero == 1 && one == N-1)	cout<<"DA\n";
		else 	cout<<"NE\n";

	}

}