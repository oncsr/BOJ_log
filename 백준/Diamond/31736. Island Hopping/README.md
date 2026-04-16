# [31736. Island Hopping](https://www.acmicpc.net/problem/31736)

## 문제
There are $N$ islands in JOI Kingdom, numbered from $1$ to $N$. There are $N - 1$ sea routes in JOI Kingdom, numbered from $1$ to $N - 1$. The sea route $j$ ($1 ≤ j ≤ N - 1$) connects island $A_j$ and island $B_j$ bi-directionally. It is possible to travel from any island to any other island by using some sea routes.


Aoi is planning a trip in JOI Kingdom. However, she doesn’t know about sea routes in JOI Kingdom. She is going to ask questions with Bitaro, a citizen in JOI Kingdom, in the following way:




Aoi tells Bitaro an integer $v$, where $1 ≤ v ≤ N$, and an integer $k$, where $1 ≤ k ≤ N - 1$.


Bitaro tells Aoi the number on the island which is the $k$-th closest from island $v$ among the $N - 1$ islands except for island $v$. To be specific, he tells her an integer $i$ that $\text{dist}(v, i) \times N + i$ ($1 ≤ i ≤ N$, $i \ne v$) is the $k$-th smallest, where $\text{dist}(v, i)$ is the minimum number of sea routes to move from island $v$ to island $i$.




Aoi wants to know all sea routes in JOI Kingdom by asking questions to Bitaro. Since Aoi does not want to spend too much time, she can ask at most $L$ questions to Bitaro.


Write a program which, given the number of islands in JOI Kingdom and the limit on number of questions to Bitaro, implements Aoi’s strategy to find all sea routes.

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Diamond 5 | C++17 / 수정 | 2036 KB | 0 ms | 415 B | 1년 전 |
