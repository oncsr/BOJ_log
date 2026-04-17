#include <bits/stdc++.h>
using namespace std;

deque<char> operator+(deque<char> a, deque<char> b) {
	deque<char> c;
	for (char i : a)	c.push_back(i);
	for (char i : b)	c.push_back(i);
	return c;
}

struct cmp {
	bool operator()(deque<char> b, deque<char> a) {
		return a + b < b + a;
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);

	string arr[20]{};
	int N;
	cin >> N;
	priority_queue<deque<char>, vector<deque<char>>, cmp> Q;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		deque<char> D;
		for (char j : arr[i])	D.push_back(j);
		Q.push(D);
	}
	string ans = "";
	while (!Q.empty()) {
		deque<char> now = Q.top();
		Q.pop();
		ans += now[0];
		now.pop_front();
		if (!now.empty())	Q.push(now);
	}
	cout << ans;

}