#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;
	deque<int> arr(N);
	for (int& i : arr)	cin >> i;

	for (int k1 = 1; (1 << k1) < N; k1++) {
		for (int k2 = 1; (1 << k2) < N; k2++) {
			deque<int> temp(N);
			deque<deque<int>> res;
			iota(temp.begin(), temp.end(), 1);
			// (2, k1) - 섞기

			deque<int> D;
			for (int i = 0; i < N - (1 << k1); i++)
				D.push_back(temp.front()), temp.pop_front();
			res.push_front(D);
			for (int k = k1 - 1; k >= 0; k--) {
				D = deque<int>();
				for (int i = 0; i < (1 << k); i++)
					D.push_back(temp.front()), temp.pop_front();
				res.push_front(D);
			}
			res.push_front(temp);

			temp = deque<int>();
			for (auto i : res)	for (int j : i)	temp.push_back(j);
			// (2, k2) - 섞기

			D = deque<int>();
			res = deque<deque<int>>();
			for (int i = 0; i < N - (1 << k2); i++)
				D.push_back(temp.front()), temp.pop_front();
			res.push_front(D);
			for (int k = k2 - 1; k >= 0; k--) {
				D = deque<int>();
				for (int i = 0; i < (1 << k); i++)
					D.push_back(temp.front()), temp.pop_front();
				res.push_front(D);
			}
			res.push_front(temp);

			temp = deque<int>();
			for (auto i : res)	for (int j : i)	temp.push_back(j);
			// 정답 판별
			if (temp == arr)	return cout << k1 << ' ' << k2, 0;

		}
	}

}