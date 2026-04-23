#include <iostream>
using namespace std;
typedef long long ll;

int tree[1000001];
int srt[1000001];

ll cnt = 0;

void merge_sort(int start, int mid, int end) {
	int left, right;
	int tem = start;
	left = start;
	right = mid + 1;
	while (left <= mid && right <= end) {
		if (tree[right] < tree[left]) {
			srt[tem++] = tree[right++];
			cnt += (ll)(mid - left + 1);
		}
		else {
			srt[tem++] = tree[left++];
		}
	}
	if (left <= mid) {
		for (int i = left; i <= mid; i++)
			srt[tem++] = tree[i];
	}
	else {
		for (int i = right; i <= end; i++)
			srt[tem++] = tree[i];
	}
	for (int i = start; i <= end; i++)
		tree[i] = srt[i];
}

void merge(int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		merge(start, mid);
		merge(mid + 1, end);
		merge_sort(start, mid, end);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	for (cin >> n;n;cin>>n) {
		cnt = 0;
		for (int i = 1; i <= n; i++)
			cin >> tree[i];
		merge(1, n);
		cout << (cnt % 2 ? "Marcelo\n" : "Carlos\n");
	}
}