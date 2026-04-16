# [27075. Secret Milk Pipes](https://www.acmicpc.net/problem/27075)

## 문제
Farmer John wants to connect his water distribution system cheaply, but he doesn't want his rival, Farmer Snidely, to be able to predict the actual routes he chooses.  FJ knows that this kind of problem usually asks for the cheapest way to connect water pipes, so he decides to avoid that and use the second cheapest way instead.


Given a list of all the bidirectional pipes that might connect a set of W (3 ≤ W ≤ 2000) water stations (any one of which can be made into a well) along with the costs for no more than P (P ≤ 20,000) pipes, find the second cheapest way to distribute water.  No pipe connects a station to itself; no two pipes connect the same pair of stations.


It is guaranteed that there is only one cheapest way to distribute the water and that there are at least two ways to distribute the water.  All costs are positive integers that fit into a signed 16-bit entity.  A water station is identified by its ID number, which is an integer in the range 1..W.

## 예제 입력 1
```
5 7
1 2 3
2 3 4
1 4 7
2 4 11
2 5 9
5 4 5
3 5 8
```

## 예제 출력 1
```
20
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 2 | Java 11 / 수정 | 306360 KB | 1416 ms | 2327 B | 1년 전 |
