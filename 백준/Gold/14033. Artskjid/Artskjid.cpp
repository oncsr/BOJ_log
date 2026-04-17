#include <bits/stdc++.h>
using namespace std;

int D[18][1<<18]{};
vector<vector<int>> edge(18, vector<int>(18, -1e6));
int N, M;

int dp(int n, int k){
	if(D[n][k])	return D[n][k];
	int g = k - (1<<n);
	for(int i=1;(1<<i)<=g;i++){
		if(!(g & (1<<i)))	continue;
		if(!D[i][g])	D[i][g] = dp(i,g);
		if(!D[n][k])	D[n][k] = D[i][g] + edge[i][n];
		else 	D[n][k] = max(D[i][g] + edge[i][n], D[n][k]);
	}
	return D[n][k];
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	cin>>N>>M;
	for(int i=0;i<M;i++){
		int a,b,c;
		cin>>a>>b>>c;
		edge[a][b] = max(edge[a][b], c);
	}
	for(int i=1;i<N;i++)	D[i][(1<<i) + 1] = edge[0][i];
	int ans = 0;
	for(int i=(1<<(N-1))+1;i<(1<<N);i+=2){
		ans = max(ans, dp(N-1, i));
	}
	cout<<ans;

}