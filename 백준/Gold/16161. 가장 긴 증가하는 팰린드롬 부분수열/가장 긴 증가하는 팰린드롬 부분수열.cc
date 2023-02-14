#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, arr[100000]{}, mx = 1;
	stack<int> temp;
	stack<int> emp;
	cin >> N;
	for (int i = 0; i < N; i++)	cin >> arr[i];
	for (int i = 1; i < N; i++) {
		if (arr[i] > arr[i - 1])	temp.push(arr[i - 1]);
		else {
			int sz = 0;
			if (arr[i] == arr[i - 1])	temp.push(arr[i - 1]);
			else	sz = 1;
			for (int pos = i; pos < N && !temp.empty(); pos++) {
				if (arr[pos] == temp.top()) {
					sz += 2;
					temp.pop();
				}
				else {
					temp = emp;
					break;
				}
			}
			mx = max(mx, sz);
		}
	}
	cout << mx;
}