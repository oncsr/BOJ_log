#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, a[3];
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> a[0] >> a[1] >> a[2];
		cout << "Scenario #" << i << ":\n";
		sort(a, a + 3);
		cout << (a[0] * a[0] + a[1] * a[1] == a[2] * a[2] ? "yes" : "no") << "\n\n";
	}
}