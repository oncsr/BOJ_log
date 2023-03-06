#include <string>
#include <vector>

using namespace std;

int string_to_int(string a) {
    int num = 0;
    num += ((a[0] - '0') * 600);
    num += ((a[1] - '0') * 60);
    num += ((a[3] - '0') * 10);
    num += (a[4] - '0');
    return num;
}

int solution(vector<vector<string>> book_time) {

    int arr[1440]{}, mx = 0;
    
    for (vector<string> now : book_time) {
        int start = string_to_int(now[0]);
        int end = string_to_int(now[1]);
        end = min(end + 10, 1440);
        for (int i = start; i < end; i++) {
            arr[i]++;
            mx = max(arr[i], mx);
        }
    }

    return mx;
}