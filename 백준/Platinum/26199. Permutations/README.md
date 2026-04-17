# [26199. Permutations](https://www.acmicpc.net/problem/26199)

## 문제
Let $[n]$ denote the set $\{1, 2, \ldots, n\}$. A 
permutation
 of order $n$ is a one-to-one mapping from the set $[n]$ to the set $[n]$. For example, let $\pi \colon [7] \to [7]$ be a concrete permutation of order $7$. We usually represent it with a table like this:


$\pi = \begin{pmatrix} 1 & 2 & 3 & 4 & 5 & 6 & 7 \\ 3 & 7 & 4 & 1 & 6 & 5 & 2\end{pmatrix}.$


This means that $\pi(1) = 3$, $\pi(2) = 7$, $\pi(3) = 4$ etc. Since the top row is always $1\ 2\ 3 \ldots n$, we usually omit it and write down the permutation in the 
one-line notation
:


$\pi = 3\ 7\ 4\ 1\ 6\ 5\ 2.$


The 
cycle notation
 is also very popular. We start with element $1$ and determine its image $\pi(1) = 3$. Next, we take the element $3$ and determine its image $\pi(3) = 4$. If we keep doing this, we sooner or later arrive back at the element $1$. Indeed, $\pi(4) = 1$. The permutation $\pi$ contains the cycle $(1\ 3\ 4)$. Then we take the smallest number that has not yet appeared in any cycle - in our case it is $2$ - and repeat the process. Eventually, we obtain to the following:


$\pi = (1\ 3\ 4)\ (2\ 7)\ (5\ 6).$


A permutation of order $n$ can also be represented by an 
inversion table
 $b_1\ b_2\ b_3 \ldots b_n$ ($0 \leq b_i \leq n-i$), where $b_i$ is the number of those elements that are greater than $i$ and appear to the left of $i$ in the one-line notation. In our concrete example, the inversion table is:


$3\ 5\ 0\ 1\ 2\ 1\ 0$.


It is known that every permutation can be written in a unique way by an inversion table and that every inversion table $b_1\ b_2\ b_3 \ldots b_n$ in which $0 \leq b_i \leq n-i$ holds for all $i \in [n]$, represents a valid permutation.


Write a program that will convert a inversion table to its corresponding cycle notation.

## 예제 입력 1
```
7
3 5 0 1 2 1 0
```

## 예제 출력 1
```
(1 3 4) (2 7) (5 6)
```

## 예제 입력 2
```
6
4 2 1 1 0 0
```

## 예제 출력 2
```
(1 5) (2 3) (4) (6)
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Platinum 5 | C++17 / 수정 | 10984 KB | 52 ms | 1283 B | 2년 전 |
