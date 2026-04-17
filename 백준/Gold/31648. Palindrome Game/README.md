# [31648. Palindrome Game](https://www.acmicpc.net/problem/31648)

## 문제
Bessie and Elsie are playing a game with a pile of stones that initially contains $S$ stones ($1\le S<10^{10^5}$). The two cows alternate turns, with Bessie going first. When it is a cow's turn, she must remove $x$ stones from the pile, where $x$ is any positive integer palindrome of the cow's choosing. If the pile is empty when a cow's turn starts, that cow loses.


Definition:
 A positive integer is a palindrome if it reads the same forward and backward; examples of palindromes include 1, 121, and 9009. Leading zeros are not allowed; e.g., 990 is *not* a palindrome.


There are $T$ ($1\le T\le 10$) independent test cases. For each test case, print who wins the game if both cows play optimally.

## 예제 입력 1
```
3
8
10
12
```

## 예제 출력 1
```
B
E
B
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 4 | C++17 / 수정 | 2488 KB | 4 ms | 201 B | 1년 전 |
