#include <iostream>
#include <vector>
#include <map>
using namespace std;

int LEVEL = 1, MAX_HP = 20, HP = 20, ATT = 2, DEF = 2, EXP = 0;
int WEAPON = 0, ARMOR = 0;
int X, Y, OX, OY;
bool death = false, win = false;
int k = 0, l = 0;

double exp_bonus = 1;
int spike_damage = 5;
int courage_bonus = 2;

string DEATH_MESSAGE = "YOU HAVE BEEN KILLED BY ";
string ALIVE_MESSAGE = "Press any key to continue.";
string WIN_MESSAGE = "YOU WIN!";
int ACC[8] = { 0 };
struct MONSTER {
	string NAME;
	int W, A, H, E;
};

int n, m;

int Turns = 0;
string MAP[101];
string command;
map<pair<int, int>, MONSTER> monster;
map<pair<int, int>, pair<int, int> > box;
 
void HP_Regeneration() {
	if (ACC[1] == 1)
		HP = min(HP + 3, MAX_HP);
}

bool Reincarnation() {
	if (ACC[2] == 1) {
		HP = MAX_HP;
		X = OX, Y = OY;
		ACC[2] = 0;
		ACC[0]--;
		return true;
	}
	return false;
}

void Levelup(int ex) {
	EXP += ex * exp_bonus;
	if (EXP >= 5 * LEVEL) {
		EXP = 0;
		LEVEL++;
		MAX_HP += 5;
		ATT += 2;
		DEF += 2;
		HP = MAX_HP;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> MAP[i];
		for (int j = 0; j < m; j++) {
			if (MAP[i][j] == '@') {
				X = i, Y = j;
				OX = i, OY = j;
				MAP[i][j] = '.';
			}
			if (MAP[i][j] == '&' || MAP[i][j] == 'M')	k++;
			if (MAP[i][j] == 'B')	l++;
		}
	}
	cin >> command;
	int r, c, w, a, h, e;
	string s;
	while (k--) {
		cin >> r >> c >> s >> w >> a >> h >> e;
		MONSTER temp;
		temp.NAME = s;
		temp.W = w, temp.A = a, temp.H = h, temp.E = e;
		monster[{r - 1, c - 1}] = temp;
	}
	char t;
	while (l--) {
		cin >> r >> c >> t;
		if (t == 'O') {
			string b;
			cin >> b;
			int code;
			if (b == "HR")	code = 1;
			else if (b == "RE")	code = 2;
			else if (b == "CO")	code = 3;
			else if (b == "EX")	code = 4;
			else if (b == "DX")	code = 5;
			else if (b == "HU")	code = 6;
			else	code = 7;
			box[{r - 1, c - 1}] = { 3, code };
		}
		else {
			int b;
			cin >> b;
			int code;
			if (t == 'W')	code = 1;
			else	code = 2;
			box[{r - 1, c - 1}] = { code, b };
		}
	}



	for (auto& i : command) {
		Turns++;
		int tx = X, ty = Y;
		if (i == 'R')	Y++;
		if (i == 'U')	X--;
		if (i == 'L')	Y--;
		if (i == 'D')	X++;
		if (X < 0 || Y < 0 || X >= n || Y >= m)	X = tx, Y = ty;

		if (MAP[X][Y] == '#')	X = tx, Y = ty;

		if (MAP[X][Y] == '.')	continue;
		else if (MAP[X][Y] == '^') {
			HP -= spike_damage;
			if (HP <= 0) {
				HP = 0;
				if (Reincarnation())	continue;
				DEATH_MESSAGE += "SPIKE TRAP..";
				death = true;
				break;
			}
		}
		else if (MAP[X][Y] == 'B') {
			int type, code;
			type = box[{X, Y}].first;
			code = box[{X, Y}].second;
			if (type == 1)	WEAPON = code;
			else if (type == 2)	ARMOR = code;
			else {
				if (ACC[0] < 4) {
					if (ACC[code] == 0) {
						ACC[code] = 1;
						ACC[0]++;
						if ((code == 3 && ACC[5] == 1) || (code == 5 && ACC[3] == 1))	courage_bonus = 3;
						if (code == 4)	exp_bonus = 1.2;
						if (code == 5)	spike_damage = 1;
					}
				}
			}
			MAP[X][Y] = '.';
		}
		else {
			MONSTER now = monster[{X, Y}];
			bool boss = (MAP[X][Y] == 'M' ? true : false);
			int OH = now.H;
			if (boss && ACC[6] == 1) {
				HP = MAX_HP;
			}
			if (ACC[3] == 1) {
				now.H -= max(1, (WEAPON + ATT) * courage_bonus - now.A);
			}
			else {
				now.H -= max(1, WEAPON + ATT - now.A);
			}

			if (now.H <= 0) {
				HP_Regeneration();
				Levelup(now.E);
				MAP[X][Y] = '.';
				if (boss) {
					win = true;
					break;
				}
			}
			else {
				if (boss && ACC[6] == 1)	HP -= 0;
				else	HP -= max(1, now.W - (DEF + ARMOR));
				if (HP <= 0) {
					HP = 0;
					if (Reincarnation()) {
						now.H = OH;
						continue;
					}
					DEATH_MESSAGE = DEATH_MESSAGE + now.NAME + "..";
					death = true;
					break;
				}
				else {
					while (HP > 0 && now.H > 0) {
						now.H -= max(1, ATT + WEAPON - now.A);
						if (now.H <= 0) {
							HP_Regeneration();
							Levelup(now.E);
							MAP[X][Y] = '.';
							break;
						}
						HP -= max(1, now.W - (DEF + ARMOR));
					}
					if (HP > 0) {
						if (boss) {
							win = true;
							break;
						}
						continue;
					}
					else {
						HP = 0;
						if (Reincarnation()) {
							now.H = OH;
							continue;
						}
						DEATH_MESSAGE = DEATH_MESSAGE + now.NAME + "..";
						death = true;
						break;
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == X && j == Y && !death)	cout << '@';
			else	cout << MAP[i][j];
		}
		cout << '\n';
	}
	cout << "Passed Turns : " << Turns << '\n';
	cout << "LV : " << LEVEL << '\n';
	cout << "HP : " << HP << '/' << MAX_HP << '\n';
	cout << "ATT : " << ATT << '+' << WEAPON << '\n';
	cout << "DEF : " << DEF << '+' << ARMOR << '\n';
	cout << "EXP : " << EXP << '/' << 5 * LEVEL << '\n';
	if (win)	cout << WIN_MESSAGE << '\n';
	else if (death)	cout << DEATH_MESSAGE << '\n';
	else	cout << ALIVE_MESSAGE << '\n';
}