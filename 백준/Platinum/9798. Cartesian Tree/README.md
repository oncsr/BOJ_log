# [9798. Cartesian Tree](https://www.acmicpc.net/problem/9798)

## 문제
Let us consider a special type of a binary search tree, called a cartesian tree. Recall that a binary search tree is a rooted ordered binary tree, such that for its every node x the following condition is satisfied: each node in its left subtree has the key less then the key of x, and each node in its right subtree has the key greater then the key of x.


That is, if we denote left subtree of the node x by L(x), its right subtree by R(x) and its key by k
x
 then for each node x we have




if y ∈ L(x) then k
y
 < k
x


if z ∈ R(x) then k
z
 > k
x




The binary search tree is called cartesian if its every node x in addition to the main key k
x
 also has an auxiliary key that we will denote by a
x
, and for these keys the heap condition is satisfied, that is




if y is the parent of x then a
y
 < a
x




Thus a cartesian tree is a binary rooted ordered tree, such that each of its nodes has a pair of two keys (k, a) and three conditions described are satisfied.


Given a set of pairs, construct a cartesian tree out of them, or detect that it is not possible.

## 예제 입력 1
```
7
5 4
2 2
3 9
0 5
1 3
6 6
4 11
```

## 예제 출력 1
```
YES
2 3 6
0 5 1
1 0 7
5 0 0
2 4 0
1 0 0
3 0 0
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Platinum 5 | C++17 / 수정 | 6440 KB | 36 ms | 1248 B | 1년 전 |
