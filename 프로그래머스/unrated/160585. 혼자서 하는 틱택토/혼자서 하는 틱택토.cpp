#include <string>
#include <vector>

using namespace std;

int solution(vector<string> board) {
    int answer = 1;
    int a = 0, b = 0;
    for (string i : board) {
        for (char j : i) {
            if (j == '.')    continue;
            if (j == 'O')    a++;
            else    b++;
        }
    }
    if (a > b + 1 || b > a) answer = 0;
    int one_win = 0, two_win = 0;
    for (int i = 0; i < 3; i++) {
        int one = 0, two = 0;
        int oone = 0, ttwo = 0;
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 'O')  one++;
            if (board[i][j] == 'X')  two++;
            if (board[j][i] == 'O')  oone++;
            if (board[j][i] == 'X')  ttwo++;
        }
        if (one == 3 || oone == 3)    one_win = 1;
        if (two == 3 || ttwo == 3)   two_win = 1;
    }
    int one = 0, two = 0;
    int oone = 0, ttwo = 0;
    for (int i = 0; i < 3; i++) {
        if (board[i][i] == 'O')  one++;
        if (board[i][i] == 'X')  two++;
        if (board[i][2 - i] == 'O')    oone++;
        if (board[i][2 - i] == 'X')    ttwo++;
    }
    if (one == 3 || oone == 3)    one_win = 1;
    if (two == 3 || ttwo == 3)   two_win = 1;
    if (one_win && two_win)  answer = 0;
    else if (one_win && b >= a)  answer = 0;
    else if (two_win && a > b)   answer = 0;
    return answer;
}