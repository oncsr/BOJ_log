#include <string>
#include <vector>

using namespace std;
int sz[101]{}, par[101]{};
vector<vector<int> > V(101);

void dfs(int n, int p) {
    sz[n] = 1;
    par[n] = p;
    for (int i : V[n])
        if (i != p) {
            dfs(i, n);
            sz[n] += sz[i];
        }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 1000;
    for (vector<int> now : wires) {
        V[now[0]].push_back(now[1]);
        V[now[1]].push_back(now[0]);
    }
    dfs(1, 0);
    for (vector<int> now : wires) {
        if (par[now[0]] == now[1]) swap(now[0], now[1]);
        int a = sz[now[1]], b = n - a;
        answer = min(answer, abs(a - b));
    }

    return answer;
}