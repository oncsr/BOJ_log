# [18484. Eight Sins](https://www.acmicpc.net/problem/18484)

## 문제
Does every interactive problem have to be binary search?


Somebody has secretly set $n$ integers $a_1, a_2, \ldots, a_n$ such that $1 \le a_1 < a_2 < \ldots < a_n \le k$. You have to guess these integers one by one interacting with the testing system.


Initially $i = 1$. To make a guess, you may send an integer $x$ such that $1 \le x \le k$. The system will reply with a string containing a single character:




"
>
" if $a_i > x$;


"
<
" if $a_i < x$;


"
=
" if $a_i = x$.




In case $a_i = x$, the value of $i$ is increased by 1. You win after you guess all $n$ integers correctly, that is, when $i$ reaches $n + 1$.


Note that the values of $a_1, a_2, \ldots, a_n$ are not chosen in advance by the interactor, but all replies to your queries will be consistent with some valid set of $a_1, a_2, \ldots, a_n$ at any time.

## 예제 입력 1
```
3 6

<

<

=

>

=

=
```

## 예제 출력 1
```
6

3

1

3

4

5
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Diamond 5 | C++17 / 수정 | 13980 KB | 1748 ms | 635 B | 1년 전 |
