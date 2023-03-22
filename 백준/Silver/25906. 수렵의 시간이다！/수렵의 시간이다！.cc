#include <iostream>
#include <vector>
using namespace std;

struct skill {
	int MAX_LV;
	vector<int> ATK;
};

struct armor {
	int PRICE;
	vector<int> SKILL_LV;
};

skill SKILL[5]{};

vector<armor> HEAD;
vector<armor> CHEST;
vector<armor> PANTS;

int T, K;

int solve(vector<armor> thing) {
	int mx = 0;

	if (thing.empty()) {
		for (armor head : HEAD) {
			for (armor chest : CHEST) {
				for (armor pants : PANTS) {

					// purchase possibility checking
					int need_gold = head.PRICE + chest.PRICE + pants.PRICE;
					if (T < need_gold)	continue;

					// compute 'attack' increasing
					vector<int> now_skill(5, 0);	// current skill lv increasing
					int attack = 0;
					for (int i = 0; i < 5; i++) {
						int expected_lv = head.SKILL_LV[i] + chest.SKILL_LV[i] + pants.SKILL_LV[i];
						now_skill[i] = min(SKILL[i].MAX_LV, expected_lv);
						attack += SKILL[i].ATK[now_skill[i]];
					}

					mx = max(mx, attack);

				}
			}
		}
		return mx;
	}
	if (T < K)	return mx;

	for (int i = 0; i < thing.size(); i++) {
		for (int j = 0; j < 5; j++) {
			if (thing[i].SKILL_LV[j] == 0)	continue;

			thing[i].SKILL_LV[j]--;

			for (int k = 0; k < 5; k++) {
				if (j == k)	continue;

				
				thing[i].SKILL_LV[k]++;

				for (armor head : HEAD) {
					for (armor chest : CHEST) {
						for (armor pants : PANTS) {

							// purchase possibility checking
							int need_gold = head.PRICE + chest.PRICE + pants.PRICE;
							if (T - K < need_gold)	continue;

							// compute 'attack' increasing
							int gold = (T - K) - need_gold;
							vector<int> now_skill(5, 0);	// current skill lv increasing
							int attack = 0;
							for (int i = 0; i < 5; i++) {
								int expected_lv = head.SKILL_LV[i] + chest.SKILL_LV[i] + pants.SKILL_LV[i];
								now_skill[i] = min(SKILL[i].MAX_LV, expected_lv);
								attack += SKILL[i].ATK[now_skill[i]];
							}

							mx = max(mx, attack);

						}
					}
				}

				
				thing[i].SKILL_LV[k]--;

			}

			thing[i].SKILL_LV[i]++;
		}
	}

	return mx;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	armor trash;
	trash.PRICE = 0;
	trash.SKILL_LV = { 0,0,0,0,0 };

	cin >> T >> K;
	for (int i = 0; i < 5; i++) {
		int l, a;
		cin >> l;
		SKILL[i].MAX_LV = l;
		SKILL[i].ATK.push_back(0);
		for (int j = 0; j < l; j++) {
			cin >> a;
			SKILL[i].ATK.push_back(a);
		}
	}

	int M;
	cin >> M;
	HEAD = vector<armor>(M + 1);
	
	HEAD[0] = trash;
	for (int i = 1; i <= M; i++) {
		int a;
		cin >> a;
		HEAD[i].PRICE = a;
	}
	for (int i = 1; i <= M; i++) {
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		HEAD[i].SKILL_LV = { a,b,c,d,e };
	}
	cin >> M;
	CHEST = vector<armor>(M + 1);

	CHEST[0] = trash;
	for (int i = 1; i <= M; i++) {
		int a;
		cin >> a;
		CHEST[i].PRICE = a;
	}
	for (int i = 1; i <= M; i++) {
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		CHEST[i].SKILL_LV = { a,b,c,d,e };
	}
	cin >> M;
	PANTS = vector<armor>(M + 1);
	
	PANTS[0] = trash;
	for (int i = 1; i <= M; i++) {
		int a;
		cin >> a;
		PANTS[i].PRICE = a;
	}
	for (int i = 1; i <= M; i++) {
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		PANTS[i].SKILL_LV = { a,b,c,d,e };
	}

	// input end

	int mx = 0;	// total answer
	
	if (T >= K) {
		for (int i = 0; i < HEAD.size(); i++) {
			for (int j = 0; j < 5; j++) {
				if (HEAD[i].SKILL_LV[j] == 0)	continue;

				HEAD[i].SKILL_LV[j]--;

				for (int k = 0; k < 5; k++) {
					if (j == k)	continue;


					HEAD[i].SKILL_LV[k]++;

					armor head = HEAD[i];

					for (armor chest : CHEST) {
						for (armor pants : PANTS) {

							// purchase possibility checking
							int need_gold = head.PRICE + chest.PRICE + pants.PRICE;
							if (T - K < need_gold)	continue;

							// compute 'attack' increasing
							int gold = (T - K) - need_gold;
							vector<int> now_skill(5, 0);	// current skill lv increasing
							int attack = 0;
							for (int i = 0; i < 5; i++) {
								int expected_lv = head.SKILL_LV[i] + chest.SKILL_LV[i] + pants.SKILL_LV[i];
								now_skill[i] = min(SKILL[i].MAX_LV, expected_lv);
								attack += SKILL[i].ATK[now_skill[i]];
							}

							mx = max(mx, attack);

						}
					}


					HEAD[i].SKILL_LV[k]--;

				}

				HEAD[i].SKILL_LV[j]++;
			}
		}
		/////////////////////////////////////////////
		for (int i = 0; i < CHEST.size(); i++) {
			for (int j = 0; j < 5; j++) {
				if (CHEST[i].SKILL_LV[j] == 0)	continue;

				CHEST[i].SKILL_LV[j]--;

				for (int k = 0; k < 5; k++) {
					if (j == k)	continue;


					CHEST[i].SKILL_LV[k]++;

					armor chest = CHEST[i];

					for (armor head : HEAD) {
						for (armor pants : PANTS) {

							// purchase possibility checking
							int need_gold = head.PRICE + chest.PRICE + pants.PRICE;
							if (T - K < need_gold)	continue;

							// compute 'attack' increasing
							int gold = (T - K) - need_gold;
							vector<int> now_skill(5, 0);	// current skill lv increasing
							int attack = 0;
							for (int i = 0; i < 5; i++) {
								int expected_lv = head.SKILL_LV[i] + chest.SKILL_LV[i] + pants.SKILL_LV[i];
								now_skill[i] = min(SKILL[i].MAX_LV, expected_lv);
								attack += SKILL[i].ATK[now_skill[i]];
							}

							mx = max(mx, attack);

						}
					}


					CHEST[i].SKILL_LV[k]--;

				}

				CHEST[i].SKILL_LV[j]++;
			}
		}
		//////////////////////////////////////////////
		for (int i = 0; i < PANTS.size(); i++) {
			for (int j = 0; j < 5; j++) {
				if (PANTS[i].SKILL_LV[j] == 0)	continue;

				PANTS[i].SKILL_LV[j]--;

				for (int k = 0; k < 5; k++) {
					if (j == k)	continue;


					PANTS[i].SKILL_LV[k]++;

					armor pants = PANTS[i];

					for (armor head : HEAD) {
						for (armor chest : CHEST) {

							// purchase possibility checking
							int need_gold = head.PRICE + chest.PRICE + pants.PRICE;
							if (T - K < need_gold)	continue;

							// compute 'attack' increasing
							int gold = (T - K) - need_gold;
							vector<int> now_skill(5, 0);	// current skill lv increasing
							int attack = 0;
							for (int i = 0; i < 5; i++) {
								int expected_lv = head.SKILL_LV[i] + chest.SKILL_LV[i] + pants.SKILL_LV[i];
								now_skill[i] = min(SKILL[i].MAX_LV, expected_lv);
								attack += SKILL[i].ATK[now_skill[i]];
							}

							mx = max(mx, attack);

						}
					}


					PANTS[i].SKILL_LV[k]--;

				}

				PANTS[i].SKILL_LV[j]++;
			}
		}
	}

	for (armor head : HEAD) {
		for (armor chest : CHEST) {
			for (armor pants : PANTS) {

				// purchase possibility checking
				int need_gold = head.PRICE + chest.PRICE + pants.PRICE;
				if (T < need_gold)	continue;

				// compute 'attack' increasing
				int gold = T - need_gold;
				vector<int> now_skill(5, 0);	// current skill lv increasing
				int attack = 0;
				for (int i = 0; i < 5; i++) {
					int expected_lv = head.SKILL_LV[i] + chest.SKILL_LV[i] + pants.SKILL_LV[i];
					now_skill[i] = min(SKILL[i].MAX_LV, expected_lv);
					attack += SKILL[i].ATK[now_skill[i]];
				}

				mx = max(mx, attack);

			}
		}
	}
	

	cout << mx;

}