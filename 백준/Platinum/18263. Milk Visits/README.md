# [18263. Milk Visits](https://www.acmicpc.net/problem/18263)

## 문제
Farmer John is planning to build $N$ ($1 \leq N \leq 10^5$) farms that will be connected by $N-1$ roads, forming a tree (i.e., all farms are reachable from each-other, and there are no cycles). Each farm contains a cow with an integer type $T_i$ between $1$ and $N$ inclusive.


Farmer John's $M$ friends ($1 \leq M \leq 10^5$) often come to visit him. During a visit with friend $i$, Farmer John will walk with his friend along the unique path of roads from farm $A_i$ to farm $B_i$ (it may be the case that $A_i = B_i$). Additionally, they can try some milk from any cow along the path they walk. Since most of Farmer John's friends are also farmers, they have very strong preferences regarding milk. Each of his friends will only drink milk from a certain type of cow. Any of Farmer John's friends will only be happy if they can drink their preferred type of milk during their visit.


Please determine whether each friend will be happy after visiting.

## 예제 입력 1
```
5 5
1 1 2 1 2
1 2
2 3
2 4
1 5
1 4 1
1 4 2
1 3 2
1 3 1
5 5 1
```

## 예제 출력 1
```
10110
```

## 예제 입력 2
```
6 4
1 2 3 3 3 3
1 2
2 3
3 4
2 5
5 6
4 6 1
4 6 2
4 6 3
4 6 4
```

## 예제 출력 2
```
0110
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Platinum 1 | C++17 / 수정 | 23600 KB | 292 ms | 2351 B | 2년 전 |
