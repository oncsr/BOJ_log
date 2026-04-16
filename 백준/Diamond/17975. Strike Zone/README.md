# [17975. Strike Zone](https://www.acmicpc.net/problem/17975)

## 문제
The strike zone in baseball is the volume of space which a baseball must pass through in order to be called a 
strike
, if the batter does not swing. A baseball that misses the strike zone is called a 
ball
, if the batter does not swing. Figure H.1 shows the locations of baseballs at plate which were captured by a ball tracking device during a baseball match. Each blue point was called a strike and each red point was called a ball during the match. This may motivate us to define a rectangular region that represents the strike zone of the match, by analyzing such a ball tracking data of the match.




Figure H.1: The locations of baseballs at plate during a baseball match. Blue points were called strikes and red points were called balls.


In this problem, you are given two sets, 
P
1
 and 
P
2
, of points in the plane and two positive constants 
c
1
 and 
c
2
. You are asked to find an axis-parallel rectangle 
R
 that maximizes the evaluation function eval(
R
) = 
c
1
 × 
s
 - 
c
2
 × 
b
, where 
s
 is the number of points in 
P
1
 ∩ 
R
 and 
b
 is the number of points in 
P
2
 ∩ 
R
.

## 예제 입력 1
```
2
-1 -1
4 4
2
0 0
2 2
5 2
```

## 예제 출력 1
```
6
```

## 예제 입력 2
```
3
0 5
3 3
8 -1
3
1 4
6 0
7 1
3 2
```

## 예제 출력 2
```
4
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Diamond 5 | Java 11 / 수정 | 297392 KB | 912 ms | 2963 B | 11달 전 |
