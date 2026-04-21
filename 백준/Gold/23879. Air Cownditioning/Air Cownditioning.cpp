#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int arr1[100001];
	int arr2[100001];
	for (int i = 0; i < n; i++)
		cin >> arr1[i];
	for (int i = 0; i < n; i++)
		cin >> arr2[i];
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (arr1[i] < arr2[i]) {
			int mx = arr2[i] - arr1[i];
			int j = i;
			while (j < n && arr1[j] < arr2[j]) {
				mx = min(mx, arr2[j] - arr1[j]);
				j++;
			}
			for (int k = i; k < j; k++)
				arr1[k] += mx;
			i--;
			ans += mx;
		}
		else if (arr1[i] == arr2[i])
			continue;
		else {
			int mx = arr1[i] - arr2[i];
			int j = i;
			while (j < n && arr1[j] > arr2[j]) {
				mx = min(mx, arr1[j] - arr2[j]);
				j++;
			}
			for (int k = i; k < j; k++)
				arr1[k] -= mx;
			i--;
			ans += mx;
		}
	}
	cout << ans;
}