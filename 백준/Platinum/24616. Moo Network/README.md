# [24616. Moo Network](https://www.acmicpc.net/problem/24616)

## 문제
Farmer John's $N$ cows ($1 \leq N \leq 10^5$) are spread far apart on his farm and would like to build a communication network so they can more easily exchange electronic text messages (all of which of course contain variations of "moo").


The $i$th cow is located at a distinct location $(x_i,y_i)$ where $0 \leq x_i \leq 10^6$ and $0 \leq y_i \leq 10$. The cost of building a communication link between cows $i$ and $j$ is the squared distance between them: $(x_i-x_j)^2 + (y_i-y_j)^2$.


Please calculate the minimum cost required to build a communication network across which all the cows can communicate. Two cows can communicate if they are directly connected by a link, or if there is a sequence of links along which their message can travel.

## 예제 입력 1
```
10
83 10
77 2
93 4
86 6
49 1
62 7
90 3
63 4
40 10
72 0
```

## 예제 출력 1
```
660
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Platinum 4 | Java 11 / 수정 | 178272 KB | 2148 ms | 2724 B | 7달 전 |
