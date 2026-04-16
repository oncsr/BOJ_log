# [31393. Urban geography](https://www.acmicpc.net/problem/31393)

## 문제
Android Vasya prepares a project in Urban geography. The aim of the project is to improve the infrasructure of the city he lives in.


Now the city consists of $n$ districts, some of which are connected by roads. Using these roads one can get from any district to any other district of the city by car. Vasya thinks that such big amount of roads makes citizens use their own cars instead of walking or cycling. He wants to close as many roads for cars as possible and turn them into boulevards. Of course, Vasya wants to keep the possibility to get from any district to any other district of the city by car using roads.


Now citizens pay for using roads, and prices for different roads may vary very much. Vasya thinks that leaving open some expensive and some cheap roads at the same time is not a good idea beacuse it can increase social tension in the city. That's why he wants to minimize the price spread between the most expensive and the cheapest roads. Help Vasya choose the roads to keep open.

## 예제 입력 1
```
3 3
1 2 1
2 3 3
3 1 4
```

## 예제 출력 1
```
2 3
```

## 예제 입력 2
```
4 5
1 2 1
2 3 1
1 3 2
1 4 2
2 4 1
```

## 예제 출력 2
```
1 2 5
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Diamond 5 | Java 11 / 수정 | 355468 KB | 3724 ms | 3823 B | 7달 전 |
