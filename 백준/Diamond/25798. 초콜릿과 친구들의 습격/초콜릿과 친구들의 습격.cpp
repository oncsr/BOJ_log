#include <iostream>
#include <cassert>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
	int T;
	for (cin >> T; T--;) {
		int N, M, K, x, y, zeros = 0, ones = 0, cho[4][2], minus = 0, plus = 0;
		bool ul[2]{}, ur[2]{}, dl[2]{}, dr[2]{};
		cin >> N >> M >> K;
		for (int i = 0; i < K; i++) {
			cin >> x >> y;
			cho[i][0] = x, cho[i][1] = y;

			if (x == 1 && y == 2)	ul[0] = true;
			if (x == 2 && y == 1)	ul[1] = true;
			if (x == 1 && y == M - 1)	ur[0] = true;
			if (x == 2 && y == M)	ur[1] = true;
			if (x == N - 1 && y == 1)	dl[0] = true;
			if (x == N && y == 2)	dl[1] = true;
			if (x == N - 1 && y == M)	dr[0] = true;
			if (x == N && y == M - 1)	dr[1] = true;
			
			if ((x % 2) ^ (y % 2))	zeros++;
			else	ones++;
		}

		if ((ul[0] && ul[1]) || (ur[0] && ur[1])) {
			minus++;
			if (ul[0] && ul[1]) {
				bool find = false;
				for (int i = 0; i < K; i++) {
					if (cho[i][0] == 1 && cho[i][1] == 1) {
						find = true;
						break;
					}
				}
				if (find)	minus--;
			}
			else {
				bool find = false;
				for (int i = 0; i < K; i++) {
					if (cho[i][0] == 1 && cho[i][1] == M) {
						find = true;
						break;
					}
				}
				if (find)	minus--;
			}
		}
		if ((dl[0] && dl[1]) || (dr[0] && dr[1])) {
			minus++;
			if (dl[0] && dl[1]) {
				bool find = false;
				for (int i = 0; i < K; i++) {
					if (cho[i][0] == N && cho[i][1] == 1) {
						find = true;
						break;
					}
				}
				if (find)	minus--;
			}
			else {
				bool find = false;
				for (int i = 0; i < K; i++) {
					if (cho[i][0] == N && cho[i][1] == M) {
						find = true;
						break;
					}
				}
				if (find)	minus--;
			}
		}



		if (K == 0)	cout << N * M / 2 << '\n';
		else if (K == 1)	cout << N * M / 2 - 1 << '\n';
		else {
			int t = max(zeros, ones);
			int diff = abs(zeros - ones);
			cout << (N * M - min(K * 2, (K + max(minus, diff)))) / 2 << '\n';
		}
	}
}