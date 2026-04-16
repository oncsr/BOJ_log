# [32580. P||k Cutting](https://www.acmicpc.net/problem/32580)

## 문제
The farmer needs some pork to be packed. This may take several days, so the farmer has allocated $N$ possible days when the packing can be performed. The whole packing process needs to be completed in a sequence of consecutive days with at least one day. This sequence of days, also called an interval, may not necessarily contain all allocated days.


The farmer has called the bulls and donkeys to help and to do the entire packing job. The bulls and donkeys do not work for free, so the farmer assigned to each day a particular number of cookies he is willing to pay, if the animals work on that day.


The bulls, not being the smartest animals, protested against using such advanced mathematics as summing several numbers of cookies in several consecutive days. They insist on being paid a fixed amount of $K$ cookies, no matter when or for how long they work.


On the other hand, the donkeys considered the sum to be a too ordinary mathematical operation and required that they are paid the bitwise OR of the numbers of cookies offered for the individual days.


Bitwise OR of two given integers is computed by taking their binary representation and keeping the digit 1 in the result on exactly those positions where at least one of the given two integers has digit 1. For instance, bitwise OR of $9$ and $5$ is $13$.


Furthermore, the bulls and donkeys are willing to work only when they are both paid the exact same total amount. The farmer, finding himself unwilling to deal with the animals any longer, agreed to their conditions and wants to know how many options does he have for scheduling the work. As such, your task is to count the total number of distinct non-empty intervals of days on which the animals are willing to work. Counted intervals may overlap.

## 예제 입력 1
```
5 3
1 2 1 2 3
```

## 예제 출력 1
```
11
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 1 | C++17 / 수정 | 7680 KB | 2812 ms | 1055 B | 1년 전 |
