# [35395. Snow](https://www.acmicpc.net/problem/35395)

## 문제
Since 1906, a cross-country ski race has been held in the lands of the Czech Crown, in the Krkonoše Mountains. In the eighth year of this championship, the initial conditions seemed favorable, and the racers set off wearing only light clothing. Unfortunately, the weather soon turned for the worse, and most of the competitors were forced to abandon the race. Only Jaroslav Hanč continued, but due to the increasingly dangerous conditions, his friend Václav Vrbata went out to find him. Tragically, neither of them managed to reach safety in time, and both lost their lives.


To prevent such dangers in the ninth year of the championship, a new system for weather estimation was introduced. As a result, we began measuring atmospheric conditions more precisely to better predict race conditions.


The currently observed snow in the atmosphere is a rectangular grid, with each tile containing snow or empty space, represented as '
*
' and '
.
' respectively. The snow tends to naturally fall downwards, unless there is ground or there is a pile of snow touching ground below it. A pile of snow consists of the snow flakes in one column that can no longer fall down. More precisely, if the snow flake is on the very last row or there are only other snow flakes (no empty space) below it, it stays put. Otherwise, it moves one position down.


At each important time of the race, we need to determine the total number of snow flakes in the piles that are touching the ground, and thus preventing unexpected difficulties.

## 예제 입력 1
```
5 4 3
****
.*..
*..*
...*
*.*.
0
2
5
```

## 예제 출력 1
```
2
7
10
```

## 예제 입력 2
```
4 5 5
*****
.*...
..*..
...*.
0
1
2
3
10
```

## 예제 출력 2
```
1
2
6
8
8
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Silver 4 | Java 15 / 수정 | 46156 KB | 676 ms | 2142 B | 1달 전 |
