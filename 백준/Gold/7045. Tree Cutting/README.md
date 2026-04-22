# [7045. Tree Cutting](https://www.acmicpc.net/problem/7045)

## 문제
After Farmer John realized that Bessie had installed a "tree-shaped" network among his N (1 <= N <= 10,000) barns at an incredible cost, he sued Bessie to mitigate his losses. 


Bessie, feeling vindictive, decided to sabotage Farmer John's network by cutting power to one of the barns (thereby disrupting all the connections involving that barn). When Bessie does this, it breaks the network into smaller pieces, each of which retains full connectivity within itself. In order to be as disruptive as possible, Bessie wants to make sure that each of these pieces connects together no more than half the barns on FJ. 


Please help Bessie determine all of the barns that would be suitable to disconnect.

## 예제 입력 1
```
10
1 2
2 3
3 4
4 5
6 7
7 8
8 9
9 10
3 8
```

## 예제 출력 1
```
3
8
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 3 | C++17 / 수정 | 2692 KB | 4 ms | 594 B | 2년 전 |
