#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t;
	for (cin >> t; t--;) {
		int n, s = 0, arr[31]{};
		vector<int> ans;
		cin >> n;
		for (int i = 1; i <= n; i++)	cin >> arr[i];
		if (n < 3)	cout << (arr[1] == 1 ? "0\n" : "1 2\n");
		else {
			for (int i = n; i >= 2; i--) {
				if (arr[i] != i) {
					if (arr[1] != i) {
						int g = 1;
						for (; arr[g] != i; g++);
						for (int j = 1, k = g; j < k; j++, k--)
							swap(arr[j], arr[k]);
						ans.push_back(g);
					}
					for (int j = 1, k = i; j < k; j++, k--)
						swap(arr[j], arr[k]);
					s++;
					ans.push_back(i);
				}
			}
			cout << ans.size() << ' ';
			for (int i : ans)	cout << i << ' ';
			cout << '\n';
		}
		
	}
}