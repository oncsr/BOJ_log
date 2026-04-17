# [29441. XOR](https://www.acmicpc.net/problem/29441)

## 문제
Today Paul and Andrew discovered a new operation, 
XOR
 of two numbers.


Let us remind you that 
XOR
, or 
exclusive OR
, is a binary operation which is applied to two integer numbers bitwise. For each bit position, if the bits in the arguments are equal, the resulting bit is 
0
, otherwise 
1
. For example, 3 
XOR
 5 $=$ 6, because $3_{10} = 011_2$, $5_{10} = 101_2$, so if we apply the operation, the second and the third bits are set to 
1
, bit the first bit is set to 0, so we get $110_{2} = 6_{10}$.


Paul and Andrew liked this operation so much that they invented a game. First, Paul writes $n$ integer numbers $a_i$. Second, Andrew writes $m$ integers $b_j$. After that, Paul finds for each $b_j$ such $k$ that $a_k$ 
XOR
 $b_j$ is maximal.


The only problem is that Paul is not very fast in finding these numbers. Help him!

## 예제 입력 1
```
2
0 1
2
2 3
```

## 예제 출력 1
```
1 0
```

## 예제 입력 2
```
2
3 0
3
2 3 9
```

## 예제 출력 2
```
0 0 3
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Platinum 3 | C++17 / 수정 | 47032 KB | 296 ms | 1714 B | 2년 전 |
