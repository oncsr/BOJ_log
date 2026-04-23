# [23247. Ten](https://www.acmicpc.net/problem/23247)

## 문제
A real estate company IC is managing a rectangular section of land. The section is divided into $mn$ segments in $m \times n$ matrix shape, where the number of rows and that of columns are $m$ and $n$, respectively. Each segment has its own price as a positive integer. IC wants to sell a rectangular subsection of the land, but the price of the subsection should be ten. The price of a subsection is simply the sum of the prices of the segments in the subsection. Since there can be several such subsections, IC wants to identify the number of candidate subsections to sell. Write a program to help IC, counting the number of candidate subsections of the land.


For example, the prices of segments of the land having $5 \times 7$ segments are given as follows:




We can find four candidate subsections to sell marked by rectangles: the first one consists of four segments in the first and the second rows spanning over from the second to the third columns, the second, six segments in the second and the third rows spanning over from the third to the fifth columns, the third, two segments in the first row spanning over from the fifth to the sixth columns, and the fourth, three segments in the seventh column spanning over from the third to the fifth rows. Therefore, your program should report four for the above input.

## 예제 입력 1
```
3 5
3 1 2 1 4
4 5 2 2 2
4 7 1 1 2
```

## 예제 출력 1
```
2
```

## 예제 입력 2
```
4 6
3 1 2 1 4 6
4 5 2 2 2 7
4 7 1 1 1 9
4 3 3 3 7 2
```

## 예제 출력 2
```
8
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Silver 1 | C++17 / 수정 | 2252 KB | 140 ms | 670 B | 3년 전 |
