#include <bits/stdc++.h>
using namespace std;

struct node {
	int gold, silver, bronze;
	string name;
};

bool compare(node a, node b) {
	if (a.gold == b.gold) {
		if (a.silver == b.silver) {
			if (a.bronze == b.bronze) {
				return a.name < b.name;
			}
			return a.bronze > b.bronze;
		}
		return a.silver > b.silver;
	}
	return a.gold > b.gold;
}

void print(node a, int rank) {
	int sum = a.gold + a.silver + a.bronze;
	cout << rank << ' ' << a.name << ' ' << a.gold << ' ' << a.silver;
	cout << ' ' << a.bronze << ' ' << sum << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	vector<node> arr;
	int a, b, c;
	string s;
	while (cin >> s >> a >> b >> c) {
		node temp;
		temp.name = s;
		temp.gold = a;
		temp.silver = b;
		temp.bronze = c;
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end(), compare);
	int ta = -1, tb = -1, tc = -1, rank = 1, trank = 1;
	for (node now : arr) {
		int sum = now.gold + now.silver + now.bronze;
		if (ta == -1) {
			print(now, rank++);
		}
		else {
			if (now.gold == ta && now.silver == tb && now.bronze == tc) {
				print(now, trank);
				rank++;
			}
			else {
				trank = rank;
				print(now, rank++);
			}
		}
		ta = now.gold, tb = now.silver, tc = now.bronze;
	}
}