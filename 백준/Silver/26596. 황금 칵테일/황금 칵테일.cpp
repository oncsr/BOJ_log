#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <cassert>
#include <map>
#include<set>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using pll = pair <ll, ll>;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	string a[5000]{};
	int id = 0;
	double arr[5000]{};
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		double b;
		cin >> s >> b;
		int j = 0;
		for (; j < id; j++)
			if (a[j] == s) {
				arr[j] += b;
				break;
			}
		if (j == id) {
			arr[id] += b, a[id] = s;
			id++;
		}
	}
	bool yes = false;
	for (int i = 0; i < id; i++) {
		for (int j = i + 1; j < id; j++) {
			double b = 1.618;
			int ta = b * arr[i], tb = b * arr[j];
			if (ta == arr[j] || tb == arr[i]) {
				yes = true;
				break;
			}
		}
		if (yes)	break;
	}
	cout << (yes ? "Delicious!" : "Not Delicious...");
}