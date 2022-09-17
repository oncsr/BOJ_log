#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

bool absmin(int a, int b){
	return a < b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	int arr[100001];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);
	int min;
	int start = 0;
	int end = n - 1;
	int lq1, lq2;
	int fklq1, fklq2;
	for (int i = 0; i < n-1; i++) {
		if (i == 0) {
			min = arr[end] + arr[start];
			fklq1 = arr[end];
			fklq2 = arr[start];
			if (min < 0)
				start++;
			else
				end--;
			min = abs(min);
			lq1 = fklq1;
			lq2 = fklq2;
			continue;
		}
		else {
			int temp = arr[end] + arr[start];
			fklq1 = arr[end];
			fklq2 = arr[start];
			if (temp < 0)
				start++;
			else
				end--;
			temp = abs(temp);
			if (absmin(temp, min)) {
				lq1 = fklq1;
				lq2 = fklq2;
				min = abs(temp);
			}
		}
	}
	cout << lq2 << ' ' << lq1 << '\n';
}