#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int g[3000001]{};
	int fib[3000001]{};
	
	int t = 1, x = 2;
	fib[t]++;
	while(x <= 3000000){
		fib[x]++;
		int temp = t;
		t = x;
		x += temp;
	}
	
	vector<int> F;
	for(int i=1;i<=3000000;i++){
		int vis[20]{};
		if(fib[i])	F.push_back(i);
		for(int j:F)	vis[g[i-j]]++;
		int c = 0;
		for(int j=0;j<20;j++){
			if(!vis[j])	break;
			c++;
		}
		g[i] = c;
	}

	int N;
	cin>>N;
	int ans = 0;
	
	for(int i=0;i<N;i++){
		int a;
		cin>>a;
		ans ^= g[a];
	}
	cout<<(ans ? "koosaga":"cubelover");
	

}