#include <iostream>
using namespace std;

int main() {
	int N, M, s = 0, p;
	char a[100], c;
	cin >> N;
	p = N - 1;
	for (int i = 0; i < N; i++)	cin >> a[i];
	cin >> M;
	while (M--) {
		cin >> c;
		int g = 1;
		p = (p + 1) % N;
		while (a[p] != c && g <= N) {
			g++;
			p = (p + 1) % N;
		}
		if (g > N) {
			s = -1;
			break;
		}
		s += g;
	}
	cout << s;
}