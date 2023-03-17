#include <iostream>
using namespace std;

int N, arr[8]{}, mx = -10000;

// now = 현재 방문하고 있는 칸, val = 현재까지의 값, n = 현재까지 방문한 칸 수
// visit[] = 방문 여부 배열
int visit[8]{};
void recur(int now, int val, int n) {
	if (n == N) {
		mx = max(mx, val);
		return;
	}
	for (int i = 0; i < N; i++) {
		if (visit[i])	continue;
		visit[i] = 1;
		recur(i, val + abs(arr[i] - arr[now]), n + 1);
		visit[i] = 0;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N; i++)	cin >> arr[i];
	for (int i = 0; i < N; i++) {
		visit[i] = 1;
		recur(i, 0, 1);
		visit[i] = 0;
	}
	cout << mx;
}