#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, s = 0, b;
	cin >> n;
	int arrow[1000001]{};
	for (int i = 0; i < n; i++) {
		cin >> b;
		if (!arrow[b]) {
			s++;
			arrow[b - 1]++;
		}
		else {
			arrow[b]--;
			arrow[b - 1]++;
		}
	}
	cout << s;
}