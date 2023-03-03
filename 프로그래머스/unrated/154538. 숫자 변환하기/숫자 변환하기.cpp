#include <string>
#include <vector>

using namespace std;

int solution(int x, int y, int n) {
    vector<int> d(1000001, -1);
    d[x] = 0;
    for (int i = x; i < y; i++) {
        if (d[i] == -1)  continue;
        if (i + n <= y) {
            if (d[i + n] == -1) d[i + n] = d[i] + 1;
            else    d[i + n] = min(d[i + n], d[i] + 1);
        }
        if (i * 2 <= y) {
            if (d[i * 2] == -1) d[i * 2] = d[i] + 1;
            else    d[i * 2] = min(d[i * 2], d[i] + 1);
        }
        if (i * 3 <= y) {
            if (d[i * 3] == -1) d[i * 3] = d[i] + 1;
            else    d[i * 3] = min(d[i * 3], d[i] + 1);
        }
    }
    return d[y];
}