# [13896. Sky Tax](https://www.acmicpc.net/problem/13896)

## 문제
New Bangkok is a newly built province of Thailand that is floating in the sky. In order for the province to be able to float, each city is supported by a spaceship. Because all spaceships are moving in same direction and velocity, the structure of the province stays still.


Cities are connected by sky ways. A sky way is a floating road connects two cities of New Bangkok together, so a citizen can commute from a city to another city by sky ways. With well urban planning, it is guaranteed that one can commute from any city to all other cities. Also, from a city to another city, there is only one simple route, i.e., no skyway that is used twice.


Because it is new, the province changes its capital city rapidly. This province also has a strange rule, this is, a city A must handle tax from a city B if a route from B to the capital city must pass through A. So it could be that a city have to handle taxes of many cities.


In this problem, we provide that structure of New Bangkok, an initial capital city, and number of queries. For each query, we ask you to either (1) move the capital city of the province to city R. or (2) given a city X, tell us how many cities that X has to handle taxes.

## 예제 입력 1
```
2
5 5 1
1 5
3 4
3 5
2 1
1 1
1 2
0 5
1 5
1 3
1 5 1
1 1
1 1
0 1
1 1
1 1
```

## 예제 출력 1
```
Case #1:
5
1
5
2
Case #2:
1
1
1
1
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Platinum 3 | C++17 / 수정 | 20008 KB | 340 ms | 1829 B | 2년 전 |
