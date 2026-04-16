# [1097. 마법의 문자열](https://www.acmicpc.net/problem/1097)

## 문제
L개의 문자로 이루어진 문자열 T가 있다. T(i)는 T를 i (0 ≤ i < L)번째 문자부터 시작하게 부터 시작하게 원형 이동한 것이고, 길이는 T의 길이와 같다. 즉, 0 ≤ j < L을 만족하는 모든 j에 대해서, T(i)의 j번째 문자는 T의 (i+j)%L 번째 문자와 같다. T(i)와 T가 같은 문자열이 되는 i가 정확히 K개 있다면, T를 마법의 문자열이라고 한다.


N개의 문자열 S
1
, S
2
, ..., SN이 주어진다. 크기가 N인 모든 순열 p = (p
0
, p
1
, ..., p
N-1
) 마다 새로운 문자열을 S
p
0
 + S
p
1
 + ... + S
p
N-1
을 하나 정의할 수 있다. 새로운 문자열이 마법의 단어가 되는 순열의 개수를 구해보자.

## 예제 입력 1
```
3
AB
RAAB
RA
2
```

## 예제 출력 1
```
3
```

## 예제 입력 2
```
3
CAD
ABRA
ABRA
1
```

## 예제 출력 2
```
6
```

## 예제 입력 3
```
4
AA
AA
AAA
A
1
```

## 예제 출력 3
```
0
```

## 예제 입력 4
```
6
AA
AA
AAA
A
AAA
AAAA
15
```

## 예제 출력 4
```
720
```

## 예제 입력 5
```
4
ABC
AB
ABC
CA
3
```

## 예제 출력 5
```
0
```

## 예제 입력 6
```
6
A
B
C
A
B
C
1
```

## 예제 출력 6
```
672
```

## 예제 입력 7
```
8
AAAAAAAAAAAAAAAAAAAA
AAAAAAAAAAAAAAAAAAAA
AAAAAAAAAAAAAAAAAAAA
AAAAAAAAAAAAAAAAAAAA
AAAAAAAAAAAAAAAAAAAA
AAAAAAAAAAAAAAAAAAAA
AAAAAAAAAAAAAAAAAAAA
AAAAAAAAAAAAAAAAAAAB
1
```

## 예제 출력 7
```
40320
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Platinum 5 | C++17 / 수정 | 2024 KB | 136 ms | 870 B | 1년 전 |
