#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ii = pair<int, int>;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, s = 1;
	ii domino[500000]{};
	cin >> N;
	for (int i = 0; i < N; i++)	cin >> domino[i].first >> domino[i].second;
	sort(domino, domino + N);
	for (int i = N - 1; i > 0; i--) {
		if (domino[i - 1].first + domino[i - 1].second < domino[i].first)
			s++;
	}
	cout << s;
}