# [15756. Disruption](https://www.acmicpc.net/problem/15756)

## 문제
Farmer John prides himself on running a well-connected farm. The farm is a collection of $N$ pastures ($2 \leq N \leq 50,000$), pairs of which are connected with $N-1$ bi-directional pathways, each having unit length. Farmer John notices that using an appropriate series of these pathways, it is possible to travel from any pasture to any other pasture.


Although FJ's farm is connected, he worries what might happen if one of the pathways gets blocked, as this would effectively partition his farm into two disjoint sets of pastures, where the cows could travel within each set but not between the sets. FJ therefore builds a set of $M$ additional bi-directional pathways ($1 \leq M \leq 50,000$), each with a positive integer length at most $10^9$. The cows still only use the original pathways for transit, unless one of these becomes blocked.


If one of the original pathways becomes blocked, the farm becomes partitioned into two disjoint pieces, and FJ will select from among his extra pathways a single replacement pathway that re-establishes connectivity between these two pieces, so the cows can once again travel from any pasture to any other pasture.


For each of the original pathways on the farm, help FJ select the shortest suitable replacement pathway.

## 예제 입력 1
```
6 3
1 2
1 3
4 1
4 5
6 5
2 3 7
3 6 8
6 4 5
```

## 예제 출력 1
```
7
7
8
5
5
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Platinum 1 | Java 11 / 수정 | 63140 KB | 728 ms | 2245 B | 11달 전 |
