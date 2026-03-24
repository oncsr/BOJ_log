# 16025 - Maximum Strategic Savings

[문제 링크](https://www.acmicpc.net/problem/16025)

| 난이도 | 시간 제한 | 메모리 제한 |
|--------|----------|------------|
| Platinum 1 | 2 초 | 512 MB |

## 알고리즘 분류
- 자료 구조
- 분리 집합
- 그래프 이론
- 최소 스패닝 트리

## 제출 결과
| 메모리 | 시간 | 언어 | 코드 길이 | 제출 일자 |
|--------|------|------|----------|----------|
| 85168 KB | 1044 ms | Java 15 | 2376 B | 2026년 3월 24일 18:39:38 |

## 문제 설명
A long time ago in a galaxy far, far away, there are N planets numbered from 1 to N. Each planet has M cities numbered from 1 to M. Let city f of planet e be denoted as (e, f).

There are N × P two-way flights in the galaxy. For every planet e (1 ≤ e ≤ N), there are P flights numbered from 1 to P. Flight i connects cities (e, a<sub>i</sub>) and (e, b<sub>i</sub>) and costs ci energy daily to maintain.

There are M × Q two-way portals in the galaxy. For all cities with number f (1 ≤ f ≤ M), there are Q portals numbered from 1 to Q. Portal j connects cities (x<sub>j</sub>, f) and (y<sub>j</sub>, f) and costs z<sub>j</sub> energy daily to maintain.

It is possible to travel between any two cities in the galaxy using only flights and/or portals.

Hard times have fallen on the galaxy. It was decided that some flights and/or portals should be shut down to save as much energy as possible, but it should remain possible to travel between any two cities afterwards.

What is the maximum sum of energy that can be saved daily?

## 입력
The first line contains four space-separated integers N, M, P, Q (1 ≤ N, M, P, Q ≤ 10<sup>5</sup>).

Then P lines follow; the i-th one contains three space-separated integers a<sub>i</sub>, b<sub>i</sub>, c<sub>i</sub> (1 ≤ a<sub>i</sub>, b<sub>i</sub> ≤ M, 1 ≤ c<sub>i</sub> ≤ 10<sup>8</sup>).

Then Q lines follow; the j-th one contains three space-separated integers x<sub>j</sub>, y<sub>j</sub>, z<sub>j</sub> (1 ≤ x<sub>j</sub>, y<sub>j</sub> ≤ N, 1 ≤ z<sub>j</sub> ≤ 10<sup>8</sup>).

It is guaranteed that it will be possible to travel between any two cities using flights and/or portals. There may be multiple flights/portals between the same pair of cities or a flight/portal between a city and itself.

## 출력
Output a single integer, the maximum sum of energy that can be saved daily.
