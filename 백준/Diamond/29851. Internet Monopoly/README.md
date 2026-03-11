# 29851 - Internet Monopoly

[문제 링크](https://www.acmicpc.net/problem/29851)

| 난이도 | 시간 제한 | 메모리 제한 |
|--------|----------|------------|
| Diamond 4 | 1 초 | 1024 MB |

## 알고리즘 분류
- 자료 구조
- 그래프 이론
- 트리
- 분리 집합
- 오프라인 쿼리
- 최소 공통 조상
- Heavy-light 분할
- 단절점과 단절선

## 제출 결과
| 메모리 | 시간 | 언어 | 코드 길이 | 제출 일자 |
|--------|------|------|----------|----------|
| 168000 KB | 1012 ms | Java 15 | 3428 B | 2026년 3월 12일 06:50:26 |

## 문제 설명
There are $N$ cities in the Very Proud Kingdom, numbered $1, \ldots, N$.

All the internet cables in the country are managed by *Internet Operations Incorporated*, or IOI. Internet service providers rent from IOI the right to use the cables.

The price list of IOI has the following structure: the yearly rent for some cables is $100\,000$ Euros; for the remaining cables it's $200\,000$ Euros. Each service provider always rents cables in such a way that all cities are connected to each other (possibly indirectly) by the rented cables and the total amount of rent is the lowest possible. IOI would like all renters to rent the exact same set of cables; this would make it easier for IOI to manage its cable network.

Every now and then, IOI lays new cables, and then the question arises: Is it possible to set the price list in such a way that exactly $K$ cables have the yearly rent equal to $100\,000$ Euros, and it's quaranteed that all the renters will rent access to the exact same set of cables?

More formally, your program needs to process queries of the following types:

- Given cities $U$ and $V$. IOI lays a new cable between cities $U$ and $V$.
- Given $K$. Determine whether it is possible to set the price list according to the conditions above.

In the beginning, before the first query, there are no cables in the country. You may assume that queries of the second type will only be given once all the cities in the country are connected to each other (possibly indirectly) by cables laid by IOI. You may also assume that IOI will never lay a cable between two cities where there already is a cable.

## 입력
The first line contains space-separated integers $N$ and $Q$ ($1 \le N \le 3 \cdot 10^5$, $1 \le Q \le 4 \cdot 10^5$), the number of cities and the number of queries, respectively.

The following $Q$ lines describe the queries. Each query of type 1 is given as '`+` $U$ $V$' ($1 \le U \le N$, $1 \le V \le N$, $U \ne V$), each query of type 2 as '`?` $K$' ($0 \le K \le M$ where $M$ is the number of cables laid by that time).

## 출력
Output answers to the queries of type 2, each answer on a separate line. If it is possible to set the price list, print '`JAH`', otherwise print '`EI`'.
