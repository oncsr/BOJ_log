#include <iostream>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T;
	for (cin >> T; T--;) {
		int arr[1000000]{}, N, mx = -1000, id = 0;
		cin >> N;
		for (int i = 0; i < N; i++) {
			int a, b;
			cin >> a >> b;
			arr[i] = a - b;
			if (arr[i] > mx)	mx = arr[i], id = i;
		}
		int s = 0, poss = 1;
		for (int i = 0; i < N; i++) {
			s += arr[(id + i) % N];
		}
		if (s < 0)	cout << "IMPOSSIBLE\n";
		else	cout << id + 1 << '\n';
	}
}