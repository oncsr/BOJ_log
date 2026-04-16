#include <bits/stdc++.h>
using namespace std;
 
int main() {
	cin.tie(0)->sync_with_stdio(0);
 
	int N, M;
	cin >> N;
	// todo = {deadline, needtime}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> todo;
	// yet = {addtime, deadline, needtime}
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> yet;
 
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		todo.emplace(b, a);
	}
 
	cin >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		yet.emplace(a, c, b);
	}
 
	int T = 0;
	while (!todo.empty() || !yet.empty()) {
		int dead, time;
		if (todo.empty()) {
			T = get<0>(yet.top());
			dead = get<1>(yet.top());
			time = get<2>(yet.top());
			yet.pop();
		}
		else {
			dead = get<0>(todo.top());
			time = get<1>(todo.top());
			todo.pop();
		}
		if (yet.empty()) {
			T += time;
			if (T > dead) { cout << "NO"; return 0; }
		}
		else {
			auto [add, dead2, time2] = yet.top();
			yet.pop();
			if (T + time <= add) {
				yet.emplace(add, dead2, time2);
				T += time;
				if (T > dead) { cout << "NO"; return 0; }
			}
			else {
				int v = add - T;
				todo.emplace(dead, time - v);
				T += v;
				if (T > dead) { cout << "NO"; return 0; }
				todo.emplace(dead2, time2);
			}
		}
	}
	cout << "YES\n" << T;
 
 
 
}
