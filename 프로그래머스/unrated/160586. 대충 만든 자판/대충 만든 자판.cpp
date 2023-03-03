#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
	vector<int> answer;
	int arr[26]{};
	for (string now : keymap) {
		for (int i = 0; i < now.size(); i++) {
			int cnt = i + 1;
			if (!arr[now[i] - 'A'])
				arr[now[i] - 'A'] = cnt;
			else
				arr[now[i] - 'A'] = min(arr[now[i] - 'A'], cnt);
		}
	}
	for (string now : targets) {
		int s = 0;
		for (char i : now) {
			if (!arr[i - 'A']) {
				s = -1;
				break;
			}
			s += arr[i - 'A'];
		}
		answer.push_back(s);
	}
	return answer;
}