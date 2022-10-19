#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, M, a;
	bool arr[20000001]{};
	for (cin >> N; N--;) {
		cin >> a;
		arr[a + 10000000] |= true;
	}
	for (cin >> M; M--;) {
		cin >> a;
		cout << (arr[a + 10000000] ? 1 : 0) << ' ';
	}
}