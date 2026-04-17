#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pl = pair<ll, ll>;
#define x first
#define y second

int ccw(pl p1, pl p2, pl p3) {
  auto [x1, y1] = p1;
  auto [x2, y2] = p2;
  auto [x3, y3] = p3;
  int xx = (x1 * y2 + x2 * y3 + x3 * y1) - (x2 * y1 + x3 * y2 + x1 * y3);
  return xx > 0 ? 1 : (xx < 0 ? -1 : 0);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T;
	for(cin>>T;T--;){
		int N;
		cin>>N;
		vector<pl> arr(N);
		for(auto &[a, b] : arr)	cin>>a>>b;
		sort(arr.begin(), arr.end());

		vector<pl> L, U;
		for(auto i:arr){
			while(L.size() >= 2 && ccw(i, L.back(), L[L.size()-2]) <= 0)	L.pop_back();
			L.emplace_back(i);
			while(U.size() >= 2 && ccw(i, U.back(), U[U.size()-2]) >= 0)	U.pop_back();
			U.emplace_back(i);
		}
		vector<pl> hull;
		for(int i=0;i<L.size()-1;i++)	hull.emplace_back(L[i]);
		for(int i=U.size()-1;i>0;i--)	hull.emplace_back(U[i]);

		sort(hull.begin(), hull.end(), [&](pl a, pl b){
			if(a.second == b.second)	return a.first < b.first;
			return a.second > b.second;
		});
		sort(hull.begin() + 1, hull.end(), [&](pl a, pl b){
			return ccw(hull[0], a, b) < 0;
		});
		cout<<hull.size()<<'\n';
		for(auto [a,b] : hull)	cout<<a<<' '<<b<<'\n';
	}

}