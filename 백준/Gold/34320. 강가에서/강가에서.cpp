#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<vector<int>> open_num, close_num;
bitset<200001> s;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	
	cin>>N>>K;
	open_num.resize(K+2);
	close_num.resize(K+2);
	
	for(int i=1,a;i<=N;i++) {
		cin>>a;
		open_num[a].push_back(i);
	}
	
	for(int i=1,a;i<=N;i++) {
		cin>>a;
		close_num[a+1].push_back(i);
	}
	
	int cnt = 0;
	for(int t=1;t<=K;t++) {
		for(int store : open_num[t]) {
			s[store] = 1;
			int ex = s[store-1] + s[store+1];
			cnt += 1-ex;
		}
		for(int store : close_num[t]) {
			s[store] = 0;
			int ex = s[store-1] + s[store+1];
			cnt += ex-1;
		}
		cout<<cnt<<' ';
	}
	
}