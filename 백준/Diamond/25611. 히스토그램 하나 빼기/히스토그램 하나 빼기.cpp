#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, s[500001]{}, e[500001]{}, l[500001]{}, r[500001]{};
ll h[500001]{}, v[500001]{}, ans[500001]{};

ll seg[1048576]{};

class DisjointSet {
	public:
	int r[500001]{};
	DisjointSet() {
		for(int i=1;i<=500000;i++) r[i] = i;
	}
	int f(int x) {return x==r[x] ? x : r[x]=f(r[x]);}
	void uni(int a, int b) {
		int x = f(a), y = f(b);
		if(x == y) return;
		r[x] = y;
	}
};

DisjointSet le, ri;

void prop(int s, int e, int n){
	if(seg[n]) {
		if(s != e) {
			seg[n*2] = max(seg[n*2], seg[n]);
			seg[n*2+1] = max(seg[n*2+1], seg[n]);
			seg[n] = 0;
		}
	}
}

void upt(int s, int e, int l, int r, ll v, int n) {
	prop(s, e, n);
	if (l > r || l > e || r < s) return;
	if (l <= s && e <= r) {
		seg[n] = max(seg[n], v);
		if(s != e) {
			seg[n*2] = max(seg[n*2], v);
			seg[n*2+1] = max(seg[n*2+1], v);
		}
		return;
	}
	int m = (s + e) >> 1;
	upt(s, m, l, r, v, n * 2);
	upt(m + 1, e, l, r, v, n * 2 + 1);
}

ll find(int s, int e, int i, int n) {
	prop(s,e,n);
	if(s == e) return seg[n];
	int m = (s+e)>>1;
	if(i <= m) return find(s,m,i,n*2);
	return find(m+1,e,i,n*2+1);
}

int main(){
	cin.tie(0)->sync_with_stdio(0);

	cin>>N;
	for(int i=1;i<=N;i++) {
		s[i] = i;
		e[i] = i;
		cin>>h[i];
	}
	
	stack<pair<int, int>> s1;
	for(int i=N;i>=1;i--) {
		while(!s1.empty() && s1.top().first > h[i]) {
			int x = s1.top().second;
			l[x] = i;
			s1.pop();
		}
		s1.push({h[i],i});
	}
	
	stack<pair<int, int>> s2;
	for(int i=1;i<=N;i++) {
		while(!s2.empty() && s2.top().first > h[i]) {
			int x = s2.top().second;
			r[x] = i;
			s2.pop();
		}
		s2.push({h[i],i});
	}

	vector<pair<ll,ll>> infos;
	for(int i=1;i<=N;i++) infos.push_back({h[i],i});
	sort(infos.begin(), infos.end(), [](auto a, auto b) -> bool {
		return a.first == b.first ? a.second < b.second : a.first > b.first;
	});

	bitset<500001> vis;

	for(int x=0;x<N;) {
		ll height = infos[x].first;
		vector<pair<ll,ll>> li;
		while(x<N && height == infos[x].first) {
			int idx = infos[x].second;
			vis[idx] = 1;
			li.push_back(infos[x++]);
			if(idx>1 && vis[idx-1]) {
				le.uni(idx, idx-1);
				ri.uni(idx-1, idx);
			}
			if(idx<N && vis[idx+1]) {
				le.uni(idx+1, idx);
				ri.uni(idx, idx+1);
			}
		}

		for(auto [_,idx] : li) {
			if(idx>1 && vis[idx-1]) s[idx] = le.f(idx-1);
			else s[idx] = idx;

			if(idx<N && vis[idx+1]) e[idx] = ri.f(idx+1);
			else e[idx] = idx;

			v[idx] = height * (e[idx] - s[idx] + 1);

			upt(1,N,s[idx],idx-1,v[idx]-h[idx],1);
			upt(1,N,idx+1,e[idx],v[idx]-h[idx],1);
			upt(1,N,1,s[idx]-1,v[idx],1);
			upt(1,N,e[idx]+1,N,v[idx],1);

			if(l[idx]) {
				int L = 0;
				if(l[idx]>1 && vis[l[idx]-1]) L = le.f(l[idx]-1);
				else L = l[idx];
				ans[l[idx]] = max(ans[l[idx]], h[idx] * (e[idx] - L));
			}

			if(r[idx]) {
				int R = 0;
				if(r[idx]<N && vis[r[idx]+1]) R = ri.f(r[idx]+1);
				else R = r[idx];
				ans[r[idx]] = max(ans[r[idx]], h[idx] * (R - s[idx]));
			}
		}
	}

	for(int i=1;i<=N;i++) {
		ans[i] = max(ans[i], find(1,N,i,1));
		if(h[i] == h[i-1] && ans[i] < ans[i-1]) ans[i] = ans[i-1];
		cout<<ans[i]<<' ';
	}

}