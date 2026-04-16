# [26483. Fiboxor](https://www.acmicpc.net/problem/26483)

## 문제
Little Square and Little Triangle are having a fight on Valentine’s day again! The reason of this year’s fight? Little Square has said that the Fibonacci sequence is way prettier than the sequence of powers of two (Little Triangle’s favorite). Recall that the Fibonacci sequence is the sequence that begins with 0 and 1, and where subsequent elements are the sum of the two previous elements:


$$0, 1, 1, 2, 3, 5, 8, 13, \dots$$


Little Triangle likes this sequence particularly because you can easily calculate the bitwise exclusive or (
XOR
) of any subarray. Thus they told Little Square that if they can successfully answer $Q$ such 
XOR
 subarray queries, then they will accept the fact that Fibonacci is better. Little Triangle isn’t cruel though, so they agreed to let Little Square tell them only the value of the subarray 
XOR
 modulo $2^k$ each query, due to the fact that the Fibonacci sequence grows exponentially.


In the end, Little Square has to answer $Q$ queries, each of which contains three integers $k$, $l$, $r$. This query asks us to calculate the 
XOR
 of the Fibonacci numbers with indexes in the interval $[l, r]$ inclusive, indexed from $0$, modulo $2^k$.


Little Square asks for your help in order to win this argument, so they can go back at having a good time on Valentine’s day.

## 예제 입력 1
```
3
2 0 3
4 4 6
20 100 1000
```

## 예제 출력 1
```
2
14
519891
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 1 | C++17 / 수정 | 52812 KB | 572 ms | 465 B | 1년 전 |
