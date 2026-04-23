# [26209. Intercepting Information](https://www.acmicpc.net/problem/26209)

## 문제
Spies Breaching Computers (SBC) is a private digital spy agency that is developing a new device for intercepting information using electromagnetic waves, which allows spying even without physical contact with the target.


The device tries to collect information one byte at a time, this is, a sequence of $8$ bits where each of them, naturally, can have a value of $0$ or $1$. In certain situations, due to interference from other devices, the reading cannot be done successfully. In this case, the device returns the value $9$ for the corresponding bit, informing that the reading could not be performed.


In order to automate the recognition of the information the device reads, a request was made for a program that, based on the information read by the device, informs whether all bits were read successfully or not. Your task is to write this program.

## 예제 입력 1
```
0 0 1 1 0 1 0 1
```

## 예제 출력 1
```
S
```

## 예제 입력 2
```
0 0 1 9 0 1 0 1
```

## 예제 출력 2
```
F
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Bronze 5 | PyPy3 / 수정 | 113112 KB | 156 ms | 26 B | 3년 전 |
