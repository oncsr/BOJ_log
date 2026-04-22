#include <iostream>
using namespace std;
using ii = pair<int, int>;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T;
	for (cin >> T; T--;) {
		int h, l, mx = 0;
		cin >> h >> l;
		ii arr[2500]{};
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < l; j++) {
				int a;
				cin >> a;
				if (a != -1)	arr[a] = { i,j };
				mx = max(mx, a);
			}
		}
		int s = 0;
		int rot[50]{};	// 돌려진 횟수
		for (int i = 1; i <= mx; i++) {
			ii des = arr[i];
			int y = (des.second + rot[des.first]) % l;
			s += 5 * min(y, l - y);
			s += 20 * des.first;
			rot[des.first] = (rot[des.first] + l - y) % l;

		}
		cout << s << '\n';
	}
}