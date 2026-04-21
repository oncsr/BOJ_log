# [24241. Elder price robot](https://www.acmicpc.net/problem/24241)

## 문제
The idea behind your latest business adventure, BarGain Overview (BGO), is to collect the history of prices for a certain item that is available for sale on the web. The 
BarGain score
 of a particular day is defined as the number of days since the price was lower or equal to today's price. The worst BarGain score is thus $1$, and if the price is strictly better than all previous prices ever recorded, then it is 
infinity
. You want to report the BarGain score to your customers to help them identify a good buy.

## 예제 입력 1
```
6
9 10 11 9 12 11
```

## 예제 출력 1
```
3
2
1
infinity
1
infinity
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 4 | C++17 / 수정 | 6780 KB | 88 ms | 533 B | 2년 전 |
