# [32564. Eradication Sort](https://www.acmicpc.net/problem/32564)

## 문제
The members of the No-Weather-too-Extreme Recreational Climbing society completed their first successful summit seven years ago to this day!


At the time, we took a picture of all the members standing together in one row. However, the photograph looks messy, as the climbers were not standing in order of height, and we have no way to reorder them.


We will need to cut some of the climbers out of the picture.




Figure E.1: This picture of 7 (formerly 11) climbers was edited to solve Sample Input 3.


An optimal solution minimises the size and number of visible gaps in the photo. We define the 
cost
 as the sum of the squares of the lengths of gaps left in the edited photo. For example, if two individual climbers are removed from the photo and one pair of adjacent climbers are removed, the total 
cost
 is $1^2 + 1^2 + 2^2 = 6$.


Find the minimum possible cost you can reach by removing climbers.

## 예제 입력 1
```
7
1 2 3 0 5 6 7
```

## 예제 출력 1
```
1
```

## 예제 입력 2
```
9
4 5 6 4 2 3 6 6 6
```

## 예제 출력 2
```
8
```

## 예제 입력 3
```
11
3 6 12 7 7 7 6 8 10 5 5
```

## 예제 출력 3
```
6
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Diamond 5 | C++17 / 수정 | 7468 KB | 36 ms | 1683 B | 1년 전 |
