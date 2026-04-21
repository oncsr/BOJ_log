# [21956. Treasure](https://www.acmicpc.net/problem/21956)

## 문제
Andrei is an adventurer who tries to find a treasure full of gold coins. When he arrives at the last clue, which will tell him where the treasure is, he sees that on the clue there are two numbers, N and K, and a string of N lowercase English letters. Andrei should take the current string and should eliminate the first sequence of exactly K identical letters which appear on consecutive positions. He will repeat this process until there will be no sequence which has K consecutive identical letters.


Andrei asks you to solve this problem as soon as possible so that he will be the first who discovers the treasure.


Find the final string after you successively eliminate the first sequence of K identical letters which appear on consecutive positions, until there is no such sequence left.

## 예제 입력 1
```
5 2
abbac
```

## 예제 출력 1
```
c
```

## 예제 입력 2
```
12 3
aabbbaabbaac
```

## 예제 출력 2
```
abbaac
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 5 | C++17 / 수정 | 2648 KB | 20 ms | 462 B | 2년 전 |
