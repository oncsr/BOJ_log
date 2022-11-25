#include <iostream>
using namespace std;

int main() {
	int N, M, a, t, te, n = 1;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a;
		te = 0;
		for (int j = 0; j < a; j++) {
			cin >> t;
			if (!te)	te = t;
			else {
				if (t > te)	n = 0;
				te = t;
			}
		}
	}
	cout << (n ? "Yes" : "No");
}