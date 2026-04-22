#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, L, id = 0;
	int magnet[500001]{};
	cin >> N >> L;
	int s = 0;
	string temp = "";
	for (int i = 0; i < N; i++) {
		string a;
		cin >> a;
		if (a == temp)	s++;
		else {
			magnet[id++] = s;
			s = 1;
		}
		temp = a;
	}
	magnet[id++] = s;
	
	s = 1;
	int e = 1;
	int sum = magnet[1], mn = 500001;
	bool edge = true;
	while (s < id) {
		if (s == 1 || e == id - 1)	edge = true;
		else	edge = false;
		if (sum == L) {
			if (((e - s + 1) % 2 == 0 && edge) || (e - s + 1) % 2 == 1) {
				mn = min(mn, e - s + 1);
			}
			e++;
			if (e >= id)	break;
			sum += magnet[e];
		}
		else if (sum > L) {
			sum -= magnet[s];
			s++;
		}
		else {
			e++;
			if (e >= id)	break;
			sum += magnet[e];
		}
	}
	cout << mn / 2;

}