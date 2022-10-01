#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;

bool compare(const pair<double, int> a, const pair<double, int> b) {
	if (a.first == b.first)
		return a.second < b.second;
	return a.first > b.first;
}

typedef struct Party {
	int all_seat;	// 총 의석 수
	string name;	// 정당 이름
	int seat;		// 지역구 의석 수
	int vote;		// 득표 수
	double Pi;		// 비례대표선거 득표율
	int Si;			// 비례대표 의석 수
	int Ti;			// 나머지에 대한 비례대표 의석 수
}Party;


bool compare2(const Party a, const Party b) {
	if (a.all_seat == b.all_seat)
		return a.name < b.name;
	else
		return a.all_seat > b.all_seat;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Party partylist[51];
	Party par[51];	// 의석할당정당들의 배열
	int par_size = 0;	// 의석할당정당 배열의 사이즈
	Party noseat_par[51];	// 의석할당 x 배열
	int noseat_par_size = 0;	// 의석할당 x 배열의 사이즈
	int n, v;	// n = 정당 수, v = 총 투표수
	cin >> n >> v;
	int real_v = 0;	// real_v = 무효표 제외 투표수
	int real_real_v = 0; // real_real_v = 의석할당정당 총 득표수
	int noparty = 0;	// 무소속 당선인 수
	int N = 300, R;			// 1단계에서의 (N - R) 값
	int N_R;
	int sum_Si = 0;		// 각 의석할당정당의 연동 배분 의석 수(Si)의 합
	int sum_Si_2 = 0;	// 2단계 Si 재설정
	int fake = 0;		// 의석할당정당이 아닌 정당의 당선인 수

	// 정보 입력
	for (int i = 0; i < n; i++) {
		cin >> partylist[i].name >> partylist[i].seat >> partylist[i].vote;
		real_v += partylist[i].vote;
		noparty += partylist[i].seat;
	}
	noparty = 253 - noparty;

	// 각 정당별 득표율 계산 후 의석할당정당인지 여부 판별
	for (int i = 0; i < n; i++) {
		if ((double)partylist[i].vote / (double)real_v >= 0.03 || partylist[i].seat >= 5) {
			par[par_size++] = partylist[i];
			real_real_v += partylist[i].vote;
		}
		else {
			partylist[i].all_seat = partylist[i].seat;
			fake += partylist[i].seat;
			noseat_par[noseat_par_size++] = partylist[i];
		}
	}
	N_R = N - noparty - fake;

	// 1단계
	for (int i = 0; i < par_size; i++) {
		par[i].Pi = (double)par[i].vote / (double)real_real_v;
		double temp = ((double)N_R * par[i].Pi - (double)(par[i].seat)) / 2.0;
		if (temp < 1)
			par[i].Si = 0;
		else
			par[i].Si = (int)round(temp);
		sum_Si += par[i].Si;
	}

	// 2-2단계 (30보다 큰 경우)
	if (sum_Si > 30) {
		vector<pair<double, int> > temp;
		for (int i = 0; i < par_size; i++) {
			double t = ((30.0 * (double)par[i].Si) / (double)sum_Si);
			par[i].Si = (int)t;
			if (par[i].Si != 0) {
				double g = t - (double)par[i].Si;
				temp.push_back({ g, i });
			}
			sum_Si_2 += par[i].Si;
		}
		sort(temp.begin(), temp.end(), compare);
		if(sum_Si_2 < 30)	// 같을 경우에는 그냥 탈출하도록
			while (1) {
				bool br = false;
				for (int i = 0; i < temp.size(); i++) {
					par[temp[i].second].Si++;
					sum_Si_2++;
					if (sum_Si_2 == 30) {
						br = true;
						break;
					}
				}
				if (br)
					break;
			}
	}	// 30보다 작은 경우 = 2-1단계
	else if (sum_Si < 30) {
		vector<pair<double, int> > temp;
		for (int i = 0; i < par_size; i++) {
			double g = (par[i].Si + (30.0 - (double)sum_Si) * par[i].Pi);
			par[i].Si = (int)g;	// floor?
			if (par[i].Si != 0) {
				double t = g - par[i].Si;
				temp.push_back({ t, i });
			}
			sum_Si_2 += par[i].Si;
		}
		sort(temp.begin(), temp.end(), compare);
		if(sum_Si_2 < 30)	// 같을 경우에는 그냥 탈출하도록
			while (1) {
				bool br = false;
				for (int i = 0; i < temp.size(); i++) {
					par[temp[i].second].Si++;
					sum_Si_2++;
					if (sum_Si_2 == 30) {
						br = true;
						break;
					}
				}
				if (br)
					break;
			}
	}

	// 3단계
	int namoji = 17;
	int moji = 0;
	vector<pair<double, int> > temp2;
	for (int i = 0; i < par_size; i++) {
		double t = (namoji * par[i].Pi);
		par[i].Ti = (int)t;
		moji += par[i].Ti;
		double g = t - par[i].Ti;
		temp2.push_back({ g, i });
	}
	sort(temp2.begin(), temp2.end(), compare);
	if(moji < namoji)	// 같을 경우에는 그냥 탈출하도록
		while (1) {
			bool br = false;
			for (int i = 0; i < temp2.size(); i++) {
				par[temp2[i].second].Ti++;
				moji++;
				if (moji == namoji) {
					br = true;
					break;
				}
			}
			if (br)
				break;
		}

	// 의석 수 -> 정당 이름 순으로 정렬
	for (int i = 0; i < par_size; i++)
		par[i].all_seat = par[i].seat + par[i].Si + par[i].Ti;

	sort(par, par + par_size, compare2);
	sort(noseat_par, noseat_par + noseat_par_size, compare2);

	// 순서대로 출력
	for (int i = 0; i < par_size; i++)
		cout << par[i].name << ' ' << par[i].all_seat << '\n';
	for (int i = 0; i < noseat_par_size; i++)
		cout << noseat_par[i].name << ' ' << noseat_par[i].all_seat << '\n';
}