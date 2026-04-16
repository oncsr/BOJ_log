# [9846. Rank](https://www.acmicpc.net/problem/9846)

## 문제
In a new sports discipline called Triball proposed for the Youth Olympic Games in Singapore, a set of k players {1, 2, . . . , k} are involved (where k < 1000). In every match, 3 players are selected and the result of the match is either 1 winner or 1 loser. Given the result of n matches (where n < 10000), our task is to give a ranking list of the players.


Precisely, the i
th
 match involves three distinct players p
i1
, p
i2
, p
i3
 ∈ {1, 2, . . . , k}. The result of the i th match is represented by p
i1
 > p
i2
, p
i3
 (or p
i2
, p
i3
 > p
i1
) where p
i1
 is the winner (or loser) of the match. The result p
i1
 > p
i2
, p
i3
 implies that p
i1
 is better than p
i2
 and that p
i1
 is better than p
i3
. Similarly, the result p
i2
, p
i3
 > p
i1
 implies that p
i2
 is better than p
i1
 and that p
i3
 is better than p
i1
. Our aim is to find the permutation of the k players so that a better player always comes before his opponent, considering all given matches. If we cannot reach our aim and such a permutation does not exist, we output 0.

## 예제 입력 1
```
6 5
4>1,3
3>1,2
2,5>6
5>2,3
1>2,6
```

## 예제 출력 1
```
4 5 3 1 2 6
```

## 예제 입력 2
```
4 2
1>2,4
2,4>1
```

## 예제 출력 2
```
0
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 5 | C++17 / 수정 | 2168 KB | 0 ms | 851 B | 1년 전 |
