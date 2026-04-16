#include <iostream>
#include <set>
#include <tuple>
#include <bitset>
#include <functional>
using namespace std;
// 난이도, 번호, 종류, id
using problem = tuple<int, int, int, int>;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;
	set<problem> Total, Type[101]{}, Rank[101]{};

	bitset<200001> solved;

	int id = 0, numToId[200001]{};

	for (int i = 0, p, l, g; i < N; i++) {
		cin >> p >> l >> g;
		problem pr = { l,p,g,numToId[p]=id++ };
		Total.insert(pr);
		Type[g].insert(pr);
		Rank[l].insert(pr);
	}

	function isSolved = [&](problem pr) -> bool {return solved[get<3>(pr)]; };

	int M;
	for (cin >> M; M--;) {
		string op;
		cin >> op;
		if (op == "recommend") {
			int g, x;
			cin >> g >> x;
			while (1) {
				problem pr = x == 1 ? *Type[g].rbegin() : *Type[g].begin();
				if (isSolved(pr)) Type[g].erase(pr);
				else break;
			}
			cout << get<1>(x == 1 ? *Type[g].rbegin() : *Type[g].begin()) << '\n';
		}
		if (op == "recommend2") {
			int x;
			cin >> x;
			while (1) {
				problem pr = x == 1 ? *Total.rbegin() : *Total.begin();
				if (isSolved(pr)) Total.erase(pr);
				else break;
			}
			cout << get<1>(x == 1 ? *Total.rbegin() : *Total.begin()) << '\n';
		}
		if (op == "recommend3") {
			int x, l;
			cin >> x >> l;
			bool f = 0;
			if (x == 1) {
				for (int i = l; i <= 100; i++) {
					while (!Rank[i].empty()) {
						problem pr = *Rank[i].begin();
						if (isSolved(pr)) Rank[i].erase(pr);
						else { f = 1; break; }
					}
					if (f) { cout << get<1>(*Rank[i].begin()) << '\n'; break; }
				}
				if (!f) cout << "-1\n";
			}
			else {
				for (int i = l - 1; i > 0; i--) {
					while (!Rank[i].empty()) {
						problem pr = *Rank[i].rbegin();
						if (isSolved(pr)) Rank[i].erase(pr);
						else { f = 1; break; }
					}
					if (f) { cout << get<1>(*Rank[i].rbegin()) << '\n'; break; }
				}
				if (!f) cout << "-1\n";
			}
		}
		if (op == "add") {
			int p, l, g;
			cin >> p >> l >> g;
			problem pr = { l,p,g,numToId[p] = id++ };
			Total.insert(pr);
			Type[g].insert(pr);
			Rank[l].insert(pr);
		}
		if (op == "solved") {
			int p;
			cin >> p;
			solved[numToId[p]] = 1;
		}
	}

}