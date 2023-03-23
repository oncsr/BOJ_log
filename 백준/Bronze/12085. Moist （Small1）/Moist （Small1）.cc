#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T;
	cin >> T;
	string EMPTY = "-1";
	for (int i = 1; i <= T; i++) {
		int n;
		cin >> n;
		cin.ignore();
		string arr[10]{};
		int ans = 0;
		for (int j = 0; j < n; j++) {
			getline(cin, arr[j]);
		}

		for (int j = 0; j < n; j++) {
			string prev = arr[0];
			for (int k = 1; k < n; k++) {
				if (arr[k] == EMPTY)	continue;
				if (arr[k] < prev) {
					arr[k] = EMPTY;
					ans++;
				}
				if (arr[k] != EMPTY)	prev = arr[k];
			}
		}

		cout << "Case #" << i << ": " << ans << '\n';
	}
}