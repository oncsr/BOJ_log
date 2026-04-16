#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int dx[4] = {1,0,-1,0};
	int dy[4] = {0,1,0,-1};
	int M, N, arr[1000][1000]{}, mx = 0, tot = 0;
	cin>>M>>N;
	queue<tuple<int, int, int>> Q;
	vector<vector<bool>> vis(1000, vector<bool>(1000,0));
	for(int i=0;i<N;i++)	for(int j=0;j<M;j++){
		cin>>arr[i][j];
		if(arr[i][j] != -1)	tot++;
		if(arr[i][j] == 1)	Q.emplace(i,j,0), vis[i][j]=1;
	}

	while(!Q.empty()){
		auto [x,y,t] = Q.front();
		Q.pop();
		mx = max(mx, t);
		tot--;
		for(int i=0;i<4;i++){
			int xx = x+dx[i], yy = y+dy[i];
			if(xx < 0 || xx >= N || yy < 0 || yy >= M || vis[xx][yy] || arr[xx][yy])	continue;
			Q.emplace(xx,yy,t+1);
			vis[xx][yy] = 1;
		}
	}
	cout<<(tot ? -1 : mx);

}