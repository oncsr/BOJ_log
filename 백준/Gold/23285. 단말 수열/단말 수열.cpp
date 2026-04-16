#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin>>N;
	vector<int> A(N-2), D(N+1,1);
	for(int &a:A)	cin>>a, D[a]++;

	vector<pair<int, int>> E = { {A.back(),N} };
	for(int &a:A){
		for(int i=1;i<=N;i++){
			if(D[i] == 1){
				E.emplace_back(min(a,i),max(a,i));
				D[a]--;
				D[i]--;
				break;
			}
		}
	}

	sort(E.begin(), E.end());
	for(auto &[a,b]:E)	cout<<a<<' '<<b<<'\n';

}