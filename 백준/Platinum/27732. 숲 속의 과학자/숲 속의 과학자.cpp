#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;

ll ans[200001]{};
ll N, M, H;
// H : 트리 최대 높이

// 트리가 만들어지는 과정 (idx 기준)
// 현재 정점 방문 -> 왼쪽 서브트리 방문 -> 오른쪽 서브트리 방문
// -> 프리오더 순서

// now : 현재 번호
// pos : now가 x_pos임을 의미
// left : 현재 기준 왼쪽 서브트리의 원소 개수
// right : 현재 기준 오른쪽 서브트리의 원소 개수
// chk : 찾으려는 값 (x_chk)
void dfs(ll now, ll pos, ll left, ll right, ll dep, ll chk) {
	if (chk == pos) {
		cout << now << ' ';
		return;
	}
	if (H - dep < 2) {
		if (pos + 2 == chk)	cout << now + 1 << ' ';
		else if (!left)	cout << now + 1 << ' ';
		else	cout << now - 1 << ' ';
		return;
	}
	if (chk <= pos + left) {	// 왼쪽으로 내려가야 하는 경우
		left--;
		ll temp = (1LL << (H - dep - 1)) - 1;
		ll next_right = min(left, temp);
		left -= next_right;
		ll next_left = left;
		ll next_root = now - next_right - 1;
		dfs(next_root, pos + 1, next_left, next_right, dep + 1, chk);
	}
	else {	// 오른쪽으로 내려가야 하는 경우
		ll next_pos = pos + left + 1;
		right--;
		ll temp = (1LL << (H - dep - 1)) - 1;
		ll next_right = min(right, temp);
		right -= next_right;
		ll next_left = right;
		ll next_root = now + next_left + 1;
		dfs(next_root, next_pos, next_left, next_right, dep + 1, chk);
	}


}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M;
	ll G = 1;
	while (G < N)	G <<= 1;
	G >>= 1;
	G = N % G + 1;
	H = log2(N);
	// G는 루트(x1)의 번호
	for (int i = 1; i <= M; i++) {
		ll a;
		cin >> a;
		dfs(G, 1, G - 1, N - G, 0, a);
	}
}