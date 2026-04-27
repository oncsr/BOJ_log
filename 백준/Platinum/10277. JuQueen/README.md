# [10277. JuQueen](https://www.acmicpc.net/problem/10277)

## 문제
JuQueen is the super computer with the best performance allover Germany. It is on rank 8 in the famous top500 list with its 458 752 cores. It draws a lot of energy (up to 2 301 kW), so we want to reduce that by underclocking the unused cores. The cluster scheduling algorithm which is in charge of distributing jobs over the nodes and cores of a cluster will issue the following speedstepping commands:




change X S
 changes the frequency of core X by S steps


groupchange A B S
 changes the frequency of every core in range [A,B] by S steps


state X
 returns the current state of core X




To be safe for the future, your program should be able to handle 4 587 520 cores. The initial frequency for each core is 0.

## 예제 입력 1
```
10 10 5
state 0
groupchange 2 9 7
state 9
groupchange 0 2 10
change 0 -5
```

## 예제 출력 1
```
0
7
7
3
-3
```

## 예제 입력 2
```
4587520 10000 5
groupchange 0 4587010 9950
groupchange 23 4587000 42
groupchange 4710 4587001 -1000
state 1234560
groupchange 6666 3060660 10000
```

## 예제 출력 2
```
9950
42
-1000
8992
1008
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Platinum 2 | C++17 / 수정 | 198632 KB | 136 ms | 1960 B | 3년 전 |
