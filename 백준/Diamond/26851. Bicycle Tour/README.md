# [26851. Bicycle Tour](https://www.acmicpc.net/problem/26851)

## 문제
There are N junctions in Jakarta (numbered from 1 to N) that are connected by M bidirectional roads such that from any junction you can reach any other junctions by going through one or more roads. The i
th
 junction has a height of H
i
.


Ahmad loves to cycle, especially on flat roads. He argues that you need more power to cycle if the road is uphill or downhill. Specifically, to cycle on a road connecting junction i and junction j, you will require a power of |H
i
 − H
j
|. The required power to cycle a set of roads is equal to the highest required power to cycle each of those roads. For example, let there be 3 roads where each requires a power of 10, 12, and 7 to cycle, then the required power to cycle through all those roads is max(10, 12, 7) = 12.


A cycling route from junction i is defined as a tour that starts at junction i, going to one or more other junctions while not using the same road more than once, and ends at the same junction i.


Ahmad would like to find a cycling route from each junction that has a minimum required power, and that is your task in this problem. For each junction, you need to output the required power of a cycling route from that junction that has the minimum required power. There might be a case where a cycling route from a junction is not possible; in such a case, the output should be −1 for the respective junction.


For example, let N = 8, H
1..8
 = {5, 2, 7, 0, 10, 6, 6, 6}, M = 11, and the roads be shown in the following figure. The label on each node indicates the junction number while the number on each edge indicates the required power to cycle through that road. Notice that the required power to cycle through each road can be obtained from the given H
1..8
.




The following are the cycling routes with the minimum required power from each junction:




Junction 1: 1 → 2 → 7 → 6 → 1, with a required power of 4.


Junction 2: 2 → 1 → 6 → 7 → 2, with a required power of 4.


Junction 3: 3 → 2 → 1 → 3, with a required power of 5.


There is no possible cycling route from junction 4.


Junction 5: 5 → 3 → 1 → 2 → 5, with a required power of 8.


Junction 6: 6 → 7 → 8 → 6, with a required power of 0.


Junction 7: 7 → 8 → 6 → 7, with a required power of 0.


Junction 8: 8 → 6 → 7 → 8, with a required power of 0.

## 예제 입력 1
```
8 11
5 2 7 0 10 6 6 6
1 2
1 3
2 3
2 4
2 5
2 7
3 5
1 6
6 7
6 8
7 8
```

## 예제 출력 1
```
4 4 5 -1 8 0 0 0
```

## 예제 입력 2
```
4 5
10 20 30 40
1 2
1 3
1 4
2 3
3 4
```

## 예제 출력 2
```
20 20 20 30
```

## 예제 입력 3
```
5 4
72 35 22 49 108
1 2
2 3
3 4
4 5
```

## 예제 출력 3
```
-1 -1 -1 -1 -1
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Diamond 5 | C++17 / 수정 | 27328 KB | 328 ms | 2969 B | 2년 전 |
