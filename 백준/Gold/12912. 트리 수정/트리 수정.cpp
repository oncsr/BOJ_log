#include <iostream>
#include <vector>
#include <functional>
using namespace std;
using ll = long long;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	
	int N;
	cin>>N;
	vector<tuple<int, int, int>> edge(N-1);
	
	for(auto &[a,b,c]:edge) cin>>a>>b>>c;
	ll ans=0;
	for(int i=0;i<N-1;i++){
		vector<vector<pair<int, ll>>> V(N);
        vector<int> vis(N);
		ll arr[2]{};
		ll v=0;
		function<ll(int, int, int)> dfs = [&](int n, int p, int k) -> ll {
			ll mx=0, mx2=0;
			for(auto &[i,c]:V[n]){
				if(vis[i] || i==p)continue;
                vis[i]++;
				ll res=dfs(i,n,k)+c;
				if(res>mx) mx2=mx, mx=res;
				else if(res>mx2)mx2=res;
			}
			arr[k] = max(arr[k], mx+mx2);
            return mx;
		};
		for(int j=0;j<N-1;j++){
			auto &[a,b,c] = edge[j];
			if(i==j){v=c;continue;}
			V[a].emplace_back(b,c);
			V[b].emplace_back(a,c);
		}
		
		int g=0;
		for(int i=0;i<N;i++){
			if(vis[i])continue;
            vis[i]++;
			dfs(i,0,g++);
		}
		ans=max(ans, arr[0]+arr[1]+v);
	}
	cout<<ans;
}