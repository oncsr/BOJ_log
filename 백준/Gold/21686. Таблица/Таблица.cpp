#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll arr[2002]{}, R;
	vector<ll> left(2002), center(2002), right(2002);
	int N, M;
	cin >> N >> M >> R;
	for (int i = 1; i <= M; i++) {
		cin >> arr[i];
		center[i] = left[i] = right[i] = arr[i];
	}

	for (int i = 2; i <= N; i++) {
		vector<ll> TL(2002), TR(2002);
		for (int j = 1; j <= M; j++) {
			arr[j] = (left[j - 1] + center[j] + right[j + 1]) % R;
			center[j] = (center[j] + arr[j]) % R;
			TL[j] = (left[j - 1] + center[j]) % R;
			TR[j] = (right[j + 1] + center[j]) % R;
		}
		left = TL, right = TR;
	}
	for (int i = 1; i <= M; i++)	cout << arr[i] << ' ';
}