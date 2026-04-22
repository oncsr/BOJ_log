#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T;
	for (cin >> T; T--;) {
		string a;
		cin >> a;
		int arr[10]{}, s = 0;
		for (char i : a) {
			if (!arr[i - '0'])	s++, arr[i - '0']++;
		}
		cout << s << '\n';
	}
}