#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int arr[100001]{}, N;

	cin >> N;
	for (int i = 0; i < N; i++)	cin >> arr[i];
	sort(arr, arr + N);
	
	int M;

	for (cin >> M; M--;) {
		int K;
		cin >> K;

		int low = 0, high = N - 1, mid = (low + high) / 2;
		while (low < high) {

			if (arr[mid] < K) {
				// mid보다 왼쪽에 있는 원소들은 고려할 필요 없다.
				low = mid + 1;
			}
			else {
				// mid보다 오른쪽에 있는 원소들은 고려할 필요 없다.
				high = mid;
			}

			// 중간 값을 다시 갱신해준다.
			mid = (low + high) / 2;
		}

		// arr[mid]가 우리가 원하는 값이랑 같은 지만 확인하면 된다.
		if (arr[mid] == K)	cout << 1 << '\n';
		else	cout << 0 << '\n';

	}


}