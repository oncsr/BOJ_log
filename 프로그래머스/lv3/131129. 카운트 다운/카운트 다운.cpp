#include <string>
#include <vector>

using namespace std;

vector<int> solution(int target) {
    vector<int> answer;
    pair<int, int> D[100100]{};
    D[0] = { 0,0 };
    for (int i = 0; i <= target; i++) {
        for (int j = i + 1; j < i + 21; j++) {
            if (!D[j].first) D[j] = { D[i].first + 1, D[i].second + 1 };
            else {
                if (D[i].first + 1 < D[j].first || (D[i].first + 1 == D[j].first && D[i].second + 1 >= D[j].second)) {
                    D[j] = { D[i].first + 1, D[i].second + 1 };
                }
            }
        }
        for (int j = i + 2; j < i + 42; j += 2) {
            if (!D[j].first) D[j] = { D[i].first + 1, D[i].second };
            else {
                if (D[i].first + 1 < D[j].first || (D[i].first + 1 == D[j].first && D[i].second >= D[j].second)) {
                    D[j] = { D[i].first + 1, D[i].second };
                }
            }
        }
        for (int j = i + 3; j < i + 63; j += 3) {
            if (!D[j].first) D[j] = { D[i].first + 1, D[i].second };
            else {
                if (D[i].first + 1 < D[j].first || (D[i].first + 1 == D[j].first && D[i].second >= D[j].second)) {
                    D[j] = { D[i].first + 1, D[i].second };
                }
            }
        }
        if (!D[i + 50].first)  D[i + 50] = { D[i].first + 1, D[i].second + 1 };
        else {
            if (D[i].first + 1 < D[i + 50].first || (D[i].first + 1 == D[i + 50].first && D[i].second + 1 >= D[i + 50].second)) {
                D[i + 50] = { D[i].first + 1, D[i].second + 1 };
            }
        }
    }
    answer.push_back(D[target].first);
    answer.push_back(D[target].second);
    return answer;
}