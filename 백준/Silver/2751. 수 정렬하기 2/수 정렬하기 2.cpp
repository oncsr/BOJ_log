#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);

	int N;
	cin >> N;
	vector<int> Vec;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		Vec.push_back(a);
	}

	sort(Vec.begin(), Vec.end());

	for (int i = 0; i < N; i++) {
		cout << Vec[i] << '\n';
	}
}