# [16100. Andrew’s Amazing Architecture](https://www.acmicpc.net/problem/16100)

## 문제
Aaron has a large supply of blocks and has challenged Andrew to build a structure out of them. All of the blocks are k × 1 × 1 for various values of k. The structure must be made up of n nonempty columns lined up in a sequence such that all blocks in column i have dimensions h
i
 × 1 × 1, and have a 1 × 1 face that is parallel to the ground. Moreover, the structure must be a pyramid. A pyramid must contain an apex column such that for each column j to the left of the apex, the height of column j is no more than the height of column j + 1 and for each column k to the right of the apex, the height of column k is no more than the height of column k −1. For example, the left structure in Figure A.1 is not a pyramid since it does not have an apex column, while the right structure is a pyramid because the third column from the left is an apex column (as is the fourth column from the left).




Figure A.1: (left) An example that is not a pyramid. (right) An example of a pyramid. In both cases, n = 8 with blocks of size 6, 8, 4, 5, 6, 4, 2, 3 in the columns from left to right. This sequence is given in Sample Input 3.


Of course, just building a pyramid is easy, so Aaron has asked Andrew to find the pyramid with the smallest volume given a sequence of block sizes to use. Help Andrew by determining the smallest volume possible. You may assume that there is an unlimited supply of blocks of each size.

## 예제 입력 1
```
1
1337
```

## 예제 출력 1
```
1337
```

## 예제 입력 2
```
3
99 15 11
```

## 예제 출력 2
```
125
```

## 예제 입력 3
```
8
6 8 4 5 6 4 2 3
```

## 예제 출력 3
```
49
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 2 | C++17 / 수정 | 5024 KB | 24 ms | 703 B | 2년 전 |
