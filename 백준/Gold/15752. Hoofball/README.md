# [15752. Hoofball](https://www.acmicpc.net/problem/15752)

## 문제
In preparation for the upcoming hoofball tournament, Farmer John is drilling his $N$ cows (conveniently numbered $1\dots N$, where $1 \leq N \leq 100$) in passing the ball. The cows are all standing along a very long line on one side of the barn, with cow $i$ standing $x_i$ units away from the barn ($1 \leq x_i \leq 1000$). Each cow is standing at a distinct location.


At the beginning of the drill, Farmer John will pass several balls to different cows. When cow $i$ receives a ball, either from Farmer John or from another cow, she will pass the ball to the cow nearest her (and if multiple cows are the same distance from her, she will pass the ball to the cow farthest to the left among these). So that all cows get at least a little bit of practice passing, Farmer John wants to make sure that every cow will hold a ball at least once. Help him figure out the minimum number of balls he needs to distribute initially to ensure this can happen, assuming he hands the balls to an appropriate initial set of cows.

## 예제 입력 1
```
5
7 1 3 11 4
```

## 예제 출력 1
```
2
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 4 | C++17 / 수정 | 2024 KB | 0 ms | 1023 B | 2년 전 |
