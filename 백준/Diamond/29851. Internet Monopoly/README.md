# [29851. Internet Monopoly](https://www.acmicpc.net/problem/29851)

## 문제
There are $N$ cities in the Very Proud Kingdom, numbered $1, \ldots, N$.


All the internet cables in the country are managed by 
Internet Operations Incorporated
, or IOI. Internet service providers rent from IOI the right to use the cables.


The price list of IOI has the following structure: the yearly rent for some cables is $100\,000$ Euros; for the remaining cables it's $200\,000$ Euros. Each service provider always rents cables in such a way that all cities are connected to each other (possibly indirectly) by the rented cables and the total amount of rent is the lowest possible. IOI would like all renters to rent the exact same set of cables; this would make it easier for IOI to manage its cable network.


Every now and then, IOI lays new cables, and then the question arises: Is it possible to set the price list in such a way that exactly $K$ cables have the yearly rent equal to $100\,000$ Euros, and it's quaranteed that all the renters will rent access to the exact same set of cables?


More formally, your program needs to process queries of the following types:




Given cities $U$ and $V$. IOI lays a new cable between cities $U$ and $V$.


Given $K$. Determine whether it is possible to set the price list according to the conditions above.




In the beginning, before the first query, there are no cables in the country. You may assume that queries of the second type will only be given once all the cities in the country are connected to each other (possibly indirectly) by cables laid by IOI. You may also assume that IOI will never lay a cable between two cities where there already is a cable.

## 예제 입력 1
```
9 22
+ 1 2
+ 1 3
+ 2 3
+ 2 4
+ 3 4
+ 4 5
+ 5 6
+ 6 7
+ 5 7
+ 7 8
+ 7 9
? 0
? 9
? 3
? 2
? 6
? 5
? 7
? 1
? 10
? 4
? 11
```

## 예제 출력 1
```
EI
EI
EI
EI
JAH
JAH
JAH
EI
EI
EI
EI
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Diamond 5 | Java 15 / 수정 | 168000 KB | 1012 ms | 3428 B | 1달 전 |
