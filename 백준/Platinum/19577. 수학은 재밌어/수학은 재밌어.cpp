#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;


int main() {
	cin.tie(0)->sync_with_stdio(0);

	int e[100001]{};
	for (int i = 2; i * i <= 100000; i++) {
		if (!e[i]) {
			for (int j = i * i; j <= 100000; j += i)
				if (!e[j])	e[j] = i;
		}
	}

	int phi[100001] = { 0,1 };
	int N;
	cin >> N;
	for (int i = 2; i <= 100000; i++) {
		phi[i] = i;
		int T = i;
		if (!e[T]) { phi[i] = i - 1; continue; }
		for (int j = 2; j * j <= T; j++) {
			if (e[j])	continue;
			if (T % j)	continue;
			while (T % j == 0)	T /= j;
			phi[i] /= j;	phi[i] *= (j - 1);
		}
		if (T > 1) { phi[i] /= T; phi[i] *= (T - 1); }
	}

	for (int i = 1; i <= 100000; i++) {
		if ((long long)i * phi[i] != N)	continue;
		cout << i;
		return 0;
	}
	cout << -1;

}