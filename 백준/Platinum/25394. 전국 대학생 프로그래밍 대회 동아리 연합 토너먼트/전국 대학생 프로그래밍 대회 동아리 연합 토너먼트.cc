#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
using ii = pair<int, int>;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ii arr[1 << 20]{};	  // 경기 결과 배열 : { 이긴 참가자, 진 참가자 }
	int win[(1 << 20) + 1]{};	  // win[i] = i번 참가자가 경기에서 이긴 횟수,
	int lose[(1 << 20) + 1]{};  // lose[i] = i번 참가자가 경기에서 진 횟수
	// 경기 결과 중 1개만 누락되었다.
	// 모든 사람은 승자를 제외하고 1번씩만 진다.
	// lose 배열을 한 번 돌면 지지 않은 사람 두 명이 나오고,
	// 각각 최종 우승자와, 누락된 사람이 뜰 것이다.
	int total[(1 << 20) + 1]{}; // total[i] = i번 참가자가 경기를 한 횟수
	// 1 <= i < N이면, total[i] = 2^(N-i)
	// i == N이면,     total[i] = 2
	// 모든 참가자는 우승자를 제외하고, win[i] + 1 == total[i] 이다.
	int win_check[21]{};  // win_check[i] = i번 우승한 사람의 수
	// 0 <= i < N이면, win_check[i] = 2^(N-(i+1))
	// i == N이면,     win_check[i] = 1
	// 따라서, win_check 배열을 한 번 돌면서 식을 만족하지 않는 값이 존재하면,
	// 그 부분에서 누락이 일어났음을 알 수 있다.
	// 정확히는, 하나가 누락이 되었으므로 반드시
	// 어떠한 win_check[i] = 2^(N-(i+1)) + 1 인 값이 존재한다.
	// 누락이 i에서 일어났다면, i번 이긴 사람들 중 한 명이 이긴 경기가 누락되었다.

	int N;
	cin >> N;
	for (int i = 0; i < (1 << N) - 2; i++) {
		cin >> arr[i].first >> arr[i].second;
		win[arr[i].first]++;
		lose[arr[i].second]++;
		total[arr[i].first]++;
		total[arr[i].second]++;
	}
	int LOSE = -1, LOSE_POSSIBLE = -1, WIN = -1, WIN_POSSIBLE = -1;
	int multiwin = 0;
	int loser_wins = 0;
	for (int i = 1; i <= (1 << N); i++) {
		if (!lose[i]) {
			// (N, 0)이 있는 경우 우승자 존재
			if (win[i] == N)	WIN = -2;
			else if (win[i] == N - 1) {
				// v (N-1, 0)이 처음 나온 경우 우승후보로 지정
				if (WIN_POSSIBLE == -1)	WIN_POSSIBLE = i;
				else	WIN = WIN_POSSIBLE, LOSE = i, multiwin++;
				// ^ 두 번 나온 경우 둘을 WIN, LOSE로 지정 후 두 개 출력
			}
			else	LOSE = i, loser_wins = win[i];
			// ^ (N-1, 0)이 하나면 WIN_POSSIBLE과 LOSE만 정해지고
			// 둘의 경기가 누락된 것임
		}
	}

	if (multiwin) {	// 결승 누락인 경우
		int mx = max(WIN, LOSE), mn = min(WIN, LOSE);
		cout << mn << ' ' << mx << '\n' << mx << ' ' << mn;
	}
	else {
		if (WIN == -2) {	// 우승자 누락 X
			if (loser_wins == 0) {	// 말단 누락은 오직 한 가지 경우
				ii arr2[(1 << 20) + 1]{};
				int visit[(1 << 20) + 1]{};
				int ERROR_A = -1, ERROR_B = -1;
				for (int i = 0; i < (1 << N) - 2; i++) {
					if (win[arr[i].second] == 0) {
						visit[arr[i].first]++;
						visit[arr[i].second]++;
						if (!arr2[arr[i].first].first)
							arr2[arr[i].first] = arr[i];
						else {
							ERROR_A = arr2[arr[i].first].second;
							ERROR_B = arr[i].second;
							break;
						}
					}
				}
				if (ERROR_A == -1) {
					for (int i = 1; i <= (1 << N); i++) {
						if (visit[i])	continue;
						if (i == LOSE)	continue;
						cout << i << ' ' << LOSE;
						break;
					}
				}
				else {
					// here
					int mn = min(ERROR_A, ERROR_B);
					int mx = max(ERROR_A, ERROR_B);
					cout << mn << ' ' << LOSE << '\n' << mx << ' ' << LOSE;
				}
			}
			else if (loser_wins == N - 2) {	// 4강전에서 누락된 경우
				// 여기도 답이 2개다.
				int WIN_1 = -1, WIN_2 = -1;
				for (int i = 1; i <= (1 << N); i++) {
					if (win[i] >= loser_wins) {
						if (i == LOSE)	continue;
						if (win[i] > loser_wins)	continue;
						if (WIN_1 == -1)	WIN_1 = i;
						else	WIN_2 = i;
					}
				}
				cout << WIN_1 << ' ' << LOSE << '\n' << WIN_2 << ' ' << LOSE;
			}
			else {
				// 아닌 경우, 답 1개
				// 밑에 있는 애들 다 제외시키고 vis가 0인 애들만 고려하기
				int vis[(1 << 20) + 1]{};
				ii arr2[(1 << 20) + 1]{};
				for (int i = 0; i < loser_wins; i++) {
					for (int j = 1; j <= (1 << N); j++) {
						if (win[j] == i)	vis[j]++;
					}
				}
				int ERROR_A = -1, ERROR_B = -1;
				for (int i = 0; i < (1 << N) - 2; i++) {
					if (vis[arr[i].second])	continue;
					if (win[arr[i].second] == loser_wins) {
						vis[arr[i].first]++;
						vis[arr[i].second]++;
						if (!arr2[arr[i].first].first)
							arr2[arr[i].first] = arr[i];
						else {
							ERROR_A = arr2[arr[i].first].second;
							ERROR_B = arr[i].second;
							break;
						}
					}
				}
				if (ERROR_A == -1) {
					for (int i = 1; i <= (1 << N); i++) {
						if (vis[i])	continue;
						if (i == LOSE)	continue;
						cout << i << ' ' << LOSE;
						break;
					}
				}
				else {
					int mn = min(ERROR_A, ERROR_B);
					int mx = max(ERROR_A, ERROR_B);
					cout << mn << ' ' << LOSE << '\n' << mx << ' ' << LOSE;
				}

			}
		}
		else {
			cout << WIN_POSSIBLE << ' ' << LOSE;
		}
	}


}