# [Diamond V] Very Important Edge - 31311 

[문제 링크](https://www.acmicpc.net/problem/31311) 

### 성능 요약

메모리: 70976 KB, 시간: 2880 ms

### 분류

자료 구조, 그래프 이론, 트리, 분리 집합, 최소 스패닝 트리, 최소 공통 조상

### 제출 일자

2024년 11월 22일 04:35:09

### 문제 설명

<p>You are given a simple connected graph where each edge is assigned a non-negative weight. Recall that a minimum spanning tree of a graph is a connected, acyclic subset of the edges of the graph with minimum total weight. Find an edge which maximizes the minimum spanning tree weight of a given graph if that edge is deleted. It is guaranteed that the input graph remains connected after deleting any one edge.</p>

### 입력 

 <p>The first line of input contains two integers $n$ ($3 \le n \le 10^5$) and $m$ ($3 \le m \le 10^6$), where $n$ is the number of vertices and $m$ is the number of edges in the input graph. The vertices are numbered from $1$ to $n$.</p>

<p>Each of the next $m$ lines contains three integers $a$, $b$ ($1\le a<b\le n$) and $w$ ($1\le w\le10^6$). This denotes an edge between vertices $a$ and $b$ with weight $w$.</p>

### 출력 

 <p>Output a single integer, which is the minimum spanning tree weight of the input graph after the right edge is deleted.</p>

