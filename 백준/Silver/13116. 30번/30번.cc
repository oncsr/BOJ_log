#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T, A, B;
	for (cin >> T; T--;) {
		cin >> A >> B;
		while (A != B) {
			if (A > B)	swap(A, B);
			if (B % 2)	B = (B - 1) / 2;
			else	B /= 2;
		}
		cout << A * 10 << '\n';
	}
}