# [9715. Surface Area](https://www.acmicpc.net/problem/9715)

## 문제
The solid in the picture below is made up of 1x1x1 cubes in a 3D grid. In this problem, we'll limit ourselves to solids that are made up of columns rooted on the ground (a column consists of one or several 1x1x1 cubes stacked on top of each other). Such solids can be described as a matrix of digits, where each digit corresponds to the height of a column in the 2D grid that makes up the ground. A zero means there is no column at all in that position.




The corresponding matrix for the above solid will be  



4231
2101
0001


The volume of such a solid is simple enough to calculate, but what we're interested here in the total surface area including the floor (that is, the number of 1x1 "squares" non hidden on the outer surface). You are given the information of the solid as a matrix. Your task is to compute the surface area of the given solid. You can assume that the solid is always connected, i.e the columns will be attached to each other in the four cardinal directions.

## 예제 입력 1
```
4
1 2
11
3 4
4231
2101
0001
3 3
111
101
111
1 1
5
```

## 예제 출력 1
```
10
54
32
22
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Silver 2 | C++17 / 수정 | 2024 KB | 0 ms | 609 B | 1년 전 |
