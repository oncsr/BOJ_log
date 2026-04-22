# [28375. German Conference for Public Counting](https://www.acmicpc.net/problem/28375)

## 문제
Greta loves counting. She practises it every day of the year. Depending on the season, she counts falling leaves, raindrops, snowflakes, or even growing leaves. However, there is one event in summer which tops everything else: the German Conference for Public Counting (GCPC).


At this event, Greta meets counting enthusiasts from all over the country for one week of counting and counting and counting... Together they participate in the Glamorous Competitive Public Counting and the Great Chaotic Public Counting. At the end of the week they all try to win the Golden Cup of Public Counting. Her favourite is the Gently Calming Public Counting where the crowd counts in silence, trying to harmoniously synchronise to reach the target number at precisely the same moment.




Figure G.1: People holding up signs for the countdown.


To increase the tension and to prepare for the Gently Calming Public Counting, the organizers of GCPC plan to start with a silent countdown, where the people on the stage will at any time display the current number by holding up signs with its digits. On every sign, there is exactly one decimal digit. Numbers greater than $9$ are displayed by holding up several signs next to each other. Each number is shown using the least possible number of signs; there is no left padding with zeroes. This way, the people on the stage display numbers $n, n-1, n-2, \dots$ until they finally display $0$. Since the GCPC will take place soon, the organizers want to finish their preparations quickly. How many signs do they need to prepare at least so that they can display the entire countdown from $n$ to $0$?

## 예제 입력 1
```
5
```

## 예제 출력 1
```
6
```

## 예제 입력 2
```
20
```

## 예제 출력 2
```
11
```

## 예제 입력 3
```
44
```

## 예제 출력 3
```
14
```

## 예제 입력 4
```
271828182
```

## 예제 출력 4
```
82
```

## 예제 입력 5
```
314159265
```

## 예제 출력 5
```
82
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Silver 3 | C++17 / 수정 | 2260 KB | 0 ms | 453 B | 2년 전 |
