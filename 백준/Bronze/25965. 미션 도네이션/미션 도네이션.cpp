#include <iostream>
using namespace std;
#define int long long
struct node {
	int k, d, a;
};
main() {
	int N;
	for (cin >> N; N--;) {
		node arr[100]{};
		int M, K, D, A, s = 0;
		cin >> M;
		for (int i = 0; i < M; i++)
			cin >> arr[i].k >> arr[i].d >> arr[i].a;
		cin >> K >> D >> A;
		for (int i = 0; i < M; i++) {
			int temp = arr[i].k * K + arr[i].a * A - arr[i].d * D;
			if (temp > 0)	s += temp;
		}
		cout << s << '\n';
	}
}