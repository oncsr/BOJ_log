#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ii = pair<int, int>;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, M;
	string hall;
	cin >> N >> M >> hall;
	vector<int> wall;
	vector<int> remain;
	int s = 1;
	int start = -1, end = -1, dot = 0;
	char temp = ' ';
	for (int i = 0; i < hall.size(); i++) {
		if (!i) {
			temp = hall[i];
			if (hall[i] == 'X')	start = 0;
			continue;
		}
		if (temp != hall[i]) {
			if (temp == '.') {
				if (start == -1)	start = s, dot = s;
				else	remain.push_back(s), dot += s;
			}
			else	wall.push_back(s);
			s = 1;
		}
		else	s++;
		temp = hall[i];
	}
	if (temp == '.')	end = s, dot += s;
	else	end = 0, wall.push_back(s);
	if (wall.size() == 0) {
		if (M < 3)	cout << N;
		else	cout << N - M + 2;
		return 0;
	}
	int combine = 0;
	sort(remain.begin(), remain.end());
	int id = 0;
	int cost = dot - M;
	while (M > 0 && id < remain.size()) {
		if (M >= remain[id]) {
			M -= remain[id++];
			combine++;
		}
		else	break;
	}
	/*
	for (int i : remain) {
		cout << i << ' ';
	}
	cout << '\n';
	for (int i : wall) {
		cout << i << ' ';
	}
	cout << '\n';
	*/
	cout << cost + (wall.size() - combine) * 2;
	



}