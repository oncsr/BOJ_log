#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
	
	int a = wallpaper.size();
	int b = wallpaper[0].size();
	int c = 0, d = 0;

	for (int i = 0; i < wallpaper.size(); i++) {
		for (int j = 0; j < wallpaper[i].size(); j++) {
			if (wallpaper[i][j] == '#') {
				a = min(a, i);
				b = min(b, j);
				c = max(c, i + 1);
				d = max(d, j + 1);
			}
		}
	}
	
	vector<int> answer = { a,b,c,d };
	return answer;
}