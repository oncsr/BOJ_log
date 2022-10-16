#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, a;
	cin >> N;
	vector<int> arr;
	for (int i = 0; i < N; i++) {
		cin >> a;
		arr.push_back(a);
	}
	vector<int> K;
	for (int i = 0; i < N; i++) {
		int id = lower_bound(K.begin(), K.end(), arr[i]) - K.begin();
		if (id == K.size())	K.push_back(arr[i]);
		else	K[id] = arr[i];
	}
	cout << K.size();
}