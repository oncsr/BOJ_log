# [27395. Toll Roads](https://www.acmicpc.net/problem/27395)

## 문제
Your state has a number of cities, and the cities are connected by roads. Unfortunately, all of the roads are toll roads!


You now run the local chapter of AAA (American Automobile Association), and people are constantly asking you about the tolls. In particular, they've been asking about individual tolls on any single road on a path between two cities. Odd, but that's what they've been asking!


Given a description of the cities in your state and the roads that connect them, and a series of queries consisting of two separate cities, for each query determine two things:




First, the smallest value such that there is a route between the two cities where no road has a toll greater than that value.


Second, the number of cities reachable from your starting city using no road with a toll greater than that first value.

## 예제 입력 1
```
4 3 6
1 2 1
2 3 3
3 4 2
1 2
1 3
1 4
2 3
2 4
3 4
```

## 예제 출력 1
```
1 2
3 4
3 4
3 4
3 4
2 2
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Platinum 2 | C++17 / 수정 | 45452 KB | 804 ms | 2823 B | 1년 전 |
