#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T, B, X, Y;
	for (cin >> T; T--;) {
		cin >> B >> X >> Y;
		int ans = 0;
		if (X > Y)	swap(X, Y);
		int i = 1;
		while (X > 0) {
			ans += i * (((X % B) + (Y % B)) % B);
			X /= B, Y /= B;
			i *= B;
		}
		while (Y > 0) {
			ans += i * (Y % B);
			Y /= B;
			i *= B;
		}
		cout << ans << '\n';
	}
}