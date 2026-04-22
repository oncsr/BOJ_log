# [28052. Maze in Bolt](https://www.acmicpc.net/problem/28052)

## 문제
Usain has an online store specializing in selling 3D puzzles made by 3D printers. One of the best-selling puzzles these days is the Maze in Bolt. This puzzle is composed of two parts: a screw-shaped piece with an embossed labyrinth engraved on it, and a nut. The inner part of the nut may contain tips. These tips make the nut slide only through the corridors of the labyrinth.


Initially, the two parts of the puzzle are separated. The challenge is to slide the nut all the way through the maze until it reaches the head of the bolt. The nut can be moved clockwise, counterclockwise, down (towards the head of the bolt), and up (away from the head). Each of these movements is only possible when every tip in the inner part of the nut is not prevented from sliding to the new position due to some wall of the maze. Besides the mentioned movements, another one is allowed: when the bolt and the nut are separated, the nut can be flipped. The illustration below shows both parts of the puzzle as well as all the allowed moves.








 










(a) Screw-shaped piece


(b) Nut piece


(c) Movements of the nut








A customer placed an order for a large quantity of the Maze in Bolt. Each puzzle is designed by Usain himself in a random and unique way but, due to the size of the order and the tight deadline, he believes he will not be able to check whether the created puzzles have a solution or not. Usain asked for your help in devising an algorithm that quickly checks any given pair of nut and bolt. For doing so, the inner part of the nut will be modeled as a binary circular string. Regarding the bolt, each row of the maze will be modeled the same way.

## 예제 입력 1
```
8 13
0110010000000
1100101110100
1001101000100
1100101110100
1000100010000
1010111011001
0000001010000
1001101111101
0001001100100
```

## 예제 출력 1
```
Y
```

## 예제 입력 2
```
1 3
100
101
```

## 예제 출력 2
```
Y
```

## 예제 입력 3
```
2 3
100
101
010
```

## 예제 출력 3
```
N
```

## 예제 입력 4
```
4 6
001000
011111
010001
010100
110111
```

## 예제 출력 4
```
Y
```

## 예제 입력 5
```
1 6
001011
001011
```

## 예제 출력 5
```
Y
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 2 | C++17 / 수정 | 3352 KB | 80 ms | 1633 B | 2년 전 |
