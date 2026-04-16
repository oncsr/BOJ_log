# [18877. Social Distancing](https://www.acmicpc.net/problem/18877)

## 문제
Farmer John is worried for the health of his cows after an outbreak of the highly contagious bovine disease COWVID-19.


In order to limit transmission of the disease, Farmer John's $N$ cows ($2 \leq N \leq 10^5$) have decided to practice "social distancing" and spread themselves out across the farm. The farm is shaped like a 1D number line, with $M$ mutually-disjoint intervals ($1 \leq M \leq 10^5$) in which there is grass for grazing. The cows want to locate themselves at distinct integer points, each covered in grass, so as to maximize the value of $D$, where $D$ represents the distance between the closest pair of cows. Please help the cows determine the largest possible value of $D$.

## 예제 입력 1
```
5 3
0 2
4 7
9 9
```

## 예제 출력 1
```
2
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 3 | C++17 / 수정 | 3588 KB | 44 ms | 570 B | 1년 전 |
