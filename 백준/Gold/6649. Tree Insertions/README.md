# [6649. Tree Insertions](https://www.acmicpc.net/problem/6649)

## 문제
All modern banks employ information systems to process their data. The amount of data is enormous. Imagine all the transactions, payments, e-banking, web services, etc. Therefore, advanced data structures must be used to store the data and allow to access them very quickly.


A Binary Search Tree (BST) is one example of such a data structure It holds a collection of values with some comparison operation that provides linear ordering on these values.


BST consists of nodes, each of them contains one value and has at most two subnodes: left and right (BST is a binary tree). The left subtree always contains only values strictly less than the node value, the right subtree only values greater than or equal to the node value.


As a consequence, values may easily be looked up by traversing the tree recursively. We begin with the root node and compare its value with the value we are searching for. Depending on the result, we descend either into the left or into the right subtree, but we never need to walk through both.


If we want to insert values to an existing tree, the procedure is also simple. The first value (when the tree is empty) is always put as the root. If the tree already exists, we start with the root node and traverse the tree recursively, as in the case of searching. When the traversal leads us to a missing subnode, we create a new leaf node at that position and assign it the new value.


The figures below show the tree after subsequently adding the following sequence of numbers: 3, 4, 3, 5, 4, 1, and 2.




You may notice that different permutations of the same numbers will often result in the same BST. For example, the tree from the fifth figure above may be constructed by three different input sequences:




3, 4, 3, 5, 4


3, 4, 5, 4, 3


3, 4, 5, 3, 4




Interesting, isn’t it? Your task is to compute how many different permutations are there that will result into the same BST.

## 예제 입력 1
```
5
3 4 3 5 4
7
3 4 3 5 4 1 2
31
16 8 24 4 12 20 28 2 6 10 14 18 22 26 30 1 3 5 7 9 11 13 15 17 19 21 23 25 27 29 31
0
```

## 예제 출력 1
```
3
45
74836825861835980800000
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 4 | PyPy3 / 수정 | 111152 KB | 132 ms | 927 B | 1년 전 |
