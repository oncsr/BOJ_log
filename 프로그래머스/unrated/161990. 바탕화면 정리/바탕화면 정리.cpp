#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
	vector<int> answer;
	
	pair<int, int> one = { wallpaper.size(), wallpaper[0].size() };
	pair<int, int> two = { 0,0 };

	for (int i = 0; i < wallpaper.size(); i++) {
		for (int j = 0; j < wallpaper[i].size(); j++) {
			if (wallpaper[i][j] == '#') {
				one.first = min(one.first, i);
				one.second = min(one.second, j);
				two.first = max(two.first, i + 1);
				two.second = max(two.second, j + 1);
			}
		}
	}
	answer.push_back(one.first);
	answer.push_back(one.second);
	answer.push_back(two.first);
	answer.push_back(two.second);
	return answer;
}