# [23655. Game on Tree](https://www.acmicpc.net/problem/23655)

## 문제
You are given an undirected rooted tree. Vertices are numbered with integers from $1$ to $n$. The root is vertex $1$.


Two players are playing a game on this tree. They make alternating moves.


The first player can mark one leaf on his move, and it will remain marked until the end of the game. A leaf of a rooted tree is a non-root vertex with only one neighbor. Initially, all leaves are unmarked.


The second player controls a chip. The chip is always located in some vertex. Initially, the chip is placed in vertex $1$, the root of the tree. On his move, the second player can put the chip in any vertex adjacent to the current one, or leave it in the current vertex.


The game ends when either all leaves are marked (the first player wins) or the chip is put into some unmarked leaf (the second player wins). Who will be the winner if both players play optimally?

## 예제 입력 1
```
2
1
```

## 예제 출력 1
```
FIRST
2
```

## 예제 입력 2
```
3
1 1
```

## 예제 출력 2
```
SECOND
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Platinum 3 | Java 11 / 수정 | 36744 KB | 364 ms | 1492 B | 1년 전 |
