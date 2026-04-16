# [11072. Football](https://www.acmicpc.net/problem/11072)

## 문제
I turned the TV on the other day and a football game (Rugby League) was being broadcast. The score was 26 to 17 and I wondered how the game had progressed and which ways the teams had scored and the order of those scoring plays to get to their current scores. After some quick back of the envelope calculations I worked out that there were 4 507 705 365 837 803 005 ways that the game could have progressed to get to the current score.


Each code of football has different ways of scoring. In soccer, the teams can only score one point at a time. In some codes different ways of scoring are worth the same number of points e.g. in Rugby Union a drop goal and a penalty goal are both worth 3 points but are different modes of scoring. In many games a team can score points for a particular play and can then attempt to score bonus points of differing values. For example, in American football (gridiron), a team can score a touchdown worth 6 points and can then attempt either a 1 point (kick) conversion or 2 point (pass or run) conversion. In this way a team could score a touchdown followed by an unsuccessful conversion for 6 points, or a touchdown followed by a successful conversion for 7 or 8 points depending on the option taken.


In football (soccer) there is only one way of scoring i.e. with a 1 point goal. A 1-1 draw can be achieved in two ways. The score could have progressed from 0-0 to 0-1 to 1-1 or from 0-0 to 1-0 to 1-1. This different ordering of team scoring also needs to be taken into consideration.


From the different ways points can be scored for a particular game, write a program to work out the number of ways, including different orders of plays, the teams could have reached their current scores. As the number of ways is likely to be large report the results modulo 1 000 000 009.

## 예제 입력 1
```
4 6
1 2 4:2
```

## 예제 출력 1
```
4 vs 6 can be achieved 3838 ways
```

## 예제 입력 2
```
26 17
1 2 3 6:1:2
```

## 예제 출력 2
```
26 vs 17 can be achieved 268455080 ways
```

## 예제 입력 3
```
1 0
1
```

## 예제 출력 3
```
1 vs 0 can be achieved 1 way
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 3 | PyPy3 / 수정 | 116040 KB | 388 ms | 737 B | 8달 전 |
