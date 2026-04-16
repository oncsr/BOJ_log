# [32584. Annoying Alliterations](https://www.acmicpc.net/problem/32584)

## 문제
Bajtazar is a member of the jury for the Find Your Palace Contest, a prestigious programming competition that offers a luxurious palace to the winner. He is now trying to come up with a name for his problem. According to Bajtazar, a good problem name consists of exactly two words. Additionally, Bajtazar finds alliterations very annoying, so he will remove the first letter from both words until the first letter of the two words is different or one of them becomes empty. After this operation, Bajtazar defines the 
goodness
 of the problem name as the sum of lengths of the two words.


He has prepared a list of $n$ words, and started to wonder what is the maximum goodness that can be achieved using the words from the list. Bajtazar himself does not have time to answer that question as he is busy reinforcing the tests with nasty edge cases. Help Bajtazar by finding the maximum goodness that can be achieved.

## 예제 입력 1
```
3
amsterdam
is
amazing
```

## 예제 출력 1
```
12
```

## 예제 입력 2
```
3
bbb
abbba
aaba
```

## 예제 출력 2
```
8
```

## 예제 입력 3
```
2
abcdefghijklmnopqrstuvwxyz
abcdefghijklmnopqrstuvwxyz
```

## 예제 출력 3
```
0
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 1 | C++17 / 수정 | 267620 KB | 280 ms | 807 B | 1년 전 |
