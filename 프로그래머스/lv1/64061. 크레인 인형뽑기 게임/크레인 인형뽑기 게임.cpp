#include <string>
#include <stack>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;

    int N = board.size();
    stack<int> S;
    for (int now : moves) {
        now--;
        int ch = 0;
        for (int i = 0; i < N; i++) {
            if (board[i][now]) {
                ch = board[i][now];
                board[i][now] = 0;
                break;
            }
        }
        if (ch) {
            if (S.empty())   S.push(ch);
            else {
                if (S.top() == ch) {
                    S.pop();
                    answer += 2;
                }
                else    S.push(ch);
            }
        }
    }

    return answer;
}