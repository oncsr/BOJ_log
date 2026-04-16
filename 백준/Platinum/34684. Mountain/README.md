# [34684. Mountain](https://www.acmicpc.net/problem/34684)

## 문제
Figure 1
 A mountain with four peaks


See Figure 1. What do you see? Yes, it is a mountain. Let’s call such a figure a mountain. To be more precise, a mountain is an $x$-monotone polygonal chain consisting of at least two line segments whose slopes alternate between $+1$ and $−1$; the leftmost segment is a half-line (ray) of slope $+1$, and the rightmost segment is a half-line of slope $−1$. Every mountain has one or more peaks, which are endpoints incident to a segment of slope $+1$ to the left and a segment of slope $−1$ to the right; in other words, a peak is a locally highest point. In Figure 1, you can see a mountain consisting of eight segments, and it has four peaks, marked by small dots.


In this problem, you are given a set $P$ of $n$ points in the plane as input, and your task is to find a mountain with the maximum number of peaks that are chosen from $P$.




Figure 2
 Two mountains with four and seven peaks, respectively, chosen from a given set $P$ of $15$ points


An example is illustrated in Figure 2, in which the input set $P$ of $n = 15$ points, marked by small circles, is given, and to the left you can see a mountain with four peaks that belong to $P$, while to the right there is a mountain with seven peaks that belong to $P$. Since there is no such mountain with eight peaks chosen from $P$, the one to the right is a correct answer for the problem. See Sample Input/Output 2 below

## 예제 입력 1
```
4
0 0
1 0
2 0
3 0
```

## 예제 출력 1
```
4
```

## 예제 입력 2
```
15
0 0
1 4
3 2
6 0
6 3
6 5
9 1
10 4
12 5
13 0
13 5
15 2
18 3
19 4
20 1
```

## 예제 출력 2
```
7
```

## 예제 입력 3
```
17
10 4
12 5
19 4
6 5
20 1
0 0
1 4
13 0
6 0
6 3
18 3
3 2
9 1
13 5
15 2
20 2
15 3
```

## 예제 출력 3
```
8
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Platinum 4 | C++17 / 수정 | 6068 KB | 172 ms | 573 B | 4달 전 |
