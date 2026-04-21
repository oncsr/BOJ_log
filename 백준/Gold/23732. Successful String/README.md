# [23732. Successful String](https://www.acmicpc.net/problem/23732)

## 문제
Yunee is studying English vocabulary. Among many words that Yunee has learned, "success" is Yunee's favorite word and "failure" is Yunee's least favorite word.


Yunee noticed that two identical characters appear in a row in the word "success" but not in the word "failure." So Yunee decided to call a string "successful string" when it has a property of the word "success." Formally, a string $S$ is a successful string when there is a position $i$ such that $S_i = S_{i+1}$. Here $S_i$ denotes the $i$-th character of $S$.


Yunee wants to count how many successful strings there are among the substrings of a given string. Help Yunee write a program that counts the number of successful substrings. 
You have to consider two substrings distinct when their positions are different, even if the two strings are the same.

## 예제 입력 1
```
7
success
```

## 예제 출력 1
```
15
```

## 예제 입력 2
```
7
failure
```

## 예제 출력 2
```
0
```

## 예제 입력 3
```
4
aaaa
```

## 예제 출력 3
```
6
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 4 | C++17 / 수정 | 2020 KB | 16 ms | 379 B | 2년 전 |
