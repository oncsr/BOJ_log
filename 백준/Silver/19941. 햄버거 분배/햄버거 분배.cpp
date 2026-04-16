#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(0)->sync_with_stdio(0);

	int N, K;
	string S;
	cin>>N>>K>>S;

	int id = 0, ans = 0;
	for(int i=0;i<N;i++){
		if(S[i] == 'H')	continue;
		while(id < i-K)	id++;
		while(id < N && id - i <= K && S[id] == 'P')	id++;
		if(id < N && S[id] == 'H' && abs(id - i) <= K)	ans++, id++;
	}
	cout<<ans;

}