#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int s = 0, n = signs.size();
    for(int i=0;i<n;i++){
        s += absolutes[i] * (signs[i] ? 1 : -1);
    }
    return s;
}