# [8632. Byteland](https://www.acmicpc.net/problem/8632)

## 문제
King Byteasar I the Great is the ruler of a mighty and rich country of Byteland. There are $n$ towns in the country. King Byteasar would like to improve the infrastructure of Byteland and has ordered the royal architects to prepare plans for building highways across the country. He has received $m$ proposals, each of which is described by three numbers $p$, $k$, $w$, where $p$ and $k$ are the towns being the endpoints of the highway, and $w$ denotes the cost of building this highway. Each highway is bidirectional and does not visit any town except for its endpoints.


The king would like to choose the highways so that there exists at least one way of travelling between any pair of towns, possibly by visiting several towns along the way. Byteasar would like to build the highway network as cheaply as possible.


Write a program which:




reads from the standard input the number of towns, the number of proposed highways and the descriptions of these highways,


finds out, for each highway, whether there exists a highway network containing this highway and satisfying Byteasar's requirements,


writes the results to the standard output.

## 예제 입력 1
```
6 10
1 2 2
1 6 1
1 5 3
4 1 5
2 6 2
2 3 5
4 3 4
3 5 4
4 5 4
5 6 3
```

## 예제 출력 1
```
TAK
TAK
TAK
NIE
TAK
NIE
TAK
TAK
TAK
TAK
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Platinum 4 | C++17 / 수정 | 15092 KB | 380 ms | 2507 B | 1년 전 |
