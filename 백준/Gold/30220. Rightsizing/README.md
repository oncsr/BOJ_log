# [30220. Rightsizing](https://www.acmicpc.net/problem/30220)

## 문제
Many tech companies have realized that they have “over-hired.” Now, looking at their books, they realize they might have to let go of some employees. In order to prioritize their bottom line, a company will always fire the employee who is making the greatest annual salary at the time. If multiple employees are making the same maximal annual salary, then the person whose name comes first alphabetically will be fired.


Of course, to improve morale, employees can still get raises, which makes figuring out who to fire a bit more tricky.


Given a set of employees and their initial annual salaries, followed by a sequence of actions (either the firing of an employee or giving a raise to a current employee), determine for each firing event, which employee got fired.

## 예제 입력 1
```
5 6
eduardo 6000000
mark 7000000
andrew 5000000
dustin 1000000
chris 500000
2
1 andrew 2000000
1 dustin 5000000
2
2
2
```

## 예제 출력 1
```
mark 7000000
andrew 7000000
dustin 6000000
eduardo 6000000
```

## 예제 입력 2
```
10 15
a 6
b 5
c 4
d 2
e 1
f 3
g 8
h 10
i 7
j 10
1 c 4
1 d 9
2
1 e 3
1 h 1
1 b 6
2
2
1 f 6
1 a 3
2
1 i 2
2
1 e 5
2
```

## 예제 출력 2
```
d 11
b 11
h 11
j 10
a 9
e 9
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 3 | C++17 / 수정 | 38244 KB | 364 ms | 1291 B | 2년 전 |
