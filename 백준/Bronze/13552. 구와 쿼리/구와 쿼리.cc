#include <iostream>
using namespace std;
using ll = long long;
struct Dot {
	ll x, y, z;
};
int main() {
	cin.tie(0)->sync_with_stdio(0);
	Dot arr[100000]{};
	int N, M;
	ll a, b, c, d;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a >> b >> c;
		arr[i] = { a,b,c };
	}
	for (cin >> M; M--;) {
		cin >> a >> b >> c >> d;
		int s = 0;
		for (int i = 0; i < N; i++) {
			Dot O = arr[i];
			if ((O.x - a) * (O.x - a) + (O.y - b) * (O.y - b) + (O.z - c) * (O.z - c) <= d * d)
				s++;
		}
		cout << s << '\n';
	}
}