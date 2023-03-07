#include <string>
#include <stack>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> S;
    for (char i : s) {
        if (S.empty())   S.push(i);
        else {
            if (i == '(')    S.push(i);
            else {
                if (S.top() == '(')  S.pop();
                else    S.push(i);
            }
        }
    }
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return S.empty();
}