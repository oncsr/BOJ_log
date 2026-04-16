# [15060. Imperial roads](https://www.acmicpc.net/problem/15060)

## 문제
The roads of Cubiconia are in a dire state, after years of neglect and lack of maintenance. Each road connects two different cities A and B and can be traveled in both ways (from A to B or from B to A). There is at most one road between each pair of cities, and using the existing roads it is possible to travel between any pair of cities. The new emperor of Cubiconia has just raised the taxes (again!), but promised to repair at least some of the roads, guaranteeing that Cubiconians will be able to travel between any pair of cities using only restored roads.


The Department of Public Works have calculated the cost of repairing each individual road. Now they want to calculate the minimum cost for repairing a set of roads so that the emperor’s promise is made true. This is not easy because the emperor wants the set of repaired roads to include one particular road, but he has not yet decided which particular road to include: could be the one that connects the city where his castle is to the city where his daughter’s royal residence is, or the road that connects the city where his summer palace is to the only city by the seaside, or. . . Fearing the emperor will take too long to decide, the engineers want your help.


Given the description of the roads in Cubiconia, with their respective repairing costs, you must write a program to answer a set of queries. For each query you will be given one specific road that should be repaired, and must determine the minimum cost for repairing a set of roads (including the given specific road) so that Cubiconians will be able to travel between any pair of cities using only restored roads.

## 예제 입력 1
```
3 3
1 2 10
2 3 5
1 3 7
3
2 3
1 2
1 3
```

## 예제 출력 1
```
12
15
12
```

## 예제 입력 2
```
4 4
1 2 1
2 4 1
2 3 100
1 4 50
1
1 4
```

## 예제 출력 2
```
151
```

## 예제 입력 3
```
5 7
1 2 8
1 3 10
2 4 5
2 3 12
4 5 4
3 5 14
1 5 20
3
2 3
1 5
3 5
```

## 예제 출력 3
```
29
39
31
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Platinum 1 | Java 11 / 수정 | 208508 KB | 2504 ms | 3180 B | 5달 전 |
