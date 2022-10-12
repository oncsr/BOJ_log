#include <iostream>
using namespace std;

int main() {
	int N, ans = 1;
	cin >> N;
	for (int i = 1; i < N / 3; i++)	ans = (ans * 3) % 10007;
	if (N % 3 == 1)	ans = (ans * 4) % 10007;
	else if (N % 3 == 2)	ans = (ans * 6) % 10007;
	else	ans = (ans * 3) % 10007;
	if (N < 3)	cout << N;
	else cout << ans;
}