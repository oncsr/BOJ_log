# [31841. Nogcd](https://www.acmicpc.net/problem/31841)

## 문제
Boss, if $N≤30\, 000$, you should try to optimise the $N^2$ solution. 
(Friedrich Nietzsche)




Let $G$ be a undirected connected graph with $N$ nodes and $M$ edges. Label each of the $M$ edges with a 
distinct
 integer from $1$ to $M$. For each node with degree greater than $1$, the greatest common divisor of its incident edges' labels should be $1$.

## 예제 입력 1
```
5 6
1 2
2 3
1 3
4 1
3 4
3 5
```

## 예제 출력 1
```
1 2 2
1 4 1
1 3 3
3 2 5
3 4 4
3 5 6
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 1 | C++17 / 수정 | 14836 KB | 144 ms | 529 B | 1년 전 |
