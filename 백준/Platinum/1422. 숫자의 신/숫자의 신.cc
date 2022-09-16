#include <iostream>
using namespace std;

//	2022-08-28
// 자릿수 많은 걸 n-k번 쓰고
// 9 91 901 88 84 7098 ... 순서대로

int main() {
	int k, n;
	string arr[51]{};
	int mx = 0;
	string ch;
	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		cin >> arr[i];
		if (arr[i].size() > mx) {
			mx = arr[i].size();
			ch = arr[i];
		}
		else if (arr[i].size() == mx && arr[i] > ch)
			ch = arr[i];
	}
	for (int i = k - 1;i>0; i--) {
		for (int j = 0; j < i; j++) {
			bool change = false, brk = false;
			for (int g = 0; g < min(arr[j].size(), arr[j + 1].size()); g++) {
				if (arr[j + 1][g] > arr[j][g]) {
					change = true;
					brk = true;
					break;
				}
				if (arr[j + 1][g] < arr[j][g]) {
					brk = true;
					break;
				}
			}
			if (!brk) {
				if (arr[j].size() > arr[j + 1].size()) {
					int g = arr[j + 1].size();
					for (;; g++) {
						if (g > 100)
							break;
						if (arr[j][g%arr[j].size()] < arr[j + 1][g % arr[j + 1].size()]) {
							change = true;
							break;
						}
						if (arr[j][g%arr[j].size()] > arr[j + 1][g % arr[j + 1].size()])
							break;
					}
				}
				else if (arr[j].size() < arr[j + 1].size()) {
					int g = arr[j].size();
					for (;; g++) {
						if (g > 100)
							break;
						if (arr[j + 1][g%arr[j+1].size()] > arr[j][g % arr[j].size()]) {
							change = true;
							break;
						}
						if (arr[j + 1][g%arr[j+1].size()] < arr[j][g % arr[j].size()])
							break;
					}
				}
			}
			if (change) {
				string temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	int c = 0;
	for (int i = 0; i < k; i++) {
		if ((arr[i] == ch) && !c) {
			for (int j = 0; j < n - k + 1; j++)cout << ch;
			c++;
		}
		else cout << arr[i];
	}
}