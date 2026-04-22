# [18921. Cost Of Subtree](https://www.acmicpc.net/problem/18921)

## 문제
The valuable tree with $n$ vertices grows near Byteazar's house. Edge $i$ has cost $v_i$ assigned to it.


A subtree of the tree is defined as a non-empty 
connected
 subset of its edges.


The 
cost
 of a subtree is defined as the number of edges in the subtree multiplied by the 
lowest
 value of $v_i$ in it.


Byteazar wants to make some money by selling subtrees, so he wants to know the maximum cost of a subtree of his tree.

## 예제 입력 1
```
10
6 4 8
5 6 7
2 3 5
3 1 2
2 7 3
9 7 4
8 2 6
8 10 7
6 2 4
```

## 예제 출력 1
```
24
```

## 예제 입력 2
```
6
1 3 12
5 3 4
3 4 2
2 4 5
6 2 6
```

## 예제 출력 2
```
12
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 1 | C++17 / 수정 | 6396 KB | 48 ms | 967 B | 2년 전 |
