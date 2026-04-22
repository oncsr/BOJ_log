#include <iostream>
#include <vector>
using namespace std;

int main() {
	string a, b;
	cin >> a >> b;
	int arr[26] = { 3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1 };
	vector<int> V;
	for (int i = 0; i < a.size(); i++) {
		V.push_back(arr[a[i] - 'A']);
		V.push_back(arr[b[i] - 'A']);
	}
	while (V.size() > 2) {
		vector<int> temp;
		for (int i = 0; i < V.size() - 1; i++)
			temp.push_back((V[i] + V[i + 1]) % 10);
		V = temp;
	}
	cout << V[0] << V[1];
}