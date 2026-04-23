#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, Q, a, b, c;
	bool j = false;
	cin >> N >> Q;
	for (; Q--;) {
		cin >> a >> b >> c;
		if (a == 1)	j ^= 1;
		else {
			if ((c - b) % 4 == 1 || (c - b) % 4 == 2)
				j ^= 1;
		}
		cout << j << '\n';
	}
}