#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer(s.size());
    vector<int> arr(26, -1);
    for (int i = 0; i < s.size(); i++) {
        if (arr[s[i] - 'a'] == -1) answer[i] = -1;
        else    answer[i] = i - arr[s[i] - 'a'];
        arr[s[i] - 'a'] = i;
    }
    return answer;
}