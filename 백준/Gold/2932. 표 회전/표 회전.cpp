#include <iostream>
using namespace std;
using ii = pair<int, int>;
using iii = pair<ii, ii>;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, K;
	int id = 0;
	iii Q[1000]{};
	for (cin >> N >> K; K--;) {
		int a, r, c;
		cin >> a >> r >> c;
		int x = (a - 1) / N + 1, y = (a - 1) % N + 1;
		for (int i = 0; i < id; i++) {
			int rownum = Q[i].first.first, colnum = Q[i].second.first;
			int R = Q[i].first.second, C = Q[i].second.second;
			if (x == rownum)	y += R;
			if (y > N)	y -= N;
			if (y == colnum)	x += C;
			if (x > N)	x -= N;
		}
		int rownum = x;
		int R = c - y;
		if (R < 0)	R += N;
		int colnum = c;
		int C = r - x;
		if (C < 0)	C += N;
		cout << R + C << '\n';
		Q[id++] = { {rownum,R}, {colnum,C} };
		
	}

}