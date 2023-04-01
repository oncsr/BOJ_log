#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N;
	cin >> N;
	string a[1000]{};
	int arr[1000]{};
	int mx = 0, id = 0;
	string mxx = "";
	for (int i = 0; i < N; i++) {
		string t;
		cin >> t;
		bool find = 0;
		for (int j = 0; j < id; j++) {
			if (a[j] == t) {
				arr[j]++;
				if (arr[j] > mx || (arr[j] == mx && a[j] < mxx)) {
					mx = arr[j];
					mxx = a[j];
					find = 1;
				}
			}
		}
		if (!find) {
			arr[id]++;
			if (arr[id] > mx || (arr[id] == mx && t < mxx)) {
				mx = arr[id];
				mxx = t;
			}
			a[id++] = t;
		}
	}
	cout << mxx;

}