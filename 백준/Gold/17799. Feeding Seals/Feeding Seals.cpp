#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using ll = long long;


int main(){
	cin.tie(0)->sync_with_stdio(0);

	int n, c;
	cin>>n>>c;
	int ans =0;
	vector<int> Q;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		Q.emplace_back(a);
	}
	sort(Q.begin(), Q.end());
	int s = 0, e = n-1;
	while(s<e){
		if(Q[s] + Q[e] <= c){
			s++;
			e--;
		}
		else{
			e--;
		}
		ans++;
	}
	if(s==e)	ans++;
	cout<<ans;

}