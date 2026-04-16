# [5998. Lights](https://www.acmicpc.net/problem/5998)

## 문제
Bessie and the cows were playing games in the barn, but the power was reset and the lights were all turned off. Help the cows get all the lights back on so they can resume their games.


The N (1 <= N <= 35) lights conveniently numbered 1..N and their switches are arranged in a complex network with M (1 <= M <= 595) clever connection between pairs of lights (see below).


Each light has a switch that, when toggled, causes that light -- and all of the lights that are connected to it -- to change their states (from on to off, or off to on).


Find the minimum number of switches that need to be toggled in order to turn all the lights back on.


It's guaranteed that there is at least one way to toggle the switches so all lights are back on.

## 예제 입력 1
```
5 6
1 2
1 3
4 2
3 4
2 5
5 3
```

## 예제 출력 1
```
3
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Platinum 5 | Java 15 / 수정 | 52708 KB | 304 ms | 2346 B | 3달 전 |
