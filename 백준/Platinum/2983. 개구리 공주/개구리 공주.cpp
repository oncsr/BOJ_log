#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M;
	string K;
	cin >> N >> M >> K;
	pair<int, int> s = { -1,-1 };
	map<int, set<int>> positive, negative;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		positive[b - a].insert(b);
		negative[b + a].insert(b);
		if (s.first == -1)	s = { a,b };
	}

	for (char i : K) {
		auto [x, y] = s;
		auto& posi = positive[y - x];
		auto& nega = negative[y + x];
		if (i == 'A' || i == 'D') {
			set<int>::iterator pos = posi.find(y);
			if (i == 'A') {
				pos++;
				if (pos == posi.end())	continue;
			}
			else {
				if (pos == posi.begin())	continue;
				pos--;
			}
			int yy = *pos;
			int xx = yy - y + x;
			s = { xx,yy };
			posi.erase(y);
			nega.erase(y);
		}
		else {
			set<int>::iterator pos = nega.find(y);
			if (i == 'C') {
				pos++;
				if (pos == nega.end())	continue;
			}
			else {
				if (pos == nega.begin())	continue;
				pos--;
			}
			int yy = *pos;
			int xx = x + y - yy;
			s = { xx,yy };
			posi.erase(y);
			nega.erase(y);
		}
	}
	cout << s.first << ' ' << s.second;

}