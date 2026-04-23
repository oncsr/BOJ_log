#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, a, s = 1;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> a;
		if (a % 2 != i % 2)	s = 0;
	}
	cout << (s ? "YES" : "NO");
}