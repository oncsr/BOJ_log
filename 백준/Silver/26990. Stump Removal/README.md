# [26990. Stump Removal](https://www.acmicpc.net/problem/26990)

## 문제
Always thinking of the cows' grazing experience, FJ has found that he must remove N (1 ≤ N ≤ 50,000) unsightly stumps from the pasture. The stumps are conveniently arranged in a straight line and numbered 1..N with each stump having some height H_i (1 ≤ H_i ≤ 10,000).


FJ will use the traditional high explosives to destroy the stumps. These high explosives are formulated to destroy adjacent stumps as long as those adjacent stumps are strictly shorter than the nearest stump being destroyed. The blast can continue past the closest adjacent stump to the next adjacent stump if it is even shorter than the nearest stump just destroyed. As soon as a stump encountered by the blast wave is not shorter, though, no more destruction occurs on that side of the target stump (the other side follows the same rules with whatever stumps might appear there).


Consider a line of nine stumps with these heights:



              1 2 5 4 3 3 6 6 2



If FJ blows up the third stump (with height 5), then the second stump will also be destroyed (height 2) and the first stump (height 1) will also be destroyed. Likewise, the fourth stump (height 4) and fifth stump (height 3) will be destroyed since they are successively shorter, leaving the line like this:



              * * * * * 3 6 6 2


Two more explosives (at stumps 7 and 8) will destroy the rest.


Help FJ determine the minimum number of explosive charges he needs to destroy the stumps.

## 예제 입력 1
```
9
1
2
5
4
3
3
6
6
2
```

## 예제 출력 1
```
3
7
8
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Silver 5 | C99 / 수정 | 1112 KB | 8 ms | 377 B | 3년 전 |
