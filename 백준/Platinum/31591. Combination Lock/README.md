# [31591. Combination Lock](https://www.acmicpc.net/problem/31591)

## 문제
Your house is protected by a combination lock containing $n$ rotating discs, numbered from $1$ to $n$. On a typical combination lock, each rotating disc has $10$ symbols, represented by integers between $0$ to $9$, inclusive. Since you are a mathematician, your combination lock is not typical. Instead, each rotating disc on your combination lock may have a different number of symbols. In particular, rotating disc $i$ has $b_i - a_i + 1$ symbols, represented by integers between $a_i$ to $b_i$, inclusive.


The combination lock is unlocked when each rotating disc displays one integer, and any pair of two integers displayed by the rotating disc are coprime. Two integers are coprime if they do not have any common positive factors other than $1$.


You want to unlock the combination lock, so you want to determine what integer to be displayed on each combination lock to satisfy the requirement above. It is possible that your combination lock was sabotaged when you were gone so it might be impossible to unlock your combination lock.

## 예제 입력 1
```
4
3 9
2 8
1 4
2 10
```

## 예제 출력 1
```
3 7 1 10
```

## 예제 입력 2
```
3
5 6
5 6
2 6
```

## 예제 출력 2
```
-1
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Platinum 5 | C++17 / 수정 | 23108 KB | 1180 ms | 1087 B | 2년 전 |
