# [30324. Finding Bridges](https://www.acmicpc.net/problem/30324)

## 문제
An undirected graph is a fundamental concept in graph theory, a branch of mathematics and computer science. It is a data structure that represents a set of vertices connected by edges that have no direction. In other words, in an undirected graph, if there is an edge from vertex $u$ to vertex $v$, there is also an edge from vertex $v$ to vertex $u$. We use a two-element set $\{A,B\}$ to represent such undirected edge. An undirected graph is simple if there is at most one edge between any pair of vertices.


In graph theory, a connected component is a group of vertices and edges within a graph where you can travel from any vertex to any other vertex by following a sequence of edges. A bridge is an edge in an undirected graph that, if removed, increases the number of connected components in the graph.


Bridges are essential concepts in graph analysis and have practical applications in network design, fault tolerance, and connectivity analysis. They are often used to identify vulnerable points in a network where the removal of a single edge could lead to the isolation of certain components or the disruption of connectivity. Identifying bridges in a graph can be done using various algorithms which can detect these crucial edges and help analyze the robustness and structure of a network or system.


You have a simple undirected graph whose vertices and edges are $V=\{1,2,\dots ,n\}$ and $E=\{\{u_1,v_1\}, \dots ,\{u_m, v_m\}\}$. Your friend, Flora, ask you to sequentially remove edges $e_1,𝑒_2,\dots ,e_q$ from your graph and report the number of bridges left in the graph after each removal. Please write a program to generate the report.

## 예제 입력 1
```
5 7 5
1 2
1 3
1 4
1 5
2 3
3 4
4 5
3 4
2 3
1 2
4 5
1 4
```

## 예제 출력 1
```
0
2
1
3
2
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Diamond 5 | Java 15 / 수정 | 212720 KB | 2024 ms | 4172 B | 1달 전 |
