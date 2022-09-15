#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(int a, int b) {
	return a > b;
}

int main() {
	int n;
	cin >> n;
	vector<int> A;
	vector<int> B;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		A.push_back(a);
	}
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		B.push_back(a);
	}
	sort(A.begin(), A.end(), compare);
	sort(B.begin(), B.end());
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += A[i] * B[i];
	}
	cout << sum << '\n';
}