#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    sort(weights.begin(), weights.end());
    int temp = 0, s = 1;
    for (int i : weights) {
        if (i == temp)   answer += s, s++;
        else    s = 1;
        temp = i;
    }
    for (int i = 0; i < weights.size(); i++) {
        int num = weights[i];
        if (num % 3 == 0) {
            answer += (upper_bound(weights.begin() + i, weights.end(), num * 4 / 3) - lower_bound(weights.begin() + i, weights.end(), num * 4 / 3));
        }
        if (num % 2 == 0) {
            answer += (upper_bound(weights.begin() + i, weights.end(), num * 3 / 2) - lower_bound(weights.begin() + i, weights.end(), num * 3 / 2));
        }
        answer += (upper_bound(weights.begin() + i, weights.end(), num * 2) - lower_bound(weights.begin() + i, weights.end(), num * 2));
    }
    return answer;
}