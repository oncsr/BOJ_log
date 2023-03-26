#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T > 0) {
		int a, b;
		cin >> a >> b;
		cout << a + b << '\n';
		T--;
	}
}