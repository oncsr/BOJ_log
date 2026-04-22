#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ii = pair<int, int>;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	for (cin >> t; t--;) {
		int N, D;
		int arr[1000002]{};
		cin >> N >> D;
		arr[0] = arr[N + 1] = -1;
		vector<ii> V;
		int temp2 = -1, temp = -1;
		for (int i = 1; i <= N; i++) {
			cin >> arr[i];
			if (i == 1) {
				temp = arr[1];
				continue;
			}
			if (arr[i] == temp)	continue;
			if (temp > temp2 && temp > arr[i])
				V.push_back({ temp,-1 });
			else if (temp < temp2 && temp < arr[i])
				V.push_back({ temp,1 });
			temp2 = temp, temp = arr[i];
		}
		if (temp > temp2)	V.push_back({ temp, -1 });
		sort(V.begin(), V.end());
		int s = 1, pos = 0;
		for (int i = 0; i < D; i++) {
			int a;
			cin >> a;
			if (pos == V.size()) {
				cout << 0 << ' ';
				continue;
			}
			while (V[pos].first <= a) {
				s += V[pos++].second;
				if (pos == V.size())	break;
			}
			cout << s << ' ';
		}
		cout << '\n';
	}
}