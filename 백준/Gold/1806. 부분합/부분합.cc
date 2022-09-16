#include <iostream>
#include <algorithm>
#define min(a,b) a<b?a:b
#define INSANE	100001
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, s;
	cin >> n >> s;
	int arr[100001];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int cnt = 1;
	int* ptr1 = arr;
	int* ptr2 = arr;
	int sum = *ptr1;
	bool find = false;
	int minlen = INSANE;
	while (ptr2 != arr + n) {
		if (sum < s) {
			ptr2++;
			cnt++;
			sum += *ptr2;
		}
		else {
			minlen = min(cnt, minlen);
			sum -= *ptr1;
			ptr1++;
			cnt--;
		}
	}
	if (minlen == INSANE)
		cout << "0\n";
	else
		cout << minlen << '\n';
}