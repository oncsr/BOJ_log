#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int left = 10, right = 11;
    int arr[12] = { 0,3,3,3,2,2,2,1,1,1,0,0 };
    int arr2[12] = { 1,0,1,2,0,1,2,0,1,2,0,2 };
    for (int i : numbers) {
        if (i == 1 || i == 4 || i == 7)  left = i, answer += 'L';
        else if (i == 3 || i == 6 || i == 9)  right = i, answer += 'R';
        else {
            int left_dist = abs(arr[left] - arr[i]) + abs(arr2[left] - arr2[i]);
            int right_dist = abs(arr[right] - arr[i]) + abs(arr2[right] - arr2[i]);
            if (left_dist < right_dist)  left = i, answer += 'L';
            else if (left_dist > right_dist) right = i, answer += 'R';
            else {
                if (hand == "left")  left = i, answer += 'L';
                else    right = i, answer += 'R';
            }
        }
    }
    return answer;
}