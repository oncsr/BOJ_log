# [27137. Square Designs](https://www.acmicpc.net/problem/27137)

## 문제
Write a program that will generate Square Designs like the ones below for any values of M and N (1 ≤ M ≤ 18; 1 ≤ N ≤ 18).  Exactly ten spaces separate the pair of boxes and the left box has no spaces in front of it.  There are neither "tabs" nor trailing spaces in the output.


Here is the output for M=5 and N=3:



+-----------+          +-------+
I-X-X-X-X-X-I          I-X-X-X-I
I-X-X-X-X-X-I          I-X-X-X-I
I-X-X-X-X-X-I          I-X-X-X-I
I-X-X-X-X-X-I          +-------+
I-X-X-X-X-X-I
+-----------+


This output contains no blank lines.

## 예제 입력 1
```
2 6
```

## 예제 출력 1
```
+-----+          +-------------+
I-X-X-I          I-X-X-X-X-X-X-I
I-X-X-I          I-X-X-X-X-X-X-I
+-----+          I-X-X-X-X-X-X-I
                 I-X-X-X-X-X-X-I
                 I-X-X-X-X-X-X-I
                 I-X-X-X-X-X-X-I
                 +-------------+
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Silver 5 | C++17 / 수정 | 2020 KB | 0 ms | 833 B | 3년 전 |
