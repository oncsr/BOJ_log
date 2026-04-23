#include <iostream>
using namespace std;
using ll = long long;

/* S3
* 2022.11.27
* [used algorithm]
* => combinatoric
* [point]
* => 조합의 곱
*/

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll al[26]{}, al2[26]{};
	char a;
	cin >> a;
	al[a - 'A']++;
	cin >> a;
	al[a - 'A']++;
	cin >> a;
	al[a - 'A']++;
	int N;
	ll s = 1;
	string b;
	for (cin >> N; N--;) {
		cin >> b;
		al2[b[0] - 'A']++;
	}
	for (int i = 0; i < 26; i++) {
		if (!al[i])	continue;
		int m = al[i];
		if (m == 1)	s *= al2[i];
		else if (m == 2) {
			s *= (al2[i] * (al2[i] - 1) / 2);
		}
		else {
			s *= (al2[i] * (al2[i] - 1) * (al2[i] - 2) / 6);
		}
	}
	cout << s;
}