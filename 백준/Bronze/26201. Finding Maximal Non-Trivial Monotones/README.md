# [26201. Finding Maximal Non-Trivial Monotones](https://www.acmicpc.net/problem/26201)

## 문제
In this problem we will be dealing with character sequences, often called 
strings
. A sequence is 
non-trivial
 if it contains at least two elements.


Given a sequence $s$, we say that a chunk $s_i , \dots , s_j$ is 
monotone
 if all its characters are equal, and we say that it is 
maximal
 if this chunk cannot be extended to left or right without losing the monotonicity.


Given a sequence composed only of characters “
a
” and “
b
”, determine how many characters “
a
” occur in non-trivial maximal monotone chunks.

## 예제 입력 1
```
7
abababa
```

## 예제 출력 1
```
0
```

## 예제 입력 2
```
7
bababab
```

## 예제 출력 2
```
0
```

## 예제 입력 3
```
10
aababaaabb
```

## 예제 출력 3
```
5
```

## 예제 입력 4
```
10
bbaababaaa
```

## 예제 출력 4
```
5
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Bronze 3 | C++17 / 수정 | 2020 KB | 8 ms | 226 B | 3년 전 |
