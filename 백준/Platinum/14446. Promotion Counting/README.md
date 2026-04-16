# [14446. Promotion Counting](https://www.acmicpc.net/problem/14446)

## 문제
The cows have once again tried to form a startup company, failing to remember from past experience that cows make terrible managers!


The cows, conveniently numbered 1…N (1 ≤ N ≤ 100,000), organize the company as a tree, with cow 1 as the president (the root of the tree). Each cow except the president has a single manager (its "parent" in the tree). Each cow i has a distinct proficiency rating, p(i), which describes how good she is at her job. If cow ii is an ancestor (e.g., a manager of a manager of a manager) of cow j, then we say j is a subordinate of i.


Unfortunately, the cows find that it is often the case that a manager has less proficiency than several of her subordinates, in which case the manager should consider promoting some of her subordinates. Your task is to help the cows figure out when this is happening. For each cow i in the company, please count the number of subordinates j where p(j)>p(i).

## 예제 입력 1
```
5
804289384
846930887
681692778
714636916
957747794
1
1
2
3
```

## 예제 출력 1
```
2
0
1
0
0
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Platinum 2 | Java 11 / 수정 | 91232 KB | 840 ms | 2586 B | 1년 전 |
