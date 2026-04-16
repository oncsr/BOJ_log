# [19464. King's Roads](https://www.acmicpc.net/problem/19464)

## 문제
King Byteasar wants to introduce an innovative road network in Byteland. There are $n$ cities in Byteland. There are $a_i$ citizens living in $i$-th city.


Initially, there are no roads in Byteland. The king wants to build several roads in such a way that all cities are connected (directly or indirectly). He also wants to minimize expenses on maintaining the roads.


Naturally, if a road connects populous cities, it is used more heavily and thus is more expensive to maintain. Formally, maintaining a road between cities $i$ and $j$ costs $a_i + a_j$ bytalers per year. However, if $a_i + a_j$ is at least $M$, the road is considered 
a national highway
, and it brings revenue of $M$ bytalers per year from taxation (thus, the effective cost for this road is $a_i + a_j - M$ per year). Note that all $a_i$ are less than $M$.


Help King Byteasar find the minimum annual cost for maintaining a set of roads so that all cities become connected.

## 예제 입력 1
```
5 9
1 3 5 8 8
```

## 예제 출력 1
```
6
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Platinum 2 | Java 11 / 수정 | 46464 KB | 628 ms | 1681 B | 1년 전 |
