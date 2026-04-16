# [32494. TOLLS](https://www.acmicpc.net/problem/32494)

## 문제
In the country named Ivo, there are $N$ cities connected by $N-1$ bidirectional highways and you can get from any city to any other city using the highways. Each highway connects two different cities $u_i$ and $v_i$ and it has a toll tax $w_i$, $1 \leq i \leq N-1$. We will call "trip" a simple path (not containing duplicate cities) along the highways between two different cities $u$ and $v$. The costs for the trips in the country Ivo have been reduced and instead of paying the sum of the tolls along the trip, only one toll is paid, which is a maximal toll for a highway along the trip.


Ivaylo is responsible for the profits in the country. The government asked Ivaylo $Q$ questions for the sum of the costs of all the trips with costs in the interval $[l_j, r_j]$, $1 \leq j \leq Q$. It is guaranteed that the first question is for the sum of the costs of the trips between every two different cities, i.e. $l_1=1$ and $r_1=max_{1 \leq i \leq N-1}\{w_i\}$. Ivaylo cannot handle this task, calculating by hand, and because he cannot work with computers he requires that you write a program 
tolls
, which calculates the answers to the questions.

## 예제 입력 1
```
7 5
1 2 1
3 1 3
1 4 1
4 5 2
5 7 4
3 6 2
1 4
2 3
2 4
1 3
2 5
```

## 예제 출력 1
```
59
32
56
35
56
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Platinum 5 | C++17 / 수정 | 8548 KB | 100 ms | 944 B | 1년 전 |
