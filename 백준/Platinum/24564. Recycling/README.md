# [24564. Recycling](https://www.acmicpc.net/problem/24564)

## 문제
Heck S. Quincy (or Hex as his friends call him) is in charge of recycling efforts in the Quad Cities within the greater Tri-state area as well as the Twin Cities in the Lone Star State.  One of the programs he oversees is the placement of large recycling bins at various locations in the cities.  Transporting these bins is very expensive so he tries to keep them at any given location for as long as possible, emptying them once a week. He's willing to keep a bin at a given location as long as it is full at the end of each week.


Hex has very reliable estimates of the amount of recyclable materials (in cubic meters) that he can expect each week at each location.  Given this information he would like to know when to install the recycling bin of an appropriate size to maximize the amount of material recycled. He will keep the bin at that location up to (but not including) the week when they don't expect it to be filled to capacity.


For example, suppose Hex has the following estimates for the next seven weeks: $2\ 5\ 7\ 3\ 5\ 10\ 2$. Hex has several options for placing bins, including:




A capacity-$2$ bin from week $1$ until week $7$, recycling $14\textrm{m}^3$


A capacity-$5$ bin from week $2$ until week $3$, recycling $10\textrm{m}^3$


A capacity-$3$ bin from week $2$ until week $6$, recycling $15\textrm{m}^3$ (this is the maximum possible)




Hex would not place a capacity-$5$ bin from week $2$ until week $6$, since it would not be filled in week $4$.

## 예제 입력 1
```
7
2 5 7 3 5
10 2
```

## 예제 출력 1
```
2 6 15
```

## 예제 입력 2
```
8
2 5 7 3 5
10 2 4
```

## 예제 출력 2
```
1 8 16
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Platinum 5 | C++17 / 수정 | 4640 KB | 20 ms | 901 B | 1년 전 |
