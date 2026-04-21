# [23992. Math Encoder](https://www.acmicpc.net/problem/23992)

## 문제
Professor Math is working on a secret project and is facing a challenge where a list of numbers need to be encoded into a single number in the most efficient manner. After much research, Professor Math finds a 3 step process that can best encode the numbers:




The first step is to find all possible non-empty subsets of the list of numbers and then, for each subset, find the difference between the largest and smallest numbers (that is, the largest minus the smallest) in that subset. Note that if there is only one number in a subset, it is both the largest and the smallest number in that subset. The complete set itself is also considered a subset.


Then add up all the differences to get the final encoded number.


As the number may be large, output the number modulo 10
9
 + 7 (1000000007).




The professor has shared an example and its explanation below. Given a list of numbers, can you help the professor build an efficient function to compute the final encoded number?

## 예제 입력 1
```
1
4
3 6 7 9
```

## 예제 출력 1
```
Case #1: 44
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 5 | C++17 / 수정 | 2220 KB | 8 ms | 555 B | 2년 전 |
