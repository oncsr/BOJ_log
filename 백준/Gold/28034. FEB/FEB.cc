#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N;
	string a;
	cin >> N >> a;
	int ans = 0, cnt = 0, mn = 0, mx = 0;
	char temp = ' ', left = ' ', right = ' ';
	for (int i = 0; i < a.size() - 1; i++) {
		if (a[i] == a[i + 1] && a[i] != 'F')	ans++;
	}

	int one = 0;
	pair<int, int> two;
	
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == 'F') {
			if (temp != 'F')	left = temp;
			cnt++;
		}
		else {
			if (temp == 'F') {
				right = a[i];
				if (left == right) {
					if (cnt % 2 == 0)	two.first++;
					two.second += cnt + 1;
				}
				else {
					if (left == ' ')	one += cnt;
					else {
						two.second += cnt;
						// F가 홀수 개면서 양 옆이 다르면 무조건 하나 있어야 함
						if (cnt % 2)	two.first++;
					}
				}
				cnt = 0;
			}
		}
		temp = a[i];
	}

	if (temp == 'F') {
		if (left == ' ')	one += cnt - 1;
		else	one += cnt;
	}

	if (!one) {
		cout << (two.second - two.first + 2) / 2 << '\n';
		for (int i = ans + two.first; i <= ans + two.second; i += 2)	cout << i << '\n';
	}
	else {
		cout << two.second - two.first + 2 + one - 1 << '\n';
		for (int i = ans + two.first; i <= ans + two.second + one; i++)	cout << i << '\n';
	}
	
}