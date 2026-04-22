# [28053. Simple Game](https://www.acmicpc.net/problem/28053)

## 문제
Let $s$ be an arithmetic sequence consisting of $2n$ integers, where the first term is denoted as $a$ and the common difference as $b$. In other words, $s = [a, a+b, a+2b, \ldots, a+(2n-1)b]$.


You should perform a sequence of $n$ operations, where each operation involves selecting two 
coprime
 integers from $s$ and erasing them. Once an integer is erased from $s$, it cannot be selected again for any subsequent operations.


Find any sequence of operations satisfying the above conditions, or report that such a sequence does not exist.

## 예제 입력 1
```
2 1 1
```

## 예제 출력 1
```
Yes
1 4
2 3
```

## 예제 입력 2
```
4 4 6
```

## 예제 출력 2
```
No
```

## 예제 입력 3
```
3 995069485 940582184
```

## 예제 출력 3
```
Yes
3816816037 4757398221
5697980405 1935651669
2876233853 995069485
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Silver 2 | C++17 / 수정 | 2020 KB | 32 ms | 398 B | 2년 전 |
