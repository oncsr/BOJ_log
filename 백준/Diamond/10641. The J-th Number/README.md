# [10641. The J-th Number](https://www.acmicpc.net/problem/10641)

## 문제
You are given N empty arrays, t
1
,…,t
n
. At first, you execute M queries as follows.




add a value v to array t
i
 (a ≤ i ≤ b)




Next, you process Q following output queries.




output the j-th number of the sequence sorted all values in t
i
 (x ≤ i ≤ y)

## 예제 입력 1
```
5 4 1
1 5 1
1 1 3
4 5 1
3 4 2
1 3 4
```

## 예제 출력 1
```
2
```

## 예제 입력 2
```
10 4 4
1 4 11
2 3 22
6 9 33
8 9 44
1 1 1
4 5 1
4 6 2
1 10 12
```

## 예제 출력 2
```
11
11
33
44
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Diamond 3 | Java 15 / 수정 | 408744 KB | 6588 ms | 5427 B | 11일 전 |
