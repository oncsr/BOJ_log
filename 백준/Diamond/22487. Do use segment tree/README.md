# [22487. Do use segment tree](https://www.acmicpc.net/problem/22487)

## 문제
Given a tree with 
n
 
(1 ≤ n ≤ 200,000)
 nodes and a list of 
q
 
(1 ≤ q ≤ 100,000)
 queries, process the queries in order and output a value for each output query. The given tree is connected and each node on the tree has a weight 
w
i
 
(-10,000 ≤ w
i
 ≤ 10,000)
.


Each query consists of a number 
t
i
 
(t
i
 = 1, 2)
, which indicates the type of the query , and three numbers 
a
i
, 
b
i
 and 
c
i
 
(1 ≤ a
i
, b
i
 ≤ n, -10,000 ≤ c
i
 ≤ 10,000)
. Depending on the query type, process one of the followings:






(
t
i
 = 1
: modification query) Change the weights of all nodes on the shortest path between 
a
i
 and 
b
i
 (both inclusive) to 
c
i
.






(
t
i
 = 2
: output query) First, create a list of weights on the shortest path between 
a
i
 and 
b
i
 (both inclusive) in order. After that, output the maximum sum of a non-empty continuous subsequence of the weights on the list. 
c
i
 is ignored for output queries.

## 예제 입력 1
```
3 4
1 2 3
1 2
2 3
2 1 3 0
1 2 2 -4
2 1 3 0
2 2 2 0
```

## 예제 출력 1
```
6
3
-4
```

## 예제 입력 2
```
7 5
-8 5 5 5 5 5 5
1 2
2 3
1 4
4 5
1 6
6 7
2 3 7 0
2 5 2 0
2 4 3 0
1 1 1 -1
2 3 7 0
```

## 예제 출력 2
```
12
10
10
19
```

## 예제 입력 3
```
21 30
10 0 -10 -8 5 -5 -4 -3 1 -2 8 -1 -7 2 7 6 -9 -6 3 4 9
10 3
3 2
3 12
12 4
4 13
4 9
10 21
21 1
1 11
11 14
1 15
10 6
6 17
6 16
6 5
5 18
5 19
10 7
10 8
8 20
1 1 21 -10
1 3 19 10
2 1 13 0
1 4 18 8
1 5 17 -5
2 16 7 0
1 6 16 5
1 7 15 4
2 4 20 0
1 8 14 3
1 9 13 -1
2 9 18 0
1 10 12 2
1 11 11 -8
2 21 15 0
1 12 10 1
1 13 9 7
2 6 14 0
1 14 8 -2
1 15 7 -7
2 10 2 0
1 16 6 -6
1 17 5 9
2 12 17 0
1 18 4 6
1 19 3 -3
2 11 8 0
1 20 2 -4
1 21 1 -9
2 5 19 0
```

## 예제 출력 3
```
20
9
29
27
10
12
1
18
-2
-3
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Diamond 3 | C++17 / 수정 | 50004 KB | 720 ms | 3900 B | 3년 전 |
