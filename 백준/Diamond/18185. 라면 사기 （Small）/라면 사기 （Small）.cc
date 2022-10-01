#include <iostream>
using namespace std;

int main() {
	int arr[10001];
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int money = 0;
	int i = 0;
	while (i < n - 3) {
		if (arr[i] != 0) {
			if (arr[i + 1] != 0) {
				if (arr[i + 2] != 0) {
					if (arr[i + 1] > arr[i + 2] && arr[i + 3] != 0) {
						int g = min(arr[i + 1] - arr[i + 2], arr[i]);
						arr[i] -= g;
						arr[i + 1] -= g;
						money += 5 * g;
					}
					else {
						int g = min(arr[i], min(arr[i + 1], arr[i + 2]));
						arr[i] -= g;
						arr[i + 1] -= g;
						arr[i + 2] -= g;
						money += 7 * g;
					}
				}
				else {
					int g = min(arr[i], arr[i + 1]);
					arr[i] -= g;
					arr[i + 1] -= g;
					money += 5 * g;
				}
			}
			else {
				money += 3 * arr[i];
				arr[i] = 0;
			}
		}
		else
			i++;
	}
	int mn = min(arr[i], min(arr[i + 1], arr[i + 2]));
	money += mn * 7;
	arr[i] -= mn;
	arr[i + 1] -= mn;
	arr[i + 2] -= mn;
	if (arr[i] == 0) {
		if (arr[i + 1] == 0)
			money += arr[i + 2] * 3;
		else {
			if (arr[i + 2] == 0)
				money += arr[i + 1] * 3;
			else {
				int mn2 = min(arr[i + 1], arr[i + 2]);
				money += (mn2 * 5 + (arr[i + 1] - mn2) * 3 + (arr[i + 2] - mn2) * 3);
			}
		}
	}
	else {
		if (arr[i + 1] == 0)
			money += (arr[i] * 3 + arr[i + 2] * 3);
		else {
			if (arr[i + 2] == 0) {
				int mn2 = min(arr[i], arr[i + 1]);
				money += (mn2 * 5 + (arr[i] - mn2) * 3 + (arr[i + 1] - mn2) * 3);
			}
		}
	}
	cout << money << '\n';
}