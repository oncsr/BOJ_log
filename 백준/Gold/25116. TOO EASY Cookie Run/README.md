# [25116. TOO EASY Cookie Run](https://www.acmicpc.net/problem/25116)

## 문제
Cookie Run game is a popular game in which the cookie character runs through a map consisting of N stages to score points. 




Soo Young, the map designer for Cookie Run, was preparing a new map patch for Children's Day. After working hard to create an attractive map and testing it for the last time the day before the patch, she suddenly realized that the map was designed to be 
too easy
!


The map design of the cookie run game consists of the following rules. 




Each stage is given a difficulty level of $A_0, A_1, A_2, ..., A_{N-1}$, and the higher the difficulty is, the more difficult it is to pass the corresponding stage.


If the sum of the difficulty levels of consecutive stages is greater than or equal to $M$, we call this section as 
interesting section
. That is, if $A_i + A_{i+1} + ... + A_j \geq M$, section $(i, j)$ is an interesting section.


Maps should always have at least $K$ interesting section.




In other words, the following conditions should be satisfied:




Let $T$ be the number of pairs $(i, j)$ satisfying the following conditions:
	


$0 \le i \le j \le N-1$


$A_{i} + A_{i+1} + ... + A_{j} \ge M$.






Then, $T \ge K$ for the given integer $K$.




To solve this problem, Soo Young requested help from KAIST RUN Spring Contest participants.


Since there is not much time left until the patch release, all Soo Young can do is 
add difficulty $X$ to all stages at once
 to make it more difficult. 


Your job is to find the smallest non-negative integer $X$ that satisfies these conditions.

## 예제 입력 1
```
3 20 5
4 0 4
```

## 예제 출력 1
```
16
```

## 예제 입력 2
```
5 30 4
1 2 3 4 5
```

## 예제 출력 2
```
6
```

## 예제 입력 3
```
4 32 4
8 7 5 9
```

## 예제 출력 3
```
9
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 4 | C++17 / 수정 | 2680 KB | 28 ms | 871 B | 3년 전 |
