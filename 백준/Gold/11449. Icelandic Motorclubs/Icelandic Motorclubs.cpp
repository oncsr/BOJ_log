#include <iostream>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T;
	for (cin >> T; T--;) {
		int N, s = 0, id = 1;
		cin >> N;
		for (int i = 0; i < N; i++) {
		    if(s < 0)   id = i+1;
			int a, b;
			cin >> a >> b;
			s += a - b;
		}
		if (s < 0)	cout << "IMPOSSIBLE\n";
		else	cout << id << '\n';
	}
}