# [26182. Interview Question](https://www.acmicpc.net/problem/26182)

## 문제
Fizz Buzz
 is a party game that is often used as a programming exercise in job interviews. In the game, there are two positive integers $a$ and $b$, and the game consists of counting up through the positive integers, replacing any number by 
Fizz
 if it is a multiple of $a$, by 
Buzz
 if it is a multiple of $b$, and by 
FizzBuzz
 if it is a multiple of both $a$ and $b$. The most common form of the game has $a=3$ and $b=5$, but other parameters are allowed.


Your task here is to solve the reverse problem: given a transcript of part of the game (not necessarily starting at 1), find possible values of $a$ and $b$ that could have been used to generate it.


Figure I.1 shows some sample sequences for various values of $a$ and $b$.








$a=3, b=5:$


1 2 Fizz 4 Buzz Fizz 7 8 Fizz Buzz 11 Fizz 13 14 FizzBuzz






$a=6, b=2:$


1 Buzz 3 Buzz 5 FizzBuzz 7 Buzz 9 Buzz 11 FizzBuzz 13






$a=4, b=4:$


1 2 3 FizzBuzz 5 6 7 FizzBuzz 9 10 11 FizzBuzz 13 14








Figure I.1: Example sequences for 
Fizz Buzz
.

## 예제 입력 1
```
7 11
7 8 Fizz Buzz 11
```

## 예제 출력 1
```
3 5
```

## 예제 입력 2
```
49999 50002
49999 FizzBuzz 50001 Fizz
```

## 예제 출력 2
```
2 125
```

## 예제 입력 3
```
8 11
Buzz Buzz FizzBuzz Buzz
```

## 예제 출력 3
```
10 1
```

## 예제 입력 4
```
10 15
10 11 12 13 14 15
```

## 예제 출력 4
```
8 23
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Silver 2 | C++17 / 수정 | 2024 KB | 24 ms | 1049 B | 3년 전 |
