# [7742. Railway](https://www.acmicpc.net/problem/7742)

## 문제
Several years ago, the government of the well-known country Byteland decided to build a railway network to make public transport in the country a little bit easier. However, due to insufficient funds, the minister of the transport wanted the "network" to be as simple as possible. Hence, the following requirements needed to be met:




Every train connects directly two cities, there are no stops in between.


Every train operates in both directions (i.e., the train going from A to B goes from B to A as well) and the prices for the two directions are the same.


It is possible to go from every city to every other city (possibly with some changes).


The number of trains is the minimum possible.




Now, the railway network has been finished and the first customers can enjoy the speed and the reliability of the Byteland railway. The only problem is the issuing of tickets: When the customer travels from A to B using 42 trains, the assistant has to sum up the prices of the trains, which is really anoying. What is more, the assistant can make a mistake. To solve the problem, the director of the Byteland Railway Corporation hired you. Your task is to write a program which calculates the price of the tickets.


First, the program reads the description of the railway and the prices of the trains. Then, the program is given several queries to answer: each query is a pair of cities x
i
 and y
i
 and the answer is the price of the ticket from x
i
 to y
i
.

## 예제 입력 1
```
4 3
1 2 5
2 3 6
2 4 1
1 2
2 3
1 3
```

## 예제 출력 1
```
5
6
11
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Platinum 5 | C++17 / 수정 | 17900 KB | 952 ms | 1880 B | 1년 전 |
