#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, L, a[1000];
	cin >> N >> L;
	for (int i = 0; i < N; i++)	cin >> a[i];
	sort(a, a + N);
	int temp = a[0], s = 1;
	for (int i = 0; i < N; i++) {
		if (a[i] >= temp + L) {
			temp = a[i];
			s++;
		}
	}
	cout << s;
}