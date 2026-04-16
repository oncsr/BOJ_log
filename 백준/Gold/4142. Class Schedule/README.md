# [4142. Class Schedule](https://www.acmicpc.net/problem/4142)

## 문제
At Fred Hacker's school, there are 
T × C
 classes, divided into 
C
 catagories of 
T
 classes each. The day begins with all the category 1 classes being taught simultaneously. These all end at the same time, and then all the category 2 classes are taught, etc. Fred has to take exactly one class in each category. His goal is to choose the set of classes that will minimize the amount of ``energy'' required to carry out his daily schedule.


The energy requirement of a schedule is the sum of the energy requirement of the classes themselves, and energy consumed by moving from one class to the next through the schedule.


More specifically, taking the 
j
th class in the 
i
th category uses 
E
ij
 units of energy. The rooms where classes take place are located at integer positions (ranging from 0 to 
L
) along a single hallway. The 
j
th class in the 
i
th category is located at position 
P
ij
. Fred starts the day at position 0, moves from class to class, according to his chosen schedule, and finally exits at location 
L
. Moving a distance 
d
 uses 
d
 units of energy.

## 예제 입력 1
```
1
3 2 5
2 1
3 1
4 1
1 3
1 4
3 2
```

## 예제 출력 1
```
11
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 2 | Java 11 / 수정 | 26956 KB | 368 ms | 1612 B | 1년 전 |
