# [16455. K번째 수 찾는 함수](https://www.acmicpc.net/problem/16455)

## 문제
크기가 
N
인 수열 
A
1
, 
A
2
, ..., 
A
N
이 주어진다. 
A
를 오름차순 정렬했을 때, 앞에서부터 
K
번째 있는 수를 리턴하는 함수를 작성하시오.


작성해야 하는 함수는 다음과 같다. 
N
은 
n
, 
A
는 
a
, 
K
는 
k
로 주어진다.




C, C11, C (Clang), C11 (Clang): 
int kth(int *a, int n, int k);


C++, C++11, C++14, C++17, C++ (Clang), C++11 (Clang), C++14 (Clang), C++17 (Clang): 
int kth(std::vector<int> &a, int k);


Java, Java (OpenJDK): 
int kth(int[] a, int k);
 (클래스 이름: Test)


PyPy2, PyPy3: 
def kth(a: list, k : int) -> int


Go: 
kth(a []int, k int) int

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 1 | C++17 / 수정 | 93432 KB | 164 ms | 741 B | 3년 전 |
