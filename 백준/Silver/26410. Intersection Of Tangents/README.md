# [26410. Intersection Of Tangents](https://www.acmicpc.net/problem/26410)

## 문제
In this problem polygons are assumed to have no self-touchings or self-intersections.


A 
tangent
 to a polygon is a straight 
line
 that contains at least one point on the boundary of the polygon, and none of its interior points.


You are given a polygon with integer vertex coordinates. The polygon is not necessarily convex. Find a point with integer coordinates such that there exist two tangents to this polygon which both pass through this point and intersect at 90$^{\circ}$. It is guaranteed that at least one solution exists. If there are multiple solutions, output any of them.

## 예제 입력 1
```
3
1 2
3 1
3 3
```

## 예제 출력 1
```
1 2
```

## 예제 입력 2
```
4
0 0
7 1
2 1
3 2
```

## 예제 출력 2
```
1 3
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Silver 3 | C++17 / 수정 | 2020 KB | 0 ms | 202 B | 3년 전 |
