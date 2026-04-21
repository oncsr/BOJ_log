# [9741. Interior Lattice Points](https://www.acmicpc.net/problem/9741)

## 문제
A lattice point is a point whose coordinates on a rectangular coordinate system are integers. An interior lattice point is a lattice point that is inside a given polygon and not on its boundary. For example, the drawing below shows a triangle having six interior lattice points.




Write a program that reads an input containing three pairs of coordinates (xA, yA), (xB, yB), (xC, yC), where each coordinate is an unsigned integer with a value less than or equal to 100. The numbers in the line are separated exactly by one space and are in the order xA yA xB yB xC yC. The coordinates describe three distinct (but possibly collinear) lattice points. If the given coordinates describe a triangle with non-zero area, then the program should display on the screen the number of interior lattice points of the triangle. Otherwise, the program should display on the screen the number zero. (If the three points are collinear, then there are no interior lattice points.)

## 예제 입력 1
```
4
0 0 100 0 100 100
0 0 98 100 100 100
0 0 99 100 100 100
0 0 99 99 100 100
```

## 예제 출력 1
```
4851
49
0
0
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 3 | C++17 / 수정 | 2020 KB | 0 ms | 914 B | 2년 전 |
