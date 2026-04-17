# [17689. Candies](https://www.acmicpc.net/problem/17689)

## 문제
There are N candies in a row on the table. Each candy has a value called deliciousness. The deliciousness of the candy which is located i-th from the left is A
i
 (1 ≤ i ≤ N).


JOI-chan decided to eat some of these N candies. JOI-chan wants to maximize the sum of deliciousness of candies which she is going to eat.


However, JOI-chan thinks that just choosing candies greedily is not interesting, so she makes a rule that she cannot choose two consecutive candies simultaneously.


JOI-chan has not decided how many candies she eats, so JOI-chan wants to know, for each j (1 ≤ j ≤ ⌈N/2⌉), the maximum sum of deliciousness of candies when she eats j candies. Here ⌈x⌉ is the smallest integer larger than or equal to x.


Given the number of candies and the deliciousness of candies, write a program which calculates, for each j (1 ≤ j ≤ ⌈N/2⌉), the maximum sum of deliciousness of candies when she eats j candies.

## 예제 입력 1
```
5
3
5
1
7
6
```

## 예제 출력 1
```
7
12
10
```

## 예제 입력 2
```
20
623239331
125587558
908010226
866053126
389255266
859393857
596640443
60521559
11284043
930138174
936349374
810093502
521142682
918991183
743833745
739411636
276010057
577098544
551216812
816623724
```

## 예제 출력 2
```
936349374
1855340557
2763350783
3622744640
4439368364
5243250666
5982662302
6605901633
7183000177
7309502029
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Diamond 4 | C++17 / 수정 | 17764 KB | 24 ms | 531 B | 2년 전 |
