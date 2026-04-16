# [11191. Xor Maximization](https://www.acmicpc.net/problem/11191)

## 문제
As you might have heard, Gunnar is an old and forgetful researcher. Most of his research is in security and he cares a bit too much about his own security, so for each website he has a different password. It would be very hard for him to remember all passwords, so for every website he only remembers the method he used to create the password.


For one of the very important websites he started with a file containing a long list of non-negative integers. Since he very much likes the operation ⊕ (xor), his password is a xor of some integers in the list. Note that the operation xor is defined on boolean values as 0 ⊕ 0 = 1 ⊕ 1 = 0 and 0 ⊕ 1 = 1 ⊕ 0 = 1. We can then extend this definition to integers, namely we first write the two integers in binary and then do xor for each two corresponding bits in the numbers. For example the xor of 12 = (1100)
2
 and 5 = (101)
2
 is 9 = (1001)
2
. Instead of addition, we can use the operation xor when summing numbers and we call this modified sum xor-sum.


Gunnar’s file contains a list of numbers and he selected a subset of the numbers such that its xor-sum is as large as possible. The resulting number was his password. Unfortunately, he forgot the algorithm to find the subset with the largest xor-sum, so he is asking you for help with restoring his password. Of course, he will not tell you for which website this password is.

## 예제 입력 1
```
3
1 3 5
```

## 예제 출력 1
```
7
```

## 예제 입력 2
```
4
2 6 4 8
```

## 예제 출력 2
```
14
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Platinum 3 | Java 11 / 수정 | 31304 KB | 392 ms | 1960 B | 10달 전 |
