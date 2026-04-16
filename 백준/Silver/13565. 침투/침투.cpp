#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int M, N;
	cin>>M>>N;
	bool arr[1000][1000]{}, vis[1000][1000]{};
	for(int i=0;i<M;i++)	for(int j=0;j<N;j++){
		char a;
		cin>>a;
		arr[i][j] = a=='1';
	}

	queue<pair<int, int>> Q;
	for(int j=0;j<N;j++)	if(!arr[0][j])	Q.emplace(0,j), vis[0][j]=1;

	int dx[4] = {1,0,-1,0};
	int dy[4] = {0,1,0,-1};
	while(!Q.empty()){
		auto [x,y] = Q.front();	Q.pop();
		if(x == M-1)	return cout<<"YES", 0;
		for(int k=0;k<4;k++){
			int xx = x+dx[k], yy = y+dy[k];
			if(xx < 0 || xx >= M || yy < 0 || yy >= N || vis[xx][yy] || arr[xx][yy])	continue;
			Q.emplace(xx,yy);
			vis[xx][yy] = 1;
		}
	}
	cout<<"NO";

}