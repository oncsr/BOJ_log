#include <bits/stdc++.h>
using namespace std;

vector<int> A, B;
vector<int> arr;
int N, K;

void push(int now, int limit, int sum, bool a) {
	if (now > limit) {
		if (a)	A.push_back(sum);
		else	B.push_back(sum);
		return;
	}
	push(now + 1, limit, sum + arr[now], a);
	push(now + 1, limit, sum, a);
}

vector<int> P1, P2;

void find(int now, int limit, int sum, int tar, vector<int> way, bool a) {
	if (now > limit) {
		if (sum != tar)	return;
		if (a)	P1 = way;
		else	P2 = way;
		return;
	}
	way.push_back(0);
	find(now + 1, limit, sum, tar, way, a);
	way.pop_back();
	way.push_back(1);
	find(now + 1, limit, sum + arr[now], tar, way, a);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		arr.push_back(a);
	}
	cin >> K;
	push(0, N / 2, 0, 1);
	push(N / 2 + 1, N - 1, 0, 0);
	sort(B.begin(), B.end());

	for (int i : A) {
		int pos = lower_bound(B.begin(), B.end(), K - i) - B.begin();
		if (pos == B.size())	continue;
		if (B[pos] != K - i)	continue;
		find(0, N / 2, 0, i, {}, 1);
		find(N / 2 + 1, N - 1, 0, B[pos], {}, 0);
		break;
	}
	for (int i : P1)	cout << i;
	for (int i : P2)	cout << i;

}