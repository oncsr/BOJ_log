#include <string>
#include <vector>

using namespace std;

long long solution(vector<int> sequence) {
    long long answer = 0;
    vector<long long> sequence3;
    vector<long long> sequence2;
    int n = sequence.size();
    for (int i = 0; i < n; i++) {
        if (i % 2) sequence3.push_back(sequence[i] * -1);
        else    sequence3.push_back(sequence[i]);
    }
    for (int i = 0; i < n; i++) {
        sequence2.push_back(sequence3[i] * -1);
    }

    for (int i = 0; i < sequence3.size(); i++) {
        if (!i) {
            answer = sequence3[i];
            continue;
        }
        sequence3[i] = (sequence3[i - 1] < 0 ? sequence3[i] : sequence3[i - 1] + sequence3[i]);
        answer = max(answer, sequence3[i]);
    }

    long long answer2 = 0;
    for (int i = 0; i < sequence2.size(); i++) {
        if (!i) {
            answer2 = sequence2[i];
            continue;
        }
        sequence2[i] = (sequence2[i - 1] < 0 ? sequence2[i] : sequence2[i - 1] + sequence2[i]);
        answer2 = max(answer2, sequence2[i]);
    }

    return max(answer, answer2);
}