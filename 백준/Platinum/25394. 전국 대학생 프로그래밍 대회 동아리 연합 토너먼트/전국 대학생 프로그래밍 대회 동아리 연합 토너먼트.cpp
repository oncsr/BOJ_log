#include <iostream>
using namespace std;
using ii = pair<int, int>;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ii arr[1 << 20]{};	  // 경기 결과 배열 : { 이긴 참가자, 진 참가자 }
	int win[(1 << 20) + 1]{};	  // win[i] = i번 참가자가 경기에서 이긴 횟수,
	bool lose[(1 << 20) + 1]{};  // lose[i] = i번 참가자가 경기에서 진 횟수
	// 경기 결과 중 1개만 누락되었다.
	// 모든 사람은 승자를 제외하고 1번씩만 진다.
	// lose 배열을 한 번 돌면 지지 않은 사람 두 명이 나오고,
	// 각각 최종 우승자와, 누락된 패배자가 뜬다.

	int N;
	cin >> N;
	int loser1 = 1, loser2 = (1 << N);
	for (int i = 0; i < (1 << N) - 2; i++) {
		cin >> arr[i].first >> arr[i].second;
		win[arr[i].first]++;
		lose[arr[i].second] = 1;
		while (lose[loser1])	loser1++;
		while (lose[loser2])	loser2--;
	}

	if (win[loser1] == N - 1 && win[loser2] == N - 1) {
		cout << loser1 << ' ' << loser2 << '\n';
		cout << loser2 << ' ' << loser1;
		return 0;
	}
	else if (win[loser1] == N - 1) {
		cout << loser1 << ' ' << loser2;
		return 0;
	}
	else if (win[loser2] == N - 1) {
		cout << loser2 << ' ' << loser1;
		return 0;
	}

	int LOSE = (win[loser1] < win[loser2] ? loser1 : loser2);
	int loser_wins = win[LOSE];

	ii arr2[(1 << 20) + 1]{};

	// 패배자보다 조금 이긴 사람들은 누락되었을 수 없으므로 제외
	long long SUM = (1LL << N) * ((1LL << N) + 1) / 2;
	if (loser_wins)
		for (int i = 1; i <= (1 << N); i++)
			if (win[i] < loser_wins)
				SUM -= (long long)i;

	for (int i = 0; i < (1 << N) - 2; i++) {
		if (win[arr[i].second] == loser_wins) {
			SUM -= (long long)arr[i].first;
			SUM -= (long long)arr[i].second;
			// 누락된 층에서 중복된 우승자가 있는 지 확인
			if (!arr2[arr[i].first].first)
				arr2[arr[i].first] = arr[i];
			else {
				int winner1 = arr2[arr[i].first].second;
				int winner2 = arr[i].second;
				cout << min(winner1, winner2) << ' ' << LOSE << '\n';
				cout << max(winner1, winner2) << ' ' << LOSE;
				return 0;
			}
		}
	}

	cout << SUM - LOSE << ' ' << LOSE;

}