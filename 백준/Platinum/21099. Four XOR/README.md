# [21099. Four XOR](https://www.acmicpc.net/problem/21099)

## 문제
Given a sequence $A_{1...n}$ of distinct integers, you need to answer whether there exist four indices $x, y, z, w$ such that $1 \le x < y < z < w \le n$ and $A_x \oplus A_y \oplus A_z \oplus A_w = 0$.


Recall that $x \oplus y$ means the bitwise exclusive-or between $x$ and $y$, sometimes expressed as $x \mathrm{xor} y$.

## 예제 입력 1
```
5
1 2 3 4 5
```

## 예제 출력 1
```
Yes
```

## 예제 입력 2
```
5
1 2 4 8 16
```

## 예제 출력 2
```
No
```

## 예제 입력 3
```
5
1 3 4 8 9
```

## 예제 출력 3
```
No
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Platinum 4 | Java 11 / 수정 | 25064 KB | 264 ms | 1878 B | 8달 전 |
