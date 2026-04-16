# [32534. Hijerarhija](https://www.acmicpc.net/problem/32534)

## 문제
Krešimir has started studying corporate structures, including 
hierarchies
. He observed employees and their relationships within a company. In this case, we are only looking at 
superior–subordinate
 relationships, meaning relationships where one employee is directly superior to another employee in the company.


A hierarchy is a structure with $N$ employees and $N - 1$ superior–subordinate relationships, where there is one person who is directly or indirectly superior to all employees. In the observed company, there are also $N$ employees and $N - 1$ such relationships, but it is not certain whether this is a valid hierarchy or not.


Krešimir has asked you to help answer this question. He has recorded all the data in his notebook. Additionally, in his notebook, he will make $Q$ permanent changes by reversing one superior–subordinate relationship such that the subordinate becomes superior to their former superior. After each such change, it is necessary to answer the same question: is the current state a valid hierarchy?

## 예제 입력 1
```
3
1 2
1 3
3
1 2
1 2
1 3
```

## 예제 출력 1
```
DA
DA
DA
DA
```

## 예제 입력 2
```
4
2 1
2 3
1 4
4
4 1
4 1
3 2
1 4
```

## 예제 출력 2
```
DA
NE
DA
DA
NE
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 3 | C++17 / 수정 | 17320 KB | 672 ms | 776 B | 1년 전 |
