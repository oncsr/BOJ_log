# [Gold I] Insertion Order - 18062 

[문제 링크](https://www.acmicpc.net/problem/18062) 

### 성능 요약

메모리: 2020 KB, 시간: 12 ms

### 분류

해 구성하기, 트리

### 제출 일자

2024년 8월 21일 19:03:00

### 문제 설명

<p>A friend of yours is currently taking a class on algorithms and data structures. Just last week he learned about binary search trees and the importance of using self-balancing trees in order to keep the tree height low and guarantee fast access to every node.</p>

<p>Recall that a binary search tree is a binary tree with each node storing a key, and the property that the key of each node is greater than all keys in the left subtree of that node and less than all keys in the right subtree. A new key is inserted into the tree by adding a new leaf node with that key in the only position such that the property is maintained, as seen in the figure below.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/11b9f022-0079-4615-a91b-2b29b4e39c7b/-/preview/" style="width: 625px; height: 232px;"></p>

<p style="text-align: center;">Figure I.1: Illustration of the first sample case.</p>

<p>To illustrate to him just how bad things can get without self-balancing, you want to show him that it is possible to build trees of nearly any height by carefully choosing an insertion order.</p>

<p>You are given two integers n and k and want to construct a binary search tree with n nodes of height k (the height of a tree is the maximal number of nodes on a path from the root to a leaf). To do so, you need to find a permutation of the integers from 1 to n such that, when they are inserted into an empty binary search tree in that order (without self-balancing), the resulting tree has height k.</p>

### 입력 

 <p>The input consists of two integers n and k (1 ≤ k ≤ n ≤ 2 · 10<sup>5</sup>), where n is the number of nodes in the tree and k is the exact height the tree should have.</p>

### 출력 

 <p>If there is no solution, output impossible. Otherwise, output one line with n integers, the requested permutation. If there is more than one solution, any one of them will be accepted.</p>

