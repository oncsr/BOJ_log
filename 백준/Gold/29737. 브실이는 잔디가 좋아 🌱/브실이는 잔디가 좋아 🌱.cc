#include <bits/stdc++.h>
using namespace std;

struct node {
	string name;
	int len, cnt, start, fail;
};

bool cmp(node a, node b) {
	if (a.len == b.len) {
		if (a.cnt == b.cnt) {
			if (a.start == b.start) {
				if (a.fail == b.fail)	return a.name < b.name;
				return a.fail < b.fail;
			}
			return a.start < b.start;
		}
		return a.cnt < b.cnt;
	}
	return a.len > b.len;
}

bool same(node a, node b) {
	return a.len == b.len && a.cnt == b.cnt && a.start == b.start && a.fail == b.fail;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, W;
	cin >> N >> W;
	node arr[100]{};
	for (int i = 0; i < N; i++) {
		cin >> arr[i].name;
		char record[7][100]{};
		for (int j = 0; j < 7; j++)
			for (int k = 0; k < W; k++)
				cin >> record[j][k];

		int suc = 0, day = 1, st = 0, freeze = 0, f = 0;
		int temp = 0;
		for (int k = 0; k < W; k++) {
			for (int j = 0; j < 7; j++) {
				if (record[j][k] == 'O') {
					if (!suc)	st = day;
					freeze += temp;
					temp = 0;
					suc++;
				}
				else if (record[j][k] == 'X') {
					if (suc > arr[i].len) {
						arr[i].len = suc;
						arr[i].cnt = freeze;
						arr[i].start = st;
					}
					else if (suc == arr[i].len && freeze < arr[i].cnt) {
						arr[i].len = suc;
						arr[i].cnt = freeze;
						arr[i].start = st;
					}
					f++;
					suc = 0, st = 0, freeze = 0, temp = 0;
				}
				else {
					if (suc)	temp++;
					else	temp = 0;
				}
				day++;
			}
		}
		if (suc > arr[i].len) {
			arr[i].len = suc;
			arr[i].cnt = freeze;
			arr[i].start = st;
		}
		else if (suc == arr[i].len && freeze < arr[i].cnt) {
			arr[i].len = suc;
			arr[i].cnt = freeze;
			arr[i].start = st;
		}
		arr[i].fail = f;
	}
	sort(arr, arr + N, cmp);
	/*
	for (int i = 0; i < N; i++) {
		cout << "Name :\t\t" << arr[i].name << '\n';
		cout << "Streak :\t" << arr[i].len << '\n';
		cout << "Freeze :\t" << arr[i].cnt << '\n';
		cout << "Start :\t\t" << arr[i].start << '\n';
		cout << "Fail :\t\t" << arr[i].fail << '\n';
	}
	*/

	int rank = 1;
	for (int i = 0; i < N; i++) {
		if (!i)	cout << rank << ". " << arr[i].name << '\n';
		else {
			if (!same(arr[i], arr[i - 1]))	rank++;
			cout << rank << ". " << arr[i].name << '\n';
		}
	}
}