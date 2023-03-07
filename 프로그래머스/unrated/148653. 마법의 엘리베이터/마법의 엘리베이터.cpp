#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int answer = 0;
    int s = 10;
    while (storey > 0) {
        int p = storey % s;
        if (p > 5 * (s / 10))  answer += ((s - p) / (s / 10)), storey += (s - p);
        else if (p == 5 * (s / 10)) {
            if (storey % (s * 10) >= 5 * s)  storey += (s - p);
            else    storey -= p;
            answer += 5;
        }
        else    answer += (p / (s / 10)), storey -= p;
        s *= 10;
    }
    return answer;
}