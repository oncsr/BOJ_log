#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T, R, C, W, i = 1;
	for (cin >> T; T--;) {
		cin >> R >> C >> W;
		cout << "Case #" << i++ << ": " << max(C / W, 1) * R + W - 1 + (int)(C % W != 0) << '\n';
	}
}