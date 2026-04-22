#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int e[5000001]{};
	for (int i = 2; i * i <= 5000000; i++)
		if (!e[i])
			for (int j = i * i; j <= 5000000; j += i)
				e[j] = 1;
	deque<char> D;
	int N;
	cin >> N;
	D.push_back('B');
	int bck = 1;
	for (int i = 2; i <= N; i++) {
		if (!e[i]) {
			if (bck) {
				if (D.back() == 'B') {
					D.pop_back();
					D.push_back('S');
				}
				D.push_back('S');
			}
			else {
				if (D.front() == 'B') {
					D.pop_front();
					D.push_front('S');
				}
				D.push_front('S');
			}
			bck ^= 1;
		}
		else {
			if (bck)	D.push_back('B');
			else	D.push_front('B');
		}
	}
	int b = 0, s = 0;
	for (char i : D) {
		if (i == 'B')	b++;
		else	s++;
	}
	cout << b << ' ' << s;
}