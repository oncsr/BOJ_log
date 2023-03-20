#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int Z;
	for (cin >> Z; Z--;) {
		int N, K;
		cin >> N >> K;
		int g = K - 1;
		while (K < N) {
			K += g;
		}
		cout << K - N << '\n';
	}

}