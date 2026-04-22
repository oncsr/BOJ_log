#include <iostream>
#include <bitset>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	bitset<1048577> dead;
	int N, Q;
	cin >> N >> Q;
	for (; Q--;) {
		int x;
		cin >> x;
		int temp = x;
		int gr = 0;
		while (x) {
			if (dead[x])	gr = x;
			x >>= 1;
		}
		cout << gr << '\n';
		dead[temp] = 1;
	}
}