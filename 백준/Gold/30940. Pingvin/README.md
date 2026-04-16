# [30940. Pingvin](https://www.acmicpc.net/problem/30940)

## 문제
Zrakoplović the penguin wants to learn how to fly!


The space in which he will learn to fly can be imagined as a cube of dimensions $n \times n \times n$, divided into $n^3$ unit cubes. Each unit cube can be described with three coordinates $(x, y, z)$, where $x$, $y$ and $z$ are integers between $1$ and $n$. The coordinate $x$ denotes the distance from the left edge of the space, the coordinate $y$ denotes the distance from the front edge of the space, and the coordinate $z$ denotes the height.


Some of these unit cubes contain clouds, and some do not.


Zrakoplović is afraid of clouds, so he will learn to fly only where there are no clouds. He initially finds himself at a position $(x_s, y_s, z_s)$, such that $z_s = 1$ (i.e. at height $1$), and wants to get to position $(x_e, y_e, z_e)$.


At the moment, he is perfecting the skill of flying in directions that are parallel to one of the axes of space (i.e. in the direction of the $x$-axis, $y$-axis or $z$-axis), and in one wing flap he can cross at most one unit cube.


Before he decides to fly, Zrakoplović wants to know how many wing flaps he needs to get to the desired position. While he is preparing for the flight, help him answer that question.

## 예제 입력 1
```
2
1 1 1
1 1 2
00
10
01
00
```

## 예제 출력 1
```
1
```

## 예제 입력 2
```
3
2 3 1
1 1 1
000
010
000
111
111
111
111
111
111
```

## 예제 출력 2
```
3
```

## 예제 입력 3
```
3
2 1 1
3 2 2
000
010
110
010
001
001
101
110
000
```

## 예제 출력 3
```
3
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 5 | C++17 / 수정 | 4176 KB | 48 ms | 917 B | 1년 전 |
