#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M;
	cin>>N>>M;
	int dp[502][502]{}, arr[502][502]{};
	vector<pair<int, int>> info[10001]{};
	for(int i=1;i<=N;i++)	for(int j=1;j<=M;j++){
		cin>>arr[i][j];
		info[arr[i][j]].emplace_back(i,j);
	}
	dp[1][1] = 1;

	int dx[4] = {1,0,-1,0};
	int dy[4] = {0,1,0,-1};
	for(int i=10000;i>0;i--){
		for(auto &[x,y]:info[i]){
			for(int k=0;k<4;k++){
				int xx = x+dx[k], yy = y+dy[k];
				if(arr[xx][yy] > arr[x][y])	dp[x][y] += dp[xx][yy];
			}
		}
	}
	cout<<dp[N][M];

}