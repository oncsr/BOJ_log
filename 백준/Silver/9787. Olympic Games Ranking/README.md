# [9787. Olympic Games Ranking](https://www.acmicpc.net/problem/9787)

## 문제
The Olympic Games is the most well-known sporting event in the world. The ranking of participating nations is done by sorting their medals. Firstly, the nations are sorted by the number of gold medals that their athletes won. Secondly, if the number of gold medals is equal, the number of silver medals is taken into consideration and then the number of bronze medals. If nations are still tied, equal ranking is given and they are listed alphabetically by the country code. The next rank will skip the equal rank(s).


You have to write a program for generating the Olympic Games medal ranking from an unordered medal list.

## 예제 입력 1
```
THA 2 2 0
MAS 0 1 0
CHN 51 21 28
NED 7 5 15
POL 3 6 1
VEN 0 0 1
USA 36 38 36
MGL 2 2 0
EGY 0 0 1
```

## 예제 출력 1
```
1 CHN 51 21 28 100
2 USA 36 38 36 110
3 NED 7 5 15 27
4 POL 3 6 1 10
5 MGL 2 2 0 4
5 THA 2 2 0 4
7 MAS 0 1 0 1
8 EGY 0 0 1 1
8 VEN 0 0 1 1
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Silver 4 | C++17 / 수정 | 2168 KB | 0 ms | 1219 B | 3년 전 |
