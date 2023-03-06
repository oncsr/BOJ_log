#include <string>
#include <map>
#include <vector>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);

    map<string, int> M;
    for (int i = 0; i < id_list.size(); i++)
        M[id_list[i]] = i;

    vector<vector<int> > V(1001);
    int visit[1000][1000]{};
    for (int i = 0; i < report.size(); i++) {
        string user_id = "", reported_id = "";
        bool space = false;
        for (int j = 0; j < report[i].size(); j++) {
            if (report[i][j] == ' ') {
                space = true;
                continue;
            }
            if (!space) user_id += report[i][j];
            else    reported_id += report[i][j];
        }
        int user = M[user_id], reported = M[reported_id];
        if (!visit[reported][user]) {
            visit[reported][user]++;
            V[reported].push_back(user);
        }
    }

    for (int i = 0; i < id_list.size(); i++) {
        if (V[i].size() < k) continue;
        for (int j : V[i])
            answer[j]++;
    }

    return answer;
}