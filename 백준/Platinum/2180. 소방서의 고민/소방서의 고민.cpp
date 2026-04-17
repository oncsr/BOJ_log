#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

bool cmp(ii a, ii b){
	if(b.first * a.second == a.first * b.second){
			if(a.first == b.first)	return a.second > b.second;
			return a.first > b.first;
		}
		return (b.first * a.second) < (a.first * b.second);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int N;
	ii arr[200000]{};
	cin>>N;
	for(int i=0;i<N;i++){
		int a,b;
		cin>>a>>b;
		arr[i] = {a,b};
	}
	sort(arr, arr+N, cmp);

	int ans = 0;
	for(int i=0;i<N;i++){
		ans = (ans + arr[i].first * ans + arr[i].second) % 40000;
	}
	cout<<ans;

}