# [24618. Robot Instructions](https://www.acmicpc.net/problem/24618)

## 문제
Bessie is learning how to control a robot she has recently received as a gift.


The robot begins at point $(0, 0)$ on the coordinate plane and Bessie wants the robot to end at point $(x_g, y_g)$. Bessie initially has a list of $N$ ($1\le N\le 40$) instructions to give to the robot, the $i$-th of which will move the robot $x_i$ units right and $y_i$ units up (or left or down when $x_i$ and $y_i$ are negative, respectively).


For each $K$ from $1$ to $N$, help Bessie count the number of ways she can select $K$ instructions from the original $N$ such that after the $K$ instructions are executed, the robot will end at point $(x_g, y_g)$.

## 예제 입력 1
```
7
5 10
-2 0
3 0
4 0
5 0
0 10
0 -10
0 10
```

## 예제 출력 1
```
0
2
0
3
0
1
0
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Platinum 4 | C++17 / 수정 | 52004 KB | 3396 ms | 1144 B | 2년 전 |
