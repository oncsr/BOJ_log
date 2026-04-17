#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	int arr[1001]{};
	cin >> N;
	for (int i = 1; i <= N; i++)	cin >> arr[i];

	int dp[1001]{};
	fill(dp + 1, dp + N + 1, 1);	// dp[1] ~ dp[N]을 1로 채운다.

	for (int i = 2; i <= N; i++) {
		for (int j = 1; j < i; j++) {
			if (arr[i] > arr[j])	dp[i] = max(dp[i], dp[j] + 1);
		}
	}

	// max_element : 주어진 범위에서 최댓값에 해당하는 원소의 포인터 반환
	cout << *max_element(dp + 1, dp + N + 1);

}