#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, M, arr[100000]{}, s = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++)	cin >> arr[i];
	sort(arr, arr + N);
	int st = 0, ed = N - 1;
	while (st < ed) {
		if (arr[st] + arr[ed] >= M) {
			s++;
			st++, ed--;
		}
		else	st++;
	}
	cout << s;
}