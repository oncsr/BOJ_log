# [25529. Training Schedule for ICPC](https://www.acmicpc.net/problem/25529)

## 문제
With little time remaining until ICPC, you decided to reschedule your training plan. As maintaining both mental and physical vitality is important, you decided to spend 
n
 days of the remaining 
n
 + 
m
 days for training, and 
m
 days for repose. The question is which days should be used for the training and which for the repose. A schedule that increases your 
ICPC power
 more is better.


Training days increase the power, and consecutive training days are more effective. One day of training on the 
k-
th day of consecutive training days increases the power by 2
k
 − 1, where 
k
 = 1 for the first day of the consecutive training days. A single training day increases the power by only 1, but two consecutive training days increase it by 1 + 3 = 4, and three consecutive training days increase it by 1 + 3 + 5 = 9.


Repose days, on the other hand, decrease the power, and consecutive repose days decrease it more rapidly. One day of repose on the 
k-
th day of consecutive repose days decreases the power by 2
k
 − 1, where 
k
 = 1 for the first day of the consecutive repose days. A single repose day decreases the power by only 1, but two consecutive repose days decrease it by 1 + 3 = 4, and three consecutive repose days decrease it by 1 + 3 + 5 = 9.


Let us compute the largest increment of your ICPC power after 
n
 + 
m
 days of training and repose by the best training schedule. Note that, if you have too many repose days, this may be negative.

## 예제 입력 1
```
1 1
3 2
6 1
1 6
0 3
2 4
7 9
0 0
```

## 예제 출력 1
```
0
7
35
-17
-9
-4
10
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 3 | Java 11 / 수정 | 15904 KB | 308 ms | 1505 B | 11달 전 |
