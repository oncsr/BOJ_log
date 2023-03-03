#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int end = 0;
    for (int i : section) {
        if (i < end) continue;
        answer++;
        end = i + m;
    }
    return answer;
}