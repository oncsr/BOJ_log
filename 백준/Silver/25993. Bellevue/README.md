# [25993. Bellevue](https://www.acmicpc.net/problem/25993)

## 문제
As any photographer knows, any good sunset photo has the sun setting over the sea. In fact, the more sea that is visible in the photo, the prettier it is!


You are currently visiting the island Bellevue, and you would like to take a photo of either the sunrise to the east or the sunset to the west to submit it to Bellevue's Astonishing Photography Competition. By carefully studying the topographic maps, you managed to find the east-west profile of the island. Now you would like to know the maximal amount of sea that you could capture in a photo, measured as the viewing angle covered by water.


The profile of the island is given as a piecewise linear function consisting of $n-1$ segments between $n$ points. The island starts and ends at sea level. As an example, Figure B.1 shows the profile of the first sample case.


Note that the viewing angle of your lens is not large enough to capture the ocean to the east and west of the island in one shot. Also, the viewing angle of sea at sea level is $0$ degrees.




Figure B.1: The east-west profile of the island in the first sample case.

## 예제 입력 1
```
6
0 0
2 1
3 1
4 4
5 1
9 0
```

## 예제 출력 1
```
45
```

## 예제 입력 2
```
5
1 0
5 4
6 1
8 2
9 0
```

## 예제 출력 2
```
63.4349488
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Silver 1 | C++17 / 수정 | 2864 KB | 20 ms | 823 B | 3년 전 |
