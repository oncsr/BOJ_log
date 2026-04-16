# [26455. Pizza delivery](https://www.acmicpc.net/problem/26455)

## 문제
JAG Pizza is the famous pizza shop. Since the number of delivery orders has been increasing, it has been busier than before.


One day, several orders came to this shop at the same time! There were $N$ orders, and $N$ customers who placed the order. The $i$-th customer placed the $i$-th order.


Through past orders, this shop knows information for each customer. For the $i$-th customer, it takes $t_i$ hours for delivering the pizza from the shop, and also takes $t_i$ hours for going back to the shop. Moreover, his or her "irritability" is $a_i$. The bigger irritability a person has, the easier to be angry.


JAG Pizza has to deliver orders for customers, and keep their minds on less customer stress. To formulate the amount of stress which the $i$-th customer feels, let $h_i$ be the time from order to delivery, and let $p_i$ be the number of other customers whose delivery time is faster than that of $i$-th customer. The amount of stress for the $i$-th customer ($s_i$) is formulated as follows: $s_i = a_i \times (h_i + p_i)$.


For less customer stress, and gaining high satisfaction rates, a better delivery plan is necessary. When you think about it, you must take the following things into account:




There is only one delivery person.


A delivery person cannot deliver several orders in parallel. It means that he or she can deliver a single order at once, and when achieved, he or she gets back to the shop for delivering the next order.


You can assume that it tooks no time for preparing an order, passing it from the shop to a delivery person, and passing it from a delivery person to a customer.




You are the delivery planner of JAG Pizza. Above these information and conditions, you have to minimize the total amount of stress for all customers.

## 예제 입력 1
```
3
10 3
3 8
4 2
```

## 예제 출력 1
```
124
```

## 예제 입력 2
```
10
17 62
30 79
99 2
88 57
42 46
84 11
44 60
21 98
68 63
17 54
```

## 예제 출력 2
```
118250
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 3 | C++17 / 수정 | 3588 KB | 28 ms | 508 B | 1년 전 |
