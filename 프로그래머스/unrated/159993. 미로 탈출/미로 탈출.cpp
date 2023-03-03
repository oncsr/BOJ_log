#include <string>
#include <vector>
#include <queue>

using namespace std;
using ii = pair<int, int>;
struct iii { ii pos; int t; };
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };

int solution(vector<string> maps) {
    int answer = 0;
    int visit[100][100]{};
    queue<iii> Q;
    ii start, end, L;
    int N = maps.size(), M = maps[0].size();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (maps[i][j] == 'S')   start = { i,j };
            if (maps[i][j] == 'E')   end = { i,j };
            if (maps[i][j] == 'L')   L = { i,j };
        }
    }

    Q.push({ start, 0 });
    visit[start.first][start.second]++;
    while (!Q.empty()) {
        ii now = Q.front().pos;
        int time = Q.front().t;
        Q.pop();
        if (now == L) {
            answer = time;
            break;
        }
        for (int i = 0; i < 4; i++) {
            int x = now.first + dir[i][0];
            int y = now.second + dir[i][1];
            if (x >= 0 && x < N && y >= 0 && y < M && !visit[x][y] && maps[x][y] != 'X') {
                visit[x][y]++;
                Q.push({ {x,y},time + 1 });
            }
        }
    }

    if (!answer) return -1;
    int temp = answer;

    queue<iii> Q2;
    Q2.push({ L, answer });
    int visit2[100][100]{};
    visit2[L.first][L.second]++;
    while (!Q2.empty()) {
        ii now = Q2.front().pos;
        int time = Q2.front().t;
        Q2.pop();
        if (now == end) {
            answer = time;
            break;
        }
        for (int i = 0; i < 4; i++) {
            int x = now.first + dir[i][0];
            int y = now.second + dir[i][1];
            if (x >= 0 && x < N && y >= 0 && y < M && !visit2[x][y] && maps[x][y] != 'X') {
                visit2[x][y]++;
                Q2.push({ {x,y},time + 1 });
            }
        }
    }

    if (answer == temp)  return -1;

    return answer;
}