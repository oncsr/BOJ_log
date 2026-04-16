# [32493. PARENTHESES](https://www.acmicpc.net/problem/32493)

## 문제
Who doesn't love parentheses?


Sashka stumbled upon a bracket sequence $S=s_1 s_2 \dots s_{2N}$ of $2N$ parentheses, from which $N$ are opening parentheses and $N$ are closing parentheses. She defines the bracket sequence's clumsiness as the minimum number of required swaps of elements to turn it into a regular parentheses sequence. The regular parentheses sequences follow these rules:




The empty sequence is a regular parentheses sequence.


$S$ is a regular non-empty parentheses sequence iff two regular sequences $A$ and $B$ exist such that $S=
(
+A+
)
+B$, where $+$ denotes the operation concatenation of two sequences.




Sashka wants to know the clumsiness for $Q$ such sequences $T_1, T_2, \dots,T_Q$, where the $i$-th of them $T_i=s_{L_i} s_{L_i+1} \dots s_{R_i}$ consists of all the elements in $S$ from position $L_i$ to $R_i$ inclusive. 
It is guaranteed that every sequence $T_i$ consists of equal number of opening and closing parentheses.
 Write a program 
parentheses
, which answers the $Q$ questions.

## 예제 입력 1
```
3 1 1
)())((
1 6
```

## 예제 출력 1
```
1
```

## 예제 입력 2
```
5 10 1
()))(()(()
2 9
6 7
1 10
3 8
7 10
3 10
9 10
4 7
4 5
3 6
```

## 예제 출력 2
```
2
0
1
1
1
1
0
1
1
1
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Platinum 4 | C++17 / 수정 | 7680 KB | 132 ms | 794 B | 1년 전 |
