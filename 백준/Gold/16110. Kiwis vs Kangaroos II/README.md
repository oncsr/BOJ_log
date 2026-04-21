# [16110. Kiwis vs Kangaroos II](https://www.acmicpc.net/problem/16110)

## 문제
Last year’s feud between the Kiwis and the Kangaroos is still ongoing. Somehow, the word game did not seem to squash the rivalry that has formed between them! Again, they have turned to you to settle this.


You have decided that you will hold a head-to-head programming tournament. Each country, Australia and New Zealand, will send some number of programmers (not necessarily the same number) to compete in the tournament. The programmers from Australia are called ‘kangaroos’, and the programmers from New Zealand are called ‘kiwis’. You have set up n stadiums to hold the tournament. The tournament will take place in n separate rounds.


In each round, n different kangaroos will battle against n different kiwis, with one kangaroo battling one kiwi in each stadium (n battles per round, so n
2
 battles in total). To keep things interesting for the spectators, no programmer may battle in any given stadium more than once, though they may battle against the same opponent multiple times in different rounds.


The king of the kangaroos has nominated m kangaroos. The ith kangaroo must fight in exactly t
i
 different battles. Similarly, the queen of the kiwis has nominated k kiwis. The ith kiwi must fight in exactly s
i
 battles.


Find a valid tournament schedule that satisfies the above constraints.

## 예제 입력 1
```
2 2 2
2 2
2 2
```

## 예제 출력 1
```
1v2 2v1
2v1 1v2
```

## 예제 입력 2
```
2 4 3
1 1 1 1
1 2 1
```

## 예제 출력 2
```
1v1 2v2
3v2 4v3
```

## 예제 입력 3
```
4 5 6
4 3 3 3 3
4 3 3 3 2 1
```

## 예제 출력 3
```
3v2 4v1 5v6 1v3
1v3 3v4 2v1 5v2
4v1 5v2 1v4 2v5
2v4 1v3 3v5 4v1
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 2 | C++17 / 수정 | 2916 KB | 12 ms | 1184 B | 2년 전 |
