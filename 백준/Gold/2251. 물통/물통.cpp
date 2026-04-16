#include <bits/stdc++.h>
using namespace std;

int main(){
	int A,B,C;
	cin>>A>>B>>C;
	int vis[201][201][201]{};
	
	queue<tuple<int,int,int>> Q;
	vis[0][0][C]++;
	Q.emplace(0,0,C);
	
	int ans[201]{};
	
	while(!Q.empty()){
		auto [a,b,c] = Q.front();
		if(!a) ans[c]++;
		Q.pop();
		if(a){
			int f=min(a,B-b);
			if(!vis[a-f][b+f][c]){
				Q.emplace(a-f,b+f,c);
				vis[a-f][b+f][c]++;
			}
			int g=min(a,C-c);
			if(!vis[a-g][b][c+g]){
				Q.emplace(a-g,b,c+g);
				vis[a-g][b][c+g]++;
			}
		}
		if(b){
			int f=min(b,A-a);
			if(!vis[a+f][b-f][c]){
				Q.emplace(a+f,b-f,c);
				vis[a+f][b-f][c]++;
			}
			int g=min(b,C-c);
			if(!vis[a][b-g][c+g]){
				Q.emplace(a,b-g,c+g);
				vis[a][b-g][c+g]++;
			}
		}
		if(c){
			int f=min(c,A-a);
			if(!vis[a+f][b][c-f]){
				Q.emplace(a+f,b,c-f);
				vis[a+f][b][c-f]++;
			}
			int g=min(c,B-b);
			if(!vis[a][b+g][c-g]){
				Q.emplace(a,b+g,c-g);
				vis[a][b+g][c-g]++;
			}
		}
	}
	for(int i=0;i<=C;i++){
		if(ans[i]) cout<<i<<' ';
	}
}