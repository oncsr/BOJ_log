# [9820. Placement of Keys](https://www.acmicpc.net/problem/9820)

## 문제
Assume that there are n (3 ≤ n ≤ 200) boxes identified by A
1
, A
2
,..., A
n
, and each box A
i
 is configured a lock which is different from the others. Now put n keys to the n locks into the n boxes, each box can only hold a key. After locking all the boxes, unclench the boxes named A
1
, A
2
 and fetch out the keys in them to unlock the locked boxes. If the two keys can open some box, fetch out the key in the box to unlock other locked boxes again. If we can open all the boxes finally, we call the placement of the n keys good placement. How many are there different good placements of the n keys?

## 예제 입력 1
```
6
8
-1
```

## 예제 출력 1
```
N=6:
240
N=8:
10080
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Silver 1 | Python 3 / 수정 | 31120 KB | 64 ms | 142 B | 1년 전 |
