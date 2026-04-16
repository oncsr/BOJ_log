# [32589. Flag Rotation](https://www.acmicpc.net/problem/32589)

## 문제
A common pattern for country flags is three stripes. Some flags are really similar, and have exactly the same stripes in the same order, but the flag is rotated by $90$ degrees. Using a sequence of colours, we can make a flag on a square grid, covering each row with the colours in the sequence. Another way to make a similar flag (that is rotated by $90$ degrees), is by covering each column with the colours in the sequence.


In preparation for the Flags You Paint for Countries meeting, you notice a mistake for one of the flags: it should have been rotated counter-clockwise by $90$ degrees! The square canvas is already stuck to a wall using super glue, so you can not simply take it off and rotate it. Therefore, you want to know how much work it would be to repaint one flag to the other. In one second, you can repaint one of the $1 \times 1$ squares to any colour. What is the minimum number of seconds you need to repaint the flag? As an example, for the flag in the first sample input (shown in Figure F.1), $34$ squares need to be repainted.


 


Figure F.1: Two flags corresponding to the first sample input. Colour $1$ corresponds to yellow, $2$ to red, $3$ to white, and $1000$ to blue. When the first flag should be rotated counter-clockwise by $90$ degrees without actually rotating the canvas, $34$ squares need to be repainted.

## 예제 입력 1
```
7
1 2 2 3 1000 2 1
```

## 예제 출력 1
```
34
```

## 예제 입력 2
```
4
10 12 12 10
```

## 예제 출력 2
```
8
```

## 예제 입력 3
```
5
6 5 5 6 5
```

## 예제 출력 3
```
12
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Silver 3 | C++17 / 수정 | 14564 KB | 124 ms | 255 B | 1년 전 |
