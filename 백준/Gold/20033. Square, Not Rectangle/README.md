# [20033. Square, Not Rectangle](https://www.acmicpc.net/problem/20033)

## 문제
A histogram is a polygon made by aligning $N$ adjacent rectangles that share a common base line. Each rectangle is called a bar. The $i$-th bar from the left has width 1 and height $H_i$.


Your goal is to find the area of the largest rectangle contained in the given histogram, such that one of the sides is parallel to the base line.




Figure 1. The histogram given in the example, with the largest rectangle shown on the right.


Actually, no, you have to find the largest 
square
. Since the area of a square is determined by its side length, you are required to output the 
side length
 instead of the area.




Figure 2. The histogram given in the example, with the largest 
square
 shown on the right.

## 예제 입력 1
```
6
3 4 4 4 4 3
```

## 예제 출력 1
```
4
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 4 | Java 11 / 수정 | 48768 KB | 448 ms | 1428 B | 1년 전 |
