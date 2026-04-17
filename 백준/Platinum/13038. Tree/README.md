# [13038. Tree](https://www.acmicpc.net/problem/13038)

## 문제
Nick has got a rooted tree with n vertices as his birthday present.


Recall that a rooted tree is a connected undirected graph, one vertex is chosen as a root. For each vertex the closest to the root neighbor is called the parent of this vertex, other neighbors are its children. The root has no parent. Nick's tree has vertices numbered from 1 to n, vertex with number 1 is the tree root.


Nick has decided to play with his tree. He chooses some vertex u and removes it, connecting the vertices that were its children to the former parent vertex of u. The root is never removed. But it is not interesting to just remove the vertices, so sometimes he asks for the length of the path from one vertex to another in the current tree. Answer to Nick's questions.

## 예제 입력 1
```
8
1 5 2 1 2 5 5
7
2 4
1 7 6
2 5
1 3 8
1 8 6
2 2
1 8 6
```

## 예제 출력 1
```
4
2
3
2
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Platinum 1 | C++17 / 수정 | 19188 KB | 188 ms | 2357 B | 2년 전 |
