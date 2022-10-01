#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll arr[1000001]{};
	ll n, b, c;
	cin >> n >> b >> c;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	ll money = 0;
	int i = 0;
	if (c >= b) {
		for (int i = 0; i < n; i++)
			money += b * arr[i];
	}
	else {
		while (i < n - 3) {
			if (arr[i] != 0) {
				if (arr[i + 1] != 0) {
					if (arr[i + 2] != 0) {
						if (arr[i + 1] > arr[i + 2] && arr[i + 3] != 0) {
							ll g = min(arr[i + 1] - arr[i + 2], arr[i]);
							arr[i] -= g;
							arr[i + 1] -= g;
							money += (b + c) * g;
						}
						else {
							ll g = min(arr[i], min(arr[i + 1], arr[i + 2]));
							arr[i] -= g;
							arr[i + 1] -= g;
							arr[i + 2] -= g;
							money += (b + 2 * c) * g;
						}
					}
					else {
						ll g = min(arr[i], arr[i + 1]);
						arr[i] -= g;
						arr[i + 1] -= g;
						money += (b + c) * g;
					}
				}
				else {
					money += b * arr[i];
					arr[i] = 0;
				}
			}
			else
				i++;
		}
		ll mn = min(arr[i], min(arr[i + 1], arr[i + 2]));
		money += mn * (b + 2 * c);
		arr[i] -= mn;
		arr[i + 1] -= mn;
		arr[i + 2] -= mn;
		if (arr[i] == 0) {
			if (arr[i + 1] == 0)
				money += arr[i + 2] * b;
			else {
				if (arr[i + 2] == 0)
					money += arr[i + 1] * b;
				else {
					ll mn2 = min(arr[i + 1], arr[i + 2]);
					money += (mn2 * (b + c) + (arr[i + 1] - mn2) * b + (arr[i + 2] - mn2) * b);
				}
			}
		}
		else {
			if (arr[i + 1] == 0)
				money += (arr[i] * b + arr[i + 2] * b);
			else {
				if (arr[i + 2] == 0) {
					ll mn2 = min(arr[i], arr[i + 1]);
					money += (mn2 * (b + c) + (arr[i] - mn2) * b + (arr[i + 1] - mn2) * b);
				}
			}
		}
	}
	cout << money << '\n';
}