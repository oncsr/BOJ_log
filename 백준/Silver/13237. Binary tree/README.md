# [13237. Binary tree](https://www.acmicpc.net/problem/13237)

## 문제
A binary tree is a mathematical structure made of nodes where each node can have up to two children nodes. One child node will be called left child and the other right child. ch If node B is a child node of A, then we say that A is the parent node of B. In a binary tree, there is only one node that has no parent and we call this node the root of the tree. We call the height of a node  N to the distance in nodes between the node N and the root node. The root node’s height is 0.


In this problem, you’ll have to compute the heights of every node of the tree. Each node will be identified by an integer from 1 to the number of nodes n.


Check the following tree:


The root of the tree is 1. The left child of 1 is 2, the right child of 1 is 3.


The nodes 4, 5, 6 and 7 do not have any child.


The heights of the nodes are:




Node 1: 0


Nodes 2 and 3: 1


Nodes 4, 5, 6 and 7: 2




The following tree is a bit different:


Node 1 is still the root and has 2 and 3 as left and right children but 3 only have right child. On the contrary, node 4 only has left child (5).


The heights:




Node 1: 0


Nodes 2 and 3: 1


Node 4: 2


Node 5: 3

## 예제 입력 1
```
7
-1
1
1
2
2
3
3
```

## 예제 출력 1
```
0
1
1
2
2
2
2
```

## 예제 입력 2
```
5
-1
1
1
3
4
```

## 예제 출력 2
```
0
1
1
2
3
```

## 예제 입력 3
```
3
2
-1
2
```

## 예제 출력 3
```
1
0
1
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Silver 3 | Java 15 / 수정 | 15864 KB | 116 ms | 2185 B | 1달 전 |
