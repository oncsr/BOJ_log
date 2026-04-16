# [31046. Communications Satellite](https://www.acmicpc.net/problem/31046)

## 문제
The Johnson Space Center has hired you to design NASA’s new communications satellite! The satellite, consisting of a set of dish antennas held together with titanium beams, must meet NASA’s exacting specifications, but a lot of the design is up to you.


Specifically, the design can be represented by a set of circles of various radii (representing the dish antennas) and line segments (the beams) in the 2D plane. A valid satellite design must meet all of the following criteria:




The necessary size and location of each dish on the $xy$ plane was computed by NASA, and you are not allowed to reposition any of the dishes.


You may add any number of titanium beams to the design, connecting one point on the circumference of one dish antenna to another point on the circumference of a different dish. Treat each beam as a straight line segment (of negligible width).


Beams are not allowed to cross each other, or attach to each other. Beams are also not allowed to occlude (cover up) any part of the interior of any dish antenna.


Your final design must consist of a single connected structure.


Two dishes might exactly touch (in which case they are already connected to each other); but NASA guarantees that no two dish antennas overlap.




Titanium isn’t cheap these days, so you want to compute the cheapest possible compliant design: the one that 
minimizes the sum
 of the beam lengths.

## 예제 입력 1
```
4
3 4 3
0 0 2
4 -2 2
9 4 1
```

## 예제 출력 1
```
2.47213595
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 3 | C++17 / 수정 | 100472 KB | 408 ms | 937 B | 1년 전 |
