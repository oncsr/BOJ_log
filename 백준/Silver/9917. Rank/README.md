# [9917. Rank](https://www.acmicpc.net/problem/9917)

## 문제
In a tournament of N players and K games, each game involves 2 players.  A player may play any number of games, but in each game his opponent must be a different person.  A player needs not play with everybody (it is even possible, though strange, that a player does not play any game at all!).  In a game, there is no draw – a player either wins or losses.


After all the games have been played, the players are ranked.  There are a few situations where ranking is not possible, but here we are interested only in one particular ituation where more than 2 players are involved in a ‘cyclic’ order.  One example is as follows: player A beats player B, player B beats player C, and player C in turns beats player A.  In this case, the relative ranking of these 3 players cannot be determined.


Note that a player may be involved in more than one cyclic ordering; when this happens, the player should be counted only once.


(Since we are only interested in players involved in cyclic ordering, those players whose ranking cannot be determined due to other reasons –  for instance, a player who did not play any game at all – should not be considered here.  See the examples.)


You are given a list of games and their results, and you are to find the total number of players whose ranking cannot be determined due to cyclic ordering.

## 예제 입력 1
```
10 12
1 8 2 1
1 2 5 0
10 7 1 2
6 9 6 9
3 4 3 1
9 5 3 1
8 2 6 8
4 9 3 0
4 1 5 2
6 10 3 5
3 5 1 9
6 7 9 8
```

## 예제 출력 1
```
7
```

## 예제 입력 2
```
5 3
1 3 9 7
5 1 9 2
3 5 2 0
```

## 예제 출력 2
```
3
```

## 예제 입력 3
```
5 6
1 2 2 1
1 5 2 1
1 3 2 1
5 2 0 5
5 3 1 8
2 4 4 2
```

## 예제 출력 3
```
0
```

## 예제 입력 4
```
10 5
2 4 0 2
2 6 5 3
8 2 8 2
6 4 6 2
8 6 0 2
```

## 예제 출력 4
```
4
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Silver 1 | C++17 / 수정 | 2020 KB | 0 ms | 781 B | 1년 전 |
