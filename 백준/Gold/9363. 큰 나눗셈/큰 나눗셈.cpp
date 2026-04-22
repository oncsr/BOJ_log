#include <iostream>
#include <vector>
using namespace std;

/*
 < 2022.03.07 >
 [my rating]
 > G4
 [used algorithm]
 > sieve of Eratosthenes
 [point]
 체의 인덱스 i에 해당하는 값을 해당 소인수를 나눌 수 있는 가장 작은 소수로
 정의하여 소인수분해에 이용
*/

int mypower(int a, int b) {
	if (b == 0)	return 1;
	if (b == 1)	return a;
	int part = mypower(a, b / 2);
	if (b % 2)	return part * part * a;
	else	return part * part;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T;
	cin >> T;
	int e[1000001]{};
	for (int i = 2; i * i <= 1000000; i++) {
		if (!e[i])
			for (int j = i * i; j <= 1000000; j += i)
				if (!e[j])	e[j] = i;
	}

	for (int j = 1; j <= T; j++) {
		int N, M;
		int arr[1000001]{}, a;
		cin >> N >> M;
		for (; N--;) {
			cin >> a;
			while (e[a]) {
				arr[e[a]]++;
				a /= e[a];
			}
			if (a > 1)	arr[a]++;
		}
		for (; M--;) {
			cin >> a;
			while (e[a]) {
				arr[e[a]]--;
				a /= e[a];
			}
			if (a > 1)	arr[a]--;
		}
		int aa = 1, b = 1;
		for (int i = 2; i <= 1000000; i++) {
			if (!arr[i])	continue;
			if (arr[i] > 0)	aa *= mypower(i, arr[i]);
			else	b *= mypower(i, arr[i]);
		}
		cout << "Case #" << j << ": " << aa << " / " << b << '\n';
	}
}