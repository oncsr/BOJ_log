# [33776. Stablo II](https://www.acmicpc.net/problem/33776)

## 문제
Patrik received a tree with $n$ vertices. He decided to paint the edges of that tree using $k$ different colors.


Initially, all edges of the tree are painted with color $0$. He will use the colors in order from the first to the $k$-th, where he will use the $i$-th color to paint all the edges on the shortest path from the $x_i$-th to the $y_i$-th node. If an edge on that path is already painted, the new color will overwrite the old one.


Help Patrik determine the final color of each edge.

## 예제 입력 1
```
6 2
1 2
2 3
2 4
1 5
4 6
5 2
6 1
```

## 예제 출력 1
```
2 0 2 1 2
```

## 예제 입력 2
```
5 4
1 2
2 3
3 4
4 5
5 5
4 3
2 1
2 4
```

## 예제 출력 2
```
3 4 4 0
```

## 예제 입력 3
```
5 4
3 5
2 3
4 3
5 1
4 1
5 5
4 2
1 5
```

## 예제 출력 3
```
1 3 3 4
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Platinum 1 | Java 11 / 수정 | 590688 KB | 7516 ms | 2190 B | 1년 전 |
