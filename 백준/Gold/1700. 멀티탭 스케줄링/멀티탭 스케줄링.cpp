#include <iostream>
using namespace std;

int use[101]{}, order[101]{}, last[101]{};
int N, K, cnt, ans = 0;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> K;
	cnt = N;
	for (int i = 1; i <= K; i++) {
		cin >> order[i];
		last[order[i]] = i;
	}
	for (int i = 1; i <= K; i++) {
		int now = order[i];
		if (use[now])	continue;
		if (cnt) {
			cnt--;
			use[now] = 1;
			continue;
		}
		int esc = 0;
		for (int j = 1; j <= K; j++) {
			if (!use[j])	continue;
			if (last[j] < i) {
				use[j] = 0;
				ans++;
				use[now] = 1;
				esc++;
				break;
			}
		}
		if (esc)	continue;
		int thing = 0;
		int idx[101]{};
		for (int j = i + 1; j <= K; j++) {
			int next = order[j];
			if (!use[next])	continue;
			if (idx[next])	continue;
			idx[next] = j;
			thing = next;
		}
		use[thing] = 0;
		ans++;
		use[now] = 1;
	}
	cout << ans;
}