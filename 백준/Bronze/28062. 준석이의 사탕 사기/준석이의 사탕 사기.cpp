#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, arr[1000]{}, s = 0;
	cin >> N;
	for (int i = 0; i < N; i++)	cin >> arr[i];
	sort(arr, arr + N, greater<>());
	int temp = 0, cnt = 0;
	for (int i = 0; i < N; i++) {
		if (arr[i] & 1) {
			if (cnt) {
				s += temp + arr[i];
				temp = 0;
				cnt = 0;
			}
			else	temp = arr[i], cnt++;
		}
		else	s += arr[i];
	}
	cout << s;
}