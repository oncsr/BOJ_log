#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;
using pl = pair<ll, ll>;

/*
 < 2023.05.22 >
 [used algorithm]
 > greedy, priority queue
 [point]
 변화율 기준 양수는 단순정렬
 음수는 변화율 - first 최댓값이 최대가 되게 정렬
*/

struct cmp {
	bool operator()(pl a, pl b) {
		if (a.first == b.first)	return a.second < b.second;
		return a.first > b.first;
	}
};

struct cmp2 {
	bool operator()(pl a, pl b) {
		if (a.second == b.second)	return a.first > b.first;
		return a.second < b.second;
	}
};
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N;
	cin >> N;
	priority_queue<pl, vector<pl>, cmp> Q;

	priority_queue<pl, vector<pl>, cmp2> W;
	int pos = 0;
	for (int i = 0; i < N; i++) {
		ll a, b;
		cin >> a >> b;
		if (b - a >= 0)	Q.push({ a,b });
		else	W.push({ a,b });
		
	}
	ll s = 0;
	while (!Q.empty()) {
		s -= Q.top().first;
		if (s < 0) {
			cout << 0;
			return 0;
		}
		s += Q.top().second;
		Q.pop();
	}

	while (!W.empty()) {
		s -= W.top().first;
		if (s < 0) {
			cout << 0;
			return 0;
		}
		s += W.top().second;
		W.pop();
	}

	
	cout << 1;
	

}