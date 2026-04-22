# [7882. Skyscrapers](https://www.acmicpc.net/problem/7882)

## 문제
In a seaside village, there is an avenue of skyscrapers. Each skyscrapers is 100m wide and has certain height. Due to very high price of parcels, any two consecutive skyscrapers are adjacent. The avenue lies close to the beach so the street is exactly at the sea level.


Unfortunately, this year, due to the global warming, the sea level started to increase by one meter each day. If the skyscraper height is no greater than the current sea level, it is considered flooded. A region is a maximal set of non-flooded, adjacent skyscrapers. This term is of particular importance, as it is sufficient to deliver goods (like current, carrots or cabbages) to any single skyscraper in each region. Hence, the city major wants to know how many regions there will be in the hard days that come.


An example of an avenue with 5 skyscrapers after 2 days is given below.

## 예제 입력 1
```
2
3 3
1 2 3
1 2 3
5 3
1 3 5 1 3
0 2 4
```

## 예제 출력 1
```
1 1 0
1 2 1
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 4 | C++17 / 수정 | 22312 KB | 688 ms | 983 B | 3년 전 |
