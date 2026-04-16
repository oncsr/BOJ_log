#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin>>N;
	char arr[2][50]{};
	int white = 0;
	for(int i=0;i<N;i++)	cin>>arr[0][i], white += arr[0][i] == '.';
	for(int i=0;i<N;i++)	cin>>arr[1][i], white += arr[1][i] == '.';

	queue<tuple<int, int, int>> Q;
	int vis[2][50]{};
	if(arr[0][0] == '.')	Q.emplace(0,0,1), vis[0][0]++;
	if(arr[1][0] == '.')	Q.emplace(1,0,1), vis[1][0]++;

	int dx[4] = {1,0,-1,0};
	int dy[4] = {0,1,0,-1};
	while(!Q.empty()){
		auto [x,y,t] = Q.front();	Q.pop();
		if(y == N-1)	return cout<<white - t, 0;
		for(int i=0;i<4;i++){
			int xx = x+dx[i], yy = y+dy[i];
			if(xx < 0 || xx > 1 || yy < 0 || yy >= N || vis[xx][yy] || arr[xx][yy] == '#')	continue;
			Q.emplace(xx,yy,t+1);
			vis[xx][yy]++;
		}
	}

}