#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

// pair<int, int>를 매번 치기 귀찮으니	줄여서 쓰자.
using ii = pair<int, int>;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ii coord[1000000]{};	// { 좌표, 인덱스 }

	int ans[1000000]{};		// 정답을 저장할 배열

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		coord[i] = make_pair(a, i);
	}

	sort(coord, coord + N);

	int pos = coord[0].second;
	ans[pos] = 0;
	int id = 0, temp = coord[0].first;

	for (int i = 1; i < N; i++) {
		int value = coord[i].first;
		pos = coord[i].second;
		if (value == temp)	ans[pos] = id;
		else {
			ans[pos] = ++id;
			temp = value;
		}
	}

	for (int i = 0; i < N; i++) {
		cout << ans[i] << ' ';
	}

}