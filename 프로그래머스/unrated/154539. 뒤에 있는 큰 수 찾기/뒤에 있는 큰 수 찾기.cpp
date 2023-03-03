#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1);
    stack<pair<int, int> > S;
    for (int i = 0; i < numbers.size(); i++) {
        if (S.empty())   S.push({ numbers[i], i });
        else {
            if (numbers[i] > S.top().first) {
                while (!S.empty() && numbers[i] > S.top().first) {
                    answer[S.top().second] = numbers[i];
                    S.pop();
                }
            }
            S.push({ numbers[i], i });
        }
    }
    return answer;
}