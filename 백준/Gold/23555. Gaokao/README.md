# [23555. Gaokao](https://www.acmicpc.net/problem/23555)

## 문제
Roundgod is about to attend Gaokao (National Unified Examination for Admissions to General Universities and Colleges) and his dream school is Zhejiang University. He sees an interesting problem while he is studying Math, which is a problem related to Pascal's Triangle.


The definition of Pascal's Triangle is given below:


The first element and the last element of each row in Pascal's Triangle is $1$, and the $m_{th}$ element of the $n_{th}$ row equals to the sum of the $m_{th}$ and the ($m-1$)$_{th}$ element of the ($n-1$)$_{th}$ row. Here's an example of a 5 levels Pascal's Triangle .


$$1$$ $$1\quad 1$$ $$1 \quad2\quad 1$$ $$1 \quad3 \quad3\quad 1$$ $$1 \quad4\quad 6\quad 4 \quad1$$


In the task, Roundgod is required to calculate how many elements in the $126_{th}$ row of Pascal's Triangle are odd numbers.


After solving it, Roundgod thinks of a harder version of this problem. He gives you many requests about similar questions but the row number will be bigger. Please calculate that how many elements in the $k_{th}$ row of Pascal's Triangle are odd numbers.

## 예제 입력 1
```
3
3
4
5
```

## 예제 출력 1
```
2
4
2
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 3 | C++17 / 수정 | 2020 KB | 0 ms | 348 B | 1년 전 |
