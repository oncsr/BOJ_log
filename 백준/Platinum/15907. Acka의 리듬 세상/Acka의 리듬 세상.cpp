#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	map<pair<int, int>, pair<int, int> > M;
	int e[2000001]{};
	for (int i = 2; i * i <= 2000000; i++) {
		if (!e[i])
			for (int j = i * i; j <= 2000000; j += i)
				e[j] = 1;
	}
	int arr[1000]{}, N;
	cin >> N;


	for (int i = 0; i < N; i++)	cin >> arr[i];
	int mx = 1;

	if (N == 1) {
		cout << 1;
		return 0;
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (arr[j] - arr[i] < 2)	continue;

			int K = arr[j] - arr[i], g = 2;
			vector<int> soinsu;

			while (K > 1) {
				if (!e[K])	break;
				if (g > K)	break;
				if (e[g]) {
					g++;
					continue;
				}
				if (K % g != 0) {
					g++;
					continue;
				}
				while (K % g == 0)	K /= g;
				soinsu.push_back(g);
				g++;
			}
			if (K > 1)	soinsu.push_back(K);

			for (int sosu : soinsu) {
				pair<int, int> now = { sosu, arr[i] % sosu };
				if (M[now].first == 0) {
					M[now] = { 2,i };
					
				}
				else {
					if (M[now].second != i)	continue;
					M[now].first++;
				}

				mx = max(mx, M[now].first);
			}

		}
	}

	cout << mx;
}