#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int n;
	cin >> n;
	int cnt[10001]{};
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		cnt[a]++;
	}
	priority_queue<int> Q;
	int counter = 0;
	for (int i = 1; i <= 10000; i++) {
		if (!cnt[i])	continue;
		cnt[i]--;
		for (int j = i+1; j <= 10000; j++) {
			if (!cnt[j])	continue;
			int res1 = i * pow(10, int(log10(j) + 1)) + j;
			int res2 = j * pow(10, int(log10(i) + 1)) + i;
			if (Q.size() < 3) {
				Q.push(res1);
				if (Q.size() < 3)	Q.push(res2);
				else {
					int mn = min(Q.top(), res2);
					Q.pop();
					Q.push(mn);
				}
			}
			else {
				int mn = min({ Q.top(), res1, res2 });
				Q.pop();
				Q.push(mn);
			}
		}
        counter++;
		cnt[i]++;
		if (counter >= 4)	break;
	}
	cout << Q.top();

}