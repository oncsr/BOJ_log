# [27639. Qizz Quzz (Hard)](https://www.acmicpc.net/problem/27639)

## 문제
After a successful presentation of your coding skills on the 
Fizz Buzz problem
 you have advanced to the second round of interviews for your dream job of code ninja at FizzBuzz Corp. In this interview you will tackle the Generalized Fizz Buzz problem.


Generalized Fizz Buzz is similar to the original Fizz Buzz. The program must print positive integers starting from 1, but some special numbers (and their multiples) should be replaced by strings. If something is divisible by multiple special numbers, it must be replaced by a concatenation of all their strings.


In this problem, your task 
isn’t
 to implement Generalized Fizz Buzz. Instead, you will be given a sequence and you need to decide whether it can be the output of a Generalized Fizz Buzz program.


A particular instance of Generalized Fizz Buzz is defined by the following parameters:




A positive integer 
n
.


A nonnegative integer 
k
.


Distinct positive integers 
d
1
, …, 
d
k
 such that 
d
1
 < 
d
2
 < ⋯ < 
d
k
.


Strings 
s
1
, …, 
s
k
 of lowercase English letters.




Their meaning is as follows:




The number 
n
 is the length of the sequence the program should output.


The number 
k
 is the number of replacement rules.


Each of the replacement rules has the form “Instead of multiples of 
d
i
 print the string 
s
i
.”


If multiple replacement rules apply, the label that should be printed is obtained by concatenating all the corresponding 
s
i
, ordered 
from the smallest to the largest divisor
.




For example, the original Fizz Buzz corresponds to 
k
 = 2, 
d
 = (3, 5), and s = (
fizz
, 
buzz
). The correct output of that program for 
n
 = 17 would be:




1 2 fizz 4 buzz fizz 7 8 fizz buzz 11 fizz 13 14 fizzbuzz 16 17


Note that instead of 15 we printed the concatenation of 
s
1
 (
fizz
) and 
s
2
 (
buzz
) because 15 is divisible both by 
d
1
 (3) and by 
d
2
 (5). Also note that you cannot print 
buzzfizz
 for 15 because you cannot change the order of the 
s
i
 when concatenating them.


Monika has also written her own implementation of a Generalized Fizz Buzz program. Monika’s program can only handle inputs where each of the strings 
s
i
 has between 1 and 25 characters, inclusive. (Her program can handle arbitrarily large values of 
k
 and 
d
i
.)


Monika has shown you a sequence of labels ℓ
1
, …, ℓ
n
. Find the largest 
q
 such that the prefix ℓ
1
, …, ℓ
q
 can be the output of Monika’s program.

## 예제 입력 1
```
5

7
mlem mlem mlem mlem mlem mlem fail

7
1 qizz quzz qizz 5 quzzqizz 007

8
1 2 3 4 hunter2 is my password

2
haha hahahaha

9
1 bat 3 batman robin batbat 7 batmanman 9
```

## 예제 출력 1
```
6
5
4
2
9
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 5 | C++17 / 수정 | 2280 KB | 112 ms | 1197 B | 1년 전 |
