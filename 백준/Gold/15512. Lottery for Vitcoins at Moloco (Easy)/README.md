# [15512. Lottery for Vitcoins at Moloco (Easy)](https://www.acmicpc.net/problem/15512)

## 문제
At the end of each month, Moloco employees participate in a simple lottery for extra employee perks.


As a valuable employee of Moloco, you receive 
n
 lottery tickets where each ticket 
i
 has a prize worth 
w
i
 > 0 Vitcoins.


In addition, each ticket 
i
 is paired with a coin that flips heads with probability 
p
i
 (assume 0 < 
p
i
 < 1) and tails with probability 1-
p
i
. 


Each coin flip is independent.


At each step, you choose a ticket among those that you have not chosen yet, and claim the prize immediately. Then, you flip the coin that is paired with the ticket; if it is heads, the lottery continues and you can pick another ticket, and so on until you run out of tickets. If it is tails, then the lottery ends immediately, and you get to keep all the Vitcoins you have collected so far.


You know all the values 
w
i
 and 
p
i
 for all 
i
, and want to know a permutation of the tickets such that picking them in this order maximizes the expected number of Vitcoins you win.

## 예제 입력 1
```
3
2 3000
5 5000
7 2000
```

## 예제 출력 1
```
2 3 1
```

## 예제 입력 2
```
3
3 5000
5 1500
7 2000
```

## 예제 출력 2
```
3 1 2
```

## 예제 입력 3
```
3
1 4000
1 5000
1 5000
```

## 예제 출력 3
```
2 3 1
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 2 | Java 11 / 수정 | 16396 KB | 148 ms | 1723 B | 1년 전 |
