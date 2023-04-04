#include <iostream>
#include <stack>
using namespace std;

int main() {
	int n, cur = 1, a, arr[100001]{}, no = 0;
	cin >> n;
	string ans = "";
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a >= cur) {
			for (int j = cur; j <= a; j++) {
				if (!arr[j]) {
					arr[j] = 1;
					ans += "+\n";
				}
			}
		}
		else {
			for (int j = cur - 1; j >= a; j--) {
				if (arr[j] == 1 && j != a) {
					cout << "NO";
					no++;
					break;
				}
			}
		}
		if (no)	break;
		cur = a;
		ans += "-\n";
		arr[a] = 2;
	}
	if (!no)	cout << ans;
}