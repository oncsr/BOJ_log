#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(0)->sync_with_stdio(0);

	int n, m;

	vector<vector<int>> dist(101, vector<int>(101, 1e9));
	vector<int> route[101][101]{};

	for(cin>>n>>m;m--;){
		int a,b,c;
		cin>>a>>b>>c;
		dist[a][b] = min(dist[a][b], c);
		route[a][b] = {b};
	}

	for(int i=1;i<=n;i++){
		dist[i][i] = 0;
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(dist[j][k] > dist[j][i] + dist[i][k]){
					dist[j][k] = dist[j][i] + dist[i][k];
					route[j][k] = route[j][i];
					for(int d:route[i][k])	route[j][k].emplace_back(d);
				}
			}
		}
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<(dist[i][j] == 1e9 ? 0 : dist[i][j])<<' ';
		}
		cout<<'\n';
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i == j || dist[i][j] == 1e9){cout<<"0\n";continue;}
			cout<<route[i][j].size() + 1<<' '<<i<<' ';
			for(int k:route[i][j])	cout<<k<<' ';
			cout<<'\n';
		}
	}
	

}