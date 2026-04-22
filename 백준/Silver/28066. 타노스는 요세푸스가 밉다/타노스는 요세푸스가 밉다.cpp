#include <iostream>
#include <deque>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	deque<int> D;
	for (int i = 1; i <= n; i += k)	D.push_back(i);
	int g = n - (1 + (n-1) / k * k);	// 처음에 지워지는 뒤의 개수
	int fr = k - 1 - g;	// 다음에 지워지는 앞의 개수
	if (D.size() - 1 < fr) {
		cout << D.back();
		return 0;
	}

	while (fr-- > 0)	D.pop_front();
	while (D.size() > 1) {
		deque<int> DD;
		int nn = D.size();
		for (int i = 0; i < nn; i += k)	DD.push_back(D[i]);
		g = nn - (1 + (nn-1) / k * k);
		fr = k - 1 - g;
		if (DD.size() - 1 < fr) {
			cout << DD.back();
			return 0;
		}
		while (fr-- > 0)	DD.pop_front();
		D = DD;
	}
	cout << D[0];
}