# [28055. Monochrome Tree](https://www.acmicpc.net/problem/28055)

## 문제
A monochrome tree is a tree in which each vertex is colored either white or black. The score of a monochrome tree is equal to the number of unordered vertex pairs $(u, v)$ such that:




Both vertices $u$ and $v$ are colored black.


$u$ is an ancestor of $v$, or $v$ is an ancestor of $u$.




You are given a rooted tree of $n$ vertices whose root vertex is $1$. 


For each $k$ from $0$ to $n$ (inclusive), you may color the given tree in such a way that there are exactly $k$ black vertices and $n - k$ white vertices. Among all the possible colorings, we denote the lowest score of a coloring as $c_k$.


Find $c_k$ for all $0 \leq k \leq n$.

## 예제 입력 1
```
3
1
1
```

## 예제 출력 1
```
0 0 0 2
```

## 예제 입력 2
```
3
3
1
```

## 예제 출력 2
```
0 0 1 3
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 2 | C++17 / 수정 | 30112 KB | 148 ms | 734 B | 1년 전 |
