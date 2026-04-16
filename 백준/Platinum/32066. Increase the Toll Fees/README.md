# [32066. Increase the Toll Fees](https://www.acmicpc.net/problem/32066)

## 문제
The ICPC Kingdom is a big kingdom with $N$ cities, numbered from $1$ to $N$. The charm of the ICPC Kingdom lies in its beautiful sceneries in the kingdom. To promote those sceneries, the King of the ICPC Kingdom decided to make $M$ toll roads, numbered from $1$ to $M$, near the scenic views for the tourists to enjoy. To use toll road $i$ that connects city $U_i$ to $V_i$ bidirectionally, one must pay $W_i$. It is possible to travel from one city to any other city using these toll roads.


Although those toll roads have been built and can be used, they still do not attract tourists. The King decided to make a promotion, where one can 
pay in advance
 for the toll roads they want to use and can use it 
multiple times
 as long as they do not leave the ICPC Kingdom.


This idea can finally attract tourists, but there’s a strange behaviour happening. All of the tourists only pay for the set of toll roads that gives the minimum total pay which allows them to travel from one city to any other city regardless of the distance. Interestingly, such a set of toll roads is 
unique
 under current toll pricing. This strange behaviour does not fully expose the kingdom’s scenery to the tourists.


To promote more scenery, the King decided to increase the price of some toll roads. If toll road $i$ is used by the tourists’ strange behaviour before the toll price increase, then after the price increase, the King 
must ensure
 toll road $i$ is 
not used
 by the tourists’ strange behaviour. For stability, the King also wants the total price increase across all toll roads to be as small as possible.


The King asked you to calculate what is the minimum total price increase to fulfill the King’s plan or report that it is impossible to do so.

## 예제 입력 1
```
4 6
1 2 2
1 3 5
1 4 5
2 3 3
2 4 5
3 4 4
```

## 예제 출력 1
```
9
```

## 예제 입력 2
```
3 4
1 2 3
2 3 4
1 3 5
1 3 10
```

## 예제 출력 2
```
-1
```

## 예제 입력 3
```
5 10
1 2 14
1 3 14
1 4 9
1 5 15
2 3 8
2 3 10
2 4 13
3 4 8
4 5 10
4 5 15
```

## 예제 출력 3
```
21
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Platinum 1 | Java 11 / 수정 | 140600 KB | 1472 ms | 3117 B | 10달 전 |
