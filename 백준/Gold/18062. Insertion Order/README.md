# [18062. Insertion Order](https://www.acmicpc.net/problem/18062)

## 문제
A friend of yours is currently taking a class on algorithms and data structures. Just last week he learned about binary search trees and the importance of using self-balancing trees in order to keep the tree height low and guarantee fast access to every node.


Recall that a binary search tree is a binary tree with each node storing a key, and the property that the key of each node is greater than all keys in the left subtree of that node and less than all keys in the right subtree. A new key is inserted into the tree by adding a new leaf node with that key in the only position such that the property is maintained, as seen in the figure below.




Figure I.1: Illustration of the first sample case.


To illustrate to him just how bad things can get without self-balancing, you want to show him that it is possible to build trees of nearly any height by carefully choosing an insertion order.


You are given two integers n and k and want to construct a binary search tree with n nodes of height k (the height of a tree is the maximal number of nodes on a path from the root to a leaf). To do so, you need to find a permutation of the integers from 1 to n such that, when they are inserted into an empty binary search tree in that order (without self-balancing), the resulting tree has height k.

## 예제 입력 1
```
7 4
```

## 예제 출력 1
```
3 6 7 1 4 2 5
```

## 예제 입력 2
```
8 3
```

## 예제 출력 2
```
impossible
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 1 | C++17 / 수정 | 2020 KB | 12 ms | 526 B | 1년 전 |
