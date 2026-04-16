# [24657. Edges, Colors and MST](https://www.acmicpc.net/problem/24657)

## 문제
There is an undirected simple connected graph $G$ with $N$ vertices and $M$ edges. The vertices of $G$ are numbered from 1 to $N$, and the edges are numbered from 1 to $M$. Edge $i$ connects vertices $u_i$ and $v_i$.


Given is a sequence $C = (c_1, c_2, \ldots, c_M)$ of length $M$, consisting of 
0
s and 
1
s. Edge $i$ is painted blue when $c_i=0$, and is painted red when $c_i=1$. The edges are colored in such a way that there are exactly $N-1$ red edges and they are forming a spanning tree of $G$.


Find the lexicographically smallest permutation $P = (p_1, p_2, \ldots, p_M)$ that satisfies the following condition: if, for each $i$, the weight of edge $i$ is $p_i$, then all the edges used in the minimal spanning tree of $G$ are red.


Note that the minimal spanning tree of $G$ is uniquely determined under those conditions.

## 예제 입력 1
```
4 5
1 2 0
2 3 1
3 4 1
2 4 0
1 3 1
```

## 예제 출력 1
```
3 1 4 5 2
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Platinum 1 | C++17 / 수정 | 22344 KB | 128 ms | 2247 B | 4달 전 |
