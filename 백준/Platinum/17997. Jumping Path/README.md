# [17997. Jumping Path](https://www.acmicpc.net/problem/17997)

## 문제
You are given a rooted tree where each vertex is labeled with a non-negative integer.


Define a 
Jumping Path
 of vertices to be a sequence of vertices 
v
1
, 
v
2
, ..., 
v
k
 where 
v
i
 is an ancestor of 
v
j
 for all 
i
 < 
j
. Note that 
v
i
 is an ancestor of 
v
i
+1
, but not necessarily the parent of 
v
i
+1
 (hence the 
jumping part
 of a 
jumping path
).


Compute two quantities:




The length (number of vertices) of the longest 
jumping path
 where the labels of the vertices are nondecreasing.


The number of 
jumping paths
 of that length where the labels of the vertices are nondecreasing.

## 예제 입력 1
```
5
3
3
3
3
3
1
2
3
4
```

## 예제 출력 1
```
5 1
```

## 예제 입력 2
```
5
4
3
2
1
0
1
2
3
4
```

## 예제 출력 2
```
1 5
```

## 예제 입력 3
```
4
1
5
3
6
1
2
3
```

## 예제 출력 3
```
3 2
```

## 예제 입력 4
```
6
1
2
3
4
5
6
1
1
1
1
1
```

## 예제 출력 4
```
2 5
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Platinum 1 | C++17 / 수정 | 222304 KB | 2732 ms | 2059 B | 1년 전 |
