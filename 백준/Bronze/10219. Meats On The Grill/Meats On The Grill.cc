#include <iostream>
using namespace std;

int main() {
	int T, M, N;
	for (cin >> T; T--;) {
		string a[11]{};
		cin >> N >> M;
		for (int i = 0; i < N; i++)	cin >> a[i];
		for (int i = N - 1; i >= 0; i--)	cout << a[i] << '\n';
	}
}