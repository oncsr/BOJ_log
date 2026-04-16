# [7639. Counting Pixels](https://www.acmicpc.net/problem/7639)

## 문제
Did you know that if you draw a circle that fills the screen on your 1080p high definition display, almost a million pixels are lit? That’s a lot of pixels! But do you know exactly how many pixels are lit? Let’s find out!


Assume that our display is set on a Cartesian grid where every pixel is a perfect unit square. For example, one pixel occupies the area of a square with corners (0, 0) and (1, 1). A circle can be drawn by specifying its center in grid coordinates and its radius. On our display, a pixel is lit if any part of is covered by the circle being drawn; pixels whose edge or corner are just touched by the circle, however, are not lit.




Your job is to compute the exact number of pixels that are lit when a circle with a given position and radius is drawn.

## 예제 입력 1
```
1 1 1
5 2 5
0 0 0
```

## 예제 출력 1
```
4
88
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Silver 1 | C++17 / 수정 | 2032 KB | 92 ms | 347 B | 1년 전 |
