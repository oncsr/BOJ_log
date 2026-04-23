#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	int arr[200000][3]{};
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[j][i];
	int last = -1;
	bool yes = true;
	for (int i = 0; i < n; i++) {
		int a[3] = { arr[i][0], arr[i][1], arr[i][2] };
		sort(a, a + 3);
		if (a[1] > last) {
			last = max(last + 1, a[0]);
		}
		else {
			if (a[2] > last) {
				last++;
			}
			else {
				yes = false;
				break;
			}
		}
	}
	cout << (yes ? "YES" : "NO");
}