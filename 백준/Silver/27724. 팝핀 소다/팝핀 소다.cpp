#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;
using ii = pair<int, int>;

int main() {

	cin.tie(0)->sync_with_stdio(0);

	//////////////////////////////////////////////////////

	int N, M, K, mx = 0;
	cin >> N >> M >> K;

	int G = N;
	while (G > 1) {
		G /= 2;
		mx++;
	}

	G = 2;
	int ans = 0;
	while (G <= K) {
		G *= 2;
		ans++;
	}
	
	cout << min(mx, ans + M);
}

/*
* [shake! 2022]
*
* < 사용한 자료구조, 알고리즘 >
* math
*
* < 참고한 자료 >
* x
*
* < 출처 >
* x
*
*/