# [32611. Dungeon of Darkness](https://www.acmicpc.net/problem/32611)

## 문제
In his great quest to rescue princess Zelda and protect the kingdom of Hyrule from the clutches of the evil Ganondorf, you, the hero, have arrived in the Lost Woods to rescue an ancient sage. The spirits of the woods have decided to test your wits in a magic-infused dungeon. The dungeon consists of $n$ doors connecting two distinct rooms, each door marked by a glowing symbol on both sides (to simplify, each symbol is a number from $1$ to $n$). Each room is shrouded in complete darkness, making you unable to see anything other than the symbols. You enter the dungeon through a magic door that disappears upon entry, and the sage waits for you after door $n$.


At the beginning of your quest, as well as every time you pass through a door, you see the symbols of all the doors that lead to and from the room which you are in. You also need to be quick of course, as the forces of Ganondorf do not wait. Going through doors a total of over $5 \cdot n$ times will be too slow and will cause Hyrule to fall to ruin!

## 예제 입력 1
```
3
2
1 2

1
1

2
1 2

2
2 3
```

## 예제 출력 1
```
1


1


2


3
```

## 예제 입력 2
```
5
3
1 2 3

2
1 3

3
1 2 3

3
2 4 5

1
4

3
2 4 5
```

## 예제 출력 2
```
1


3


2


4


4


5
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 2 | C++17 / 수정 | 13988 KB | 56 ms | 438 B | 1년 전 |
