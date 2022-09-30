#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;	cin >> t;
	while (t--) {
		string a, b;
		cin >> a >> b;
		int cnt[26]{};
		bool chk = false;
		for (char s : b)	cnt[s - 'a']++;
		int sz1 = a.size(), sz2 = b.size();
		int cnt2[26]{};
		for (int i = 0; i < sz1; i++) {
			cnt2[a[i] - 'a']++;
			if (i >= sz2 - 1) {
				bool same = true;
				for (int j = 0; j < 26; j++) {
					if (cnt[j] != cnt2[j]) {
						same = false;
						break;
					}
				}
				if (same) {
					chk = true;
					break;
				}
				cnt2[a[i - sz2 + 1] - 'a']--;
			}
		}
		cout << (chk ? "YES" : "NO") << '\n';
	}
}