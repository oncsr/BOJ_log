# [22197. Railway](https://www.acmicpc.net/problem/22197)

## 문제
A couple of years ago the Bergen Ministry of Infrastructure prepared a plan for a new light railway network. This network was supposed to connect all n neighbourhoods in the city with n−1 railway tracks in such a way, that there would be a path from every neighbourhood to every other neighbourhood. The planned tracks are identified by numbers from 1 to n − 1.


Years passed, new elections are approaching, and the railway network still exists only on paper. Therefore the Minister of Infrastructure (representing a party holding disagreement in high regard) decided to construct at least some part of the plan. He asked each of his m deputy ministers to choose which neighbourhoods they thought should be connected. That will result in a list of necessary tracks for each deputy minister. If a deputy minister thinks that the neighbourhoods a
1
, . . . , a
s
 need to be connected, then according to him or her, the necessary tracks are all those which lie on planned paths from a
i
 to a
j
 for some 1 ≤ i < j ≤ s.


The minister just received all lists from the deputy ministers. He decided to construct in the first place the tracks which are requested by at least k deputy ministers. Your task is to prepare a list of these tracks.

## 예제 입력 1
```
6 3 2
1 3
2 3
3 4
6 4
4 5
4 1 3 2 5
2 6 3
2 3 2
```

## 예제 출력 1
```
2
2 3
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Platinum 1 | Java 15 / 수정 | 137856 KB | 1672 ms | 2634 B | 22일 전 |
