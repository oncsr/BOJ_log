#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int s = 0;
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int temp = 0, a = 0, b = 0;
		for (int j = 0; j < M; j++) {
			int c;
			cin >> c;
			if (!c) {
				if (a == 0 && b == 0)	continue;
				if (a && b)	s += min(a, b) + 1;
				else if (a)	s += a;
				else if (b)	s += b;
				a = 0, b = 0, temp = 0;
				continue;
			}
			if (c != temp) {
				if (c == 1)	a++;
				else	b++;
				temp = c;
			}
		}
		if (a && b)	s += min(a, b) + 1;
		else if (a)	s += a;
		else if (b)	s += b;
	}
	cout << s;
}