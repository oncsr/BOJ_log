# [24953. Reconstruction Project](https://www.acmicpc.net/problem/24953)

## 문제
JOI Town is an industrial area which had flourished some time ago. In order to transport products, many stations and railway tracks were constructed. Though it declined, there remain the stations and the railway tracks which are not used any more


There are $N$ stations in JOI Town, numbered from $1$ to $N$. There remain $M$ railway tracks. The $i$-th railway track ($1 ≤ i ≤ M$) connects the station $A_i$ and the station $B_i$ bidirectionally. The width of the $i$-th railway track is $W_i$. It is possible to travel from any station to any other station using railway tracks.


You are the mayor of JOI Town. You are planning to attract a railroad company using the remaining stations and railway tracks, and revive the JOI Town as the town of railway. Then, $Q$ railroad companies applied for this revival project. However, the width of the railway track for trains varies for different companies. It turns out that they need to reconstruct the railway tracks so that the width of the railway tracks of JOI Town matches the width of the railway tracks for the trains of a company.


The width of the railway tracks for the trains of the railroad company $j$ (1 ≤ j ≤ Q) is Xj . To attract the railroad company $j$, it is required that the following condition is satisfied.


Condition
 It is possible to travel from any station to any other station using railway tracks of width $X_j$ only.


In order to satisfy the above condition, you can reconstruct the railway tracks as many times as needed.


Reconstruction
 You choose a railway track. Then you reconstruct the chosen track so that its width will be increased or decreased by $1$. The cost is $1$. However, if the width of a railway track is $1$, it is impossible to decrease the width further.


In order to decide on the company to be attracted, you want to estimate the minimum cost to attract each railroad company.


White a program which, given information on the stations, the railway tracks, and the railroad companies, calculates the minimum cost to attract each railroad company.

## 예제 입력 1
```
5 10
1 2 8
1 3 13
1 4 5
1 5 11
1 5 3
2 3 7
2 4 15
3 4 6
3 5 6
4 5 2
6
3
6
8
10
13
17
```

## 예제 출력 1
```
8
2
5
10
9
21
```

## 예제 입력 2
```
3 4
1 2 1
1 2 4
2 3 2
2 3 4
4
1
2
3
4
```

## 예제 출력 2
```
1
1
2
0
```

## 예제 입력 3
```
10 20
6 7 914727791
1 8 771674531
3 5 632918108
5 9 329296846
1 7 237501112
4 9 303328173
2 6 216298255
2 10 504024991
3 8 158236886
1 10 10176179
8 9 918271145
3 6 217165898
3 6 624543444
4 9 70147274
8 9 976983490
6 9 210108505
2 9 972711062
1 10 564567289
3 7 411395464
4 7 952470985
10
115721165
198969744
356664401
429802521
513343279
610443927
741016686
786597783
898772266
903568946
```

## 예제 출력 3
```
1121073688
761832468
1026806785
1316097872
1321500065
1445238392
1637513141
1621778548
1733953031
1738749711
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Diamond 3 | C++17 / 수정 | 10140 KB | 1072 ms | 2306 B | 1년 전 |
