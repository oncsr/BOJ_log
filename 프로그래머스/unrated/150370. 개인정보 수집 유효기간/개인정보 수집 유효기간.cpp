#include <string>
#include <vector>

using namespace std;

vector<int> time_split(string date) {
    int year = 0, s = 1000;
    for (int i = 0; i < 4; i++) {
        year += (date[i] - '0') * s;
        s /= 10;
    }
    int month = (date[5] - '0') * 10 + (date[6] - '0');
    int day = (date[8] - '0') * 10 + (date[9] - '0');
    return { year, month, day };
}

vector<int> date_plus(vector<int> ymd, int p) {
    int y = ymd[0], m = ymd[1], d = ymd[2];
    d--;
    if (!d)  d = 28, m--;
    m += p;
    y += (m - 1) / 12;
    m %= 12;
    if (!m)  m = 12;
    return { y,m,d };
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    vector<int> real_today = time_split(today);
    int real_terms[26]{};
    for (string i : terms) {
        char t = i[0] - 'A';
        int period = 0, s = 1;
        for (int j = i.size() - 1; j >= 2; j--) {
            period += (i[j] - '0') * s;
            s *= 10;
        }
        real_terms[t] = period;
    }
    int id = 1;
    for (string i : privacies) {
        string parsed = "";
        char term = ' ';
        bool passed = false;
        for (char j : i) {
            if (j == ' ') {
                passed = true;
                continue;
            }
            if (passed)  term = j;
            else    parsed += j;
        }
        vector<int> ymd = date_plus(time_split(parsed), real_terms[term - 'A']);
        
        if (real_today[0] > ymd[0])  answer.push_back(id);
        else if (real_today[0] == ymd[0]) {
            if (real_today[1] > ymd[1])  answer.push_back(id);
            else if (real_today[1] == ymd[1]) {
                if (real_today[2] > ymd[2])  answer.push_back(id);
            }
        }

        id++;
    }

    return answer;
}