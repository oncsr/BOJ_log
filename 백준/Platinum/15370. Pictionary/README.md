# [15370. Pictionary](https://www.acmicpc.net/problem/15370)

## 문제
There is a planet, in a yet undiscovered part of the universe, with a country inhabited solely by mathematicians. In this country, there are a total of N mathematicians, and the interesting fact is that each mathematician lives in their own city. Is it also interesting that no two cities are connected with a road, because mathematicians can communicate online or by reviewing academic papers. Naturally, the cities are labeled with numbers from 1 to N.


Life was perfect until one mathematician decided to write an academic paper on their smartphone. The smartphone auto-corrected the word “self-evident” to “Pictionary” and the paper was published as such. Soon after, the entire country discovered pictionary and wanted to meet up and play, so construction work on roads between cities began shortly.


The road construction will last a total of M days, according to the following schedule: on the first day, construction is done on roads between all pairs of cities that have M as their greatest common divisor. On the second day, construction is done on roads between all pairs of cities that have M-1 as their greatest common divisor, and so on until the Mth day when construction is done on roads between all pairs of cities that are co-prime. More formally, on the ith day, construction is done on roads between cities a and b if gcd(a, b) = M - i + 1.


Since the mathematicians are busy with construction work, they’ve asked you to help them determine the minimal number of days before a given pair of mathematicians can play pictionary together.

## 예제 입력 1
```
8 3 3
2 5
3 6
4 8
```

## 예제 출력 1
```
3
1
2
```

## 예제 입력 2
```
25 6 1
20 9
```

## 예제 출력 2
```
4
```

## 예제 입력 3
```
9999 2222 2
1025 2405
3154 8949
```

## 예제 출력 3
```
1980
2160
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Platinum 1 | C++17 / 수정 | 22128 KB | 96 ms | 1433 B | 6달 전 |
