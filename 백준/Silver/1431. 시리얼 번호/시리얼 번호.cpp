#include <iostream>
#include <algorithm>
using namespace std;

bool compare(string a, string b) {
	if (a.size() == b.size()) {
		int aa = 0, bb = 0;
		for (char i : a) {
			if (i >= 48 && i <= 57)	aa += (i - '0');
		}
		for (char i : b) {
			if (i >= 48 && i <= 57)	bb += (i - '0');
		}
		if (aa == bb)	return a < b;
		return aa < bb;
	}
	return a.size() < b.size();
}

int main() {
	int N;
	cin >> N;
	string arr[50]{};
	for (int i = 0; i < N; i++)	cin >> arr[i];
	sort(arr, arr + N, compare);
	for (int i = 0; i < N; i++)	cout << arr[i] << '\n';
}