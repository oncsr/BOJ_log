#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    int p1 = 0, p2 = 0;
    for (string i : goal) {
        if (p1 < cards1.size() && cards1[p1] == i) {
            p1++;
            continue;
        }
        if (p2 < cards2.size() && cards2[p2] == i) {
            p2++;
            continue;
        }
        return "No";
        
    }

    return "Yes";
}