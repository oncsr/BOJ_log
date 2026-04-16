# [23594. Vasya's graph](https://www.acmicpc.net/problem/23594)

## 문제
Vasya has got a graph. The graph has $N$ nodes, but it's got no eges yet. Vasya cares a lot about the future graph structure: he knows $K$ pairs of nodes {$u_j$, $v_j$}, such that if there is a path between these nodes in the graph, the 
irredeemable
 will happen to the graph. Vasya must prevent it at all costs.


Vasya has made a list of $M$ 
unoriented
 edges. Vasya will examine the edges in the preset order and he will surely put them into the graph, if possible. If adding another edge will cause the 
irredeemable
, Vasya will simply discard such an edge. Your task is to find out which edges are good for the graph and which ones must end up in the trash.

## 예제 입력 1
```
3 1 3
1 2
1 2
2 3
1 3
```

## 예제 출력 1
```
1
2
```

## 예제 입력 2
```
5 2 6
1 2
2 3
1 3
2 4
3 4
1 4
4 5
1 5
```

## 예제 출력 2
```
3
1 2 5
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Platinum 1 | C++17 / 수정 | 23144 KB | 340 ms | 1128 B | 1년 전 |
