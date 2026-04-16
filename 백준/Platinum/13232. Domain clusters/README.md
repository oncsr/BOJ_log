# [13232. Domain clusters](https://www.acmicpc.net/problem/13232)

## 문제
We are analyzing how the domains on the Internet connect to each other. A domain is the part of a URL that comes before the / character. Examples of domains are: twitter.com, aipo.computing.dcu.ieor google.com. A domain d1 is connected to a domain d2 if there is a link from d1 to d2 or if d1 is connected to a domain d3 and d3 is connected to d2. We consider that a domain is connected to itself. In the following structure of domains:






D1 is connected to D2, D3 (through D2), D4 and D5 (through D3).


D2 is connected to D3, D4 (through D3) and D5 (through D3).


D3 is connected to D2, D4 and D5.


D4 is not connected to any other domain.


D5 is connected to D2, D3 (through D2) and D4 (through D3).




We want to obtain the biggest subset of domains S where each domain in S is connected to all the other domains in S. In the example above we have the following subsets that meet this criteria:




D1: Connected to itself.


D2, D3, D5: We can arrive from D2 to D3 and D5, from D3 to D2 and D5 and from D5 to D2 and D3.


D4: Connected to itself.




Please, given the links of the Internet, compute the size of the biggest subset.

## 예제 입력 1
```
5
7
1 2
1 4
2 3
3 4
3 2
3 5
5 2
```

## 예제 출력 1
```
3
```

## 예제 입력 2
```
4
4
1 2
4 1
3 4
2 3
```

## 예제 출력 2
```
4
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Platinum 5 | C++17 / 수정 | 3932 KB | 20 ms | 846 B | 4달 전 |
