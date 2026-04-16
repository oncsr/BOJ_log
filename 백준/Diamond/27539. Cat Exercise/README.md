# [27539. Cat Exercise](https://www.acmicpc.net/problem/27539)

## 문제
There are $N$ cat towers, numbered from $1$ to $N$. The height of Tower $i$ ($1 ≤ i ≤ N$) is $P_i$. The heights of the towers are distinct integers between $1$ and $N$, inclusive. There are $N - 1$ adjacent pairs of towers. For each $j$ ($1 ≤ j ≤ N - 1$), Tower $A_j$ and Tower $B_j$ are adjacent to each other. In the beginning, it is possible to travel from a tower to any other tower by repeating moves from towers to adjacent towers.


In the beginning, a cat stays in a tower of height $N$.


Then we perform 
cat exercises
. In cat exercises, we repeatedly choose a tower and put an obstacle on it. However, we cannot put an obstacle on a tower where we already put an obstacle on it. During the process, the following will happen.




If the cat does not stay in the chosen tower, nothing will happen.


If the cat stays in the chosen tower and there is an obstacle on every tower which is adjacent to the chosen tower, the cat exercises will finish.


Otherwise, among the towers where the cat can arrive by repeating moves from towers to adjacent towers without obstacles, the cat will move to the highest tower except for the current tower by repeating moves from towers to adjacent towers. In this process, the cat takes the route where the number of moves from towers to adjacent towers becomes minimum.




Given information of the heights of the towers and pairs of adjacent towers, write a program which calculates the maximum possible sum of the number of moves of the cat from towers to adjacent towers if we put obstacles suitably

## 예제 입력 1
```
4
3 4 1 2
1 2
2 3
3 4
```

## 예제 출력 1
```
3
```

## 예제 입력 2
```
7
3 2 7 1 5 4 6
1 2
1 3
2 4
2 5
3 6
3 7
```

## 예제 출력 2
```
7
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Diamond 5 | Java 11 / 수정 | 167168 KB | 2044 ms | 2727 B | 8달 전 |
