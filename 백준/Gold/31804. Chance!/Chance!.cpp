#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int a,b;
	cin>>a>>b;
	int vis[1000001][2]{};
	vis[a][0] = 1;
	queue<tuple<int, int, int>> Q;
	Q.emplace(a,0,1);
	while(!Q.empty()){
		auto [num, ch, t] = Q.front();
		Q.pop();
		if(num == b)	{cout<<t-1;return 0;}
		if(num + 1 <= b && !vis[num+1][ch]){
			vis[num+1][ch]++;
			Q.emplace(num+1, ch, t+1);
		}
		if(num * 2 <= b && !vis[num*2][ch]){
			vis[num*2][ch]++;
			Q.emplace(num*2, ch, t+1);
		}
		if(!ch && num * 10 <= b && !vis[num*10][1]){
			vis[num*10][1]++;
			Q.emplace(num*10, 1, t+1);
		}
	}

}