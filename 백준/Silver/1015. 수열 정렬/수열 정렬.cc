#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a[50]{}, b[50]{}, c, n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> c;
		a[i] = b[i] = c;
	}
	sort(a, a + n);
	int visit[50]{};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (b[i] == a[j] && !visit[j]) {
				visit[j]++;
				cout << j << ' ';
				break;
			}
		}
	}
}