# [18174. Crimson Sexy Jalapeños](https://www.acmicpc.net/problem/18174)

## 문제
The central piece of the Tainted chocolate game is a classic chocolate bar divided into square pieces by a rectangular grid of grooves parallel to the sides of the bar. Some squares have been tainted with extremely bitter substance that makes the tainted square (nearly) indigestible.


The game is played by two players who alternate in their moves. In a valid move, one player is obliged to consume some part of the chocolate bar. It is allowed to divide the current chocolate bar along one of the grooves into two smaller bars and then eat just one of them. The player who consumes a bar containing at least one tainted square loses the game.


The positions of all tainted squares are known at the beginning of the game. All other squares are safe to eat. Each player tries to avoid eating a bar of chocolate containing one or more tainted squares, because when this happens, the player involuntarily makes their personal most disgusted grimace becoming a source of great amusement not only to the other player but also to other people watching the game.


In this problem, you are to write a program to play the Tainted chocolate game. We neglect the part of the code which simulates players grimaces and chocolate consumption, and instead focus only on the winning moves.


A valid move is described by a directional string and a positive integer X. The directional string is one of the four strings “top”, “bottom”, “left”, or “right”. The description means that the bar is divided by the X-th groove, counted from that side of the currently remaining bar which is specified by the given directional string. The player then consumes the part on that side.

## 예제 입력 1
```
4 6 2
2 3
4 4

right 2

yuck!
```

## 예제 출력 1
```
top 1

left 2
```

## 예제 입력 2
```
3 5 1
2 3
left 1
left 1
right 1
yuck!
```

## 예제 출력 2
```
pass
right 1
top 1
bottom 1
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Platinum 3 | Java 11 / 수정 | 35448 KB | 4300 ms | 2714 B | 1년 전 |
