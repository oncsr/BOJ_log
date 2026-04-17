#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	string S;
	ll N;
	cin >> S >> N;
	string ch[26]{};
	// sum[i][j][k] = 대문자 i의 변환에서, 1~j번째 문자 중 소문자 k의 개수
	vector<vector<int>> sum2[26]{};
	for (int i = 0; i < N; i++) {
		char a;
		string b;
		cin >> a >> b;
		ch[a - 'A'] = b;
		sum2[a - 'A'] = vector<vector<int>>(b.size(), vector<int>(26));
		sum2[a - 'A'][0][b[0] - 'a']++;
		for (int j = 1; j < b.size(); j++) {
			sum2[a - 'A'][j][b[j] - 'a']++;
			for (int k = 0; k < 26; k++)	sum2[a - 'A'][j][k] += sum2[a - 'A'][j - 1][k];
		}
	}

	vector<vector<ll>> sum1(S.size(), vector<ll>(26));
	for (int j = 0; j < 26; j++)	sum1[0][j] = sum2[S[0] - 'A'][ch[S[0] - 'A'].size() - 1][j];
	vector<ll> start(S.size());
	for (int i = 1; i < S.size(); i++) {
		start[i] = start[i - 1] + ch[S[i - 1] - 'A'].size();
		for (int j = 0; j < 26; j++)	sum1[i][j] = sum2[S[i] - 'A'][ch[S[i] - 'A'].size() - 1][j];
		for (int j = 0; j < 26; j++)	sum1[i][j] += sum1[i - 1][j];
	}

	int Q;
	for (cin >> Q; Q--;) {
		ll o, s, e;
		cin >> o >> s >> e;
		s--; e--;
		int l = upper_bound(start.begin(), start.end(), s) - start.begin();
		int r = upper_bound(start.begin(), start.end(), e) - start.begin() - 1;

		if (o == 1) {
			if (l > r) {
				for (int i = s - start[r]; i <= e - start[r]; i++)	cout << ch[S[r] - 'A'][i];
			}
			else {
				for (int i = s - start[l - 1]; i < ch[S[l - 1] - 'A'].size(); i++)	cout << ch[S[l - 1] - 'A'][i];
				for (int i = l; i < r; i++)	cout << ch[S[i] - 'A'];
				for (int i = 0; i <= e - start[r]; i++)	cout << ch[S[r] - 'A'][i];
			}
			cout << '\n';
		}
		else {
			vector<ll> res(26);
			if (r)	res = sum1[r - 1];
			
			//r번째 글자의 누적 합을 e-start[r]번째 까지 더해야함
			for (int j = 0; j < 26; j++) {
				res[j] += ll(sum2[S[r] - 'A'][e - start[r]][j]);
				if (l - 2 >= 0)	res[j] -= sum1[l - 2][j];
				if (s - start[l - 1] > 0)	res[j] -= ll(sum2[S[l - 1] - 'A'][s - start[l - 1] - 1][j]);
			}
			cout << *max_element(res.begin(), res.end()) << '\n';

		}
	}

}