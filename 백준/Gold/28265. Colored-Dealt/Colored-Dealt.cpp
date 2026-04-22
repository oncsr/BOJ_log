#include <string>
#include <algorithm>
#include "colored_dealt.h"
using namespace std;

string guess(int N)
{
    string Q = "";
    int len = N;
    while (len--)    Q += 'R';
    int F = design(Q), sco = F, now = 0;
    int g = N - 1;
    string ans = "";
    while (g > 0) {
        Q[g] = 'B';
        int p = design(Q);
        if (p - F == 0) ans += 'B', now += 3;
        if (p - F == 1) ans += 'G', now += 2;
        if (p - F == 2) ans += 'R', now += 1;
        F = p;
        g--;
    }
    if (sco - now == 3)  ans += 'B';
    if (sco - now == 2)  ans += 'G';
    if (sco - now == 1)  ans += 'R';
    reverse(ans.begin(), ans.end());
    return ans;
}
