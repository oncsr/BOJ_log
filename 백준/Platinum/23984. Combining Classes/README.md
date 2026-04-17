# [23984. Combining Classes](https://www.acmicpc.net/problem/23984)

## 문제
Supervin is teaching 
N
 classes, which are numbered from 1 to 
N
. After giving his most recent exam, he noticed that in each of his classes, the test scores of his students form a sequence of consecutive integers. Therefore, Supervin can summarize the scores for the i-th class as two integers 
L
i
 and 
R
i
. This means that the i-th class has 
R
i
 - 
L
i
 + 1 students, and for each x (
L
i
 ≤ x ≤ 
R
i
), there is exactly one student with score x.


Supervin would like to combine the scores from the students from all of his classes and sort the scores in non-increasing order. He has 
Q
 questions (numbered from 1 to 
Q
) about this list; for the i-th question, he wants to know what the 
K
i
-th highest score is. (If 
K
i
 is greater than the number of students, then the answer for the i-th question is 0.)


Can you help Supervin answer all of his questions? Since there may be many answers, instead of outputting all of them, output proof that you have answered them: the sum of (S
i
 × i) for all 1 ≤ i ≤ 
Q
, where S
i
 is the answer to the i-th question.

## 예제 입력 1
```
2
5 1
3 1 4 1 5 9
2 7 1 8 2 9
4 8 15 16 23 42
7 1
2 3 4 5 6 31
1 3 4 5 5 17
2 2 1 3 2 100
```

## 예제 출력 1
```
Case #1: 7
Case #2: 28
```

## 예제 입력 2
```
2
5 5
3 1 4 1 5 9
2 7 1 8 2 9
4 8 15 16 23 42
1 2
0 0 0 0 0 1
0 0 0 0 0 1
0 1 0 0 0 2
```

## 예제 출력 2
```
Case #1: 39
Case #2: 1
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Platinum 4 | C++17 / 수정 | 39216 KB | 8100 ms | 1874 B | 2년 전 |
