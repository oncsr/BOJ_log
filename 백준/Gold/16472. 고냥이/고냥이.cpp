#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	string A;
	cin >> N >> A;

	int s = 0, e = 0, ex[26]{}, ans = 1, cnt = 1;
	ex[A[0] - 'a']++;
	while (e < A.size()) {
		if (cnt > N) {
			ex[A[s] - 'a']--;
			if (ex[A[s] - 'a'] == 0)	cnt--;
			s++;
		}
		else {
			e++;
			if (e == A.size())	break;
			if (!ex[A[e] - 'a']++)	cnt++;
		}
		if (cnt <= N)	ans = max(ans, e - s + 1);
	}
	cout << ans;

}