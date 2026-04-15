#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, arr[1001]{};
	cin >> N;
	vector<int> V;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		if (!arr[a])	V.push_back(a);
		arr[a]++;
	}
	sort(V.begin(), V.end());
	if (V.size() == 1) {
		for (int i = 0; i < arr[V[0]]; i++)	cout << V[0] << ' ';
		return 0;
	}
	for (int i = 0; i < V.size() - 1; i++) {
		if (!arr[V[i]])	continue;
		if (i == V.size() - 2 && V[i] + 1 == V[i + 1]) {
			for (int j = 0; j < arr[V[i + 1]]; j++)	cout << V[i + 1] << ' ';
			for (int j = 0; j < arr[V[i]]; j++)	cout << V[i] << ' ';
			arr[V[i + 1]] = arr[V[i]] = 0;
			break;
		}
		for (int j = 0; j < arr[V[i]]; j++)	cout << V[i] << ' ';
		if (V[i] + 1 == V[i + 1] && arr[V[i + 1]]) {
			cout << V[i + 2] << ' ';
			arr[V[i + 2]]--;
		}
	}
	for (int i = 0; i < arr[V.back()]; i++)	cout << V.back() << ' ';
}