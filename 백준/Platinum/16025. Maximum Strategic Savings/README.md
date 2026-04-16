# [16025. Maximum Strategic Savings](https://www.acmicpc.net/problem/16025)

## 문제
A long time ago in a galaxy far, far away, there are N planets numbered from 1 to N. Each planet has M cities numbered from 1 to M. Let city f of planet e be denoted as (e, f).


There are N × P two-way flights in the galaxy. For every planet e (1 ≤ e ≤ N), there are P flights numbered from 1 to P. Flight i connects cities (e, a
i
) and (e, b
i
) and costs ci energy daily to maintain.


There are M × Q two-way portals in the galaxy. For all cities with number f (1 ≤ f ≤ M), there are Q portals numbered from 1 to Q. Portal j connects cities (x
j
, f) and (y
j
, f) and costs z
j
 energy daily to maintain.


It is possible to travel between any two cities in the galaxy using only flights and/or portals.


Hard times have fallen on the galaxy. It was decided that some flights and/or portals should be shut down to save as much energy as possible, but it should remain possible to travel between any two cities afterwards.


What is the maximum sum of energy that can be saved daily?

## 예제 입력 1
```
2 2 1 2
1 2 1
2 1 1
2 1 1
```

## 예제 출력 1
```
3
```

## 예제 입력 2
```
2 3 4 1
2 3 5
3 2 7
1 2 6
1 1 8
2 1 5
```

## 예제 출력 2
```
41
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Platinum 2 | Java 15 / 수정 | 85168 KB | 1044 ms | 2376 B | 23일 전 |
