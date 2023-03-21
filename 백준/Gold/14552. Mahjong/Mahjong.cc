#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ans[10]{};

void solve(int head, int body, vector<int> G, int ord) {
	if (head == 7 || (head == 1 && body == 4)) {
		ans[ord] |= 1;
		return;
	}

	for (int i = 1; i <= 9; i++) {
		if (!G[i])	continue;
		if (G[i] == 4) {
			// 같은 거 몸통 1개 + 연속 몸통 1개
			if (i <= 7 && (G[i + 1] >= 1 && G[i + 2] >= 1)) {
				G[i] = 0, G[i + 1]--, G[i + 2]--;
				solve(head, body + 2, G, ord);
				G[i] = 4, G[i + 1]++, G[i + 2]++;
			}

			// or 연속 몸통 4개

			if (i <= 7 && G[i + 1] >= G[i] && G[i + 2] >= G[i]) {
				G[i] = G[i + 1] = G[i + 2] = 0;
				solve(head, body + 4, G, ord);
				G[i] = G[i + 1] = G[i + 2] = 4;
			}

		}

		else if (G[i] == 3) {
			// 몸통 1개
			G[i] -= 3;
			solve(head, body + 1, G, ord);
			G[i] += 3;
			// or 머리 1개 몸통 1개
			// 3개 있는데 머리 + 몸통으로 나뉘는 것이 방법일 경우
			// 현재 머리가 없는 경우밖에 없음
			if (!head && (i <= 7 && (G[i+1] >= 1 && G[i+2] >= 1))) {
				G[i] = 0, G[i + 1]--, G[i + 2]--;
				solve(head + 1, body + 1, G, ord);
				G[i] = 3, G[i + 1]++, G[i + 2]++;
			}
			// or 몸통 3개
			if (i <= 7 && (G[i + 1] >= G[i] && G[i + 2] >= G[i])) {
				G[i] = 0, G[i + 1] -= 3, G[i + 2] -= 3;
				solve(head, body + 3, G, ord);
				G[i] = 3, G[i + 1] += 3, G[i + 2] += 3;
			}
		}
		else if (G[i] == 2) {
			// 머리 1개
			G[i] -= 2;
			solve(head + 1, body, G, ord);
			G[i] += 2;
			// or 몸통 최대 2개
			if (i <= 7 && (G[i + 1] >= G[i] && G[i + 2] >= G[i])) {
				G[i] = 0, G[i + 1] -= 2, G[i + 2] -= 2;
				solve(head, body + 2, G, ord);
				G[i] = 2, G[i + 1] += 2, G[i + 2] += 2;
			}
		}
		else {
			if (i <= 7 && (G[i + 1] && G[i + 2])) {
				G[i]--, G[i + 1]--, G[i + 2]--;
				solve(head, body + 1, G, ord);
				G[i]++, G[i + 1]++, G[i + 2]++;
			}
		}
	}
	
}

int main() {
	int a;
	vector<int> arr(10);
	for (int i = 0; i < 13; i++) {
		cin >> a;
		arr[a]++;
	}
	// 머리 7개를 모으려면
	// 똑같은 패가 3장 이상 있으면 안된다.
	// -> 똑같은 패가 3장 이상 나오면
	// 무조건 몸통으로 가면 된다. (greedy)
	
	for (int i = 1; i <= 9; i++) {
		vector<int> G = arr;
		G[i]++;
		solve(0, 0, G, i);
	}
	bool find = false;
	for (int i = 1; i <= 9; i++) {
		if (ans[i])	cout << i << ' ', find = true;
	}
	if (!find)	cout << -1;

}