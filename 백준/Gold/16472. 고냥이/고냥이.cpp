#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string a;
	int arr[26]{}, N, ans = 0, s = 0, e = 0, cnt = 0;
	cin >> N >> a;
	while (e < a.size()) {
		if (!arr[a[e] - 'a'])	cnt++;
		arr[a[e] - 'a']++;
		if (cnt > N) {
			while (arr[a[s] - 'a']--) {
				if (arr[a[s] - 'a'] == 0) {
					cnt--;
					s++;
					break;
				}
				s++;
			}
		}
		ans = max(ans, e - s + 1);
		e++;
	}
	cout << ans;
}