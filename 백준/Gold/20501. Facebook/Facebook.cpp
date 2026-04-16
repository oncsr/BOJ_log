#include <iostream>
#include <bitset>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	bitset<2000> A[2000]{};
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];

	int Q;
	for (cin >> Q; Q--;) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		cout << (A[a] & A[b]).count() << '\n';
	}

}