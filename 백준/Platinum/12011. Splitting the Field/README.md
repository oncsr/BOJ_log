# [12011. Splitting the Field](https://www.acmicpc.net/problem/12011)

## 문제
Farmer John's \(N\) cows (\(3 \leq N \leq 50,000\)) are all located at distinct positions in his two-dimensional field. FJ wants to enclose all of the cows with a rectangular fence whose sides are parallel to the x and y axes, and he wants this fence to be as small as possible so that it contains every cow (cows on the boundary are allowed).


FJ is unfortunately on a tight budget due to low milk production last quarter. He would therefore like to enclose a smaller area to reduce maintenance costs, and the only way he can see to do this is by building two enclosures instead of one. Please help him compute how much less area he needs to enclose, in total, by using two enclosures instead of one. Like the original enclosure, the two enclosures must collectively contain all the cows (with cows on boundaries allowed), and they must have sides parallel to the x and y axes. The two enclosures are not allowed to overlap -- not even on their boundaries. Note that enclosures of zero area are legal, for example if an enclosure has zero width and/or zero height.

## 예제 입력 1
```
6
4 2
8 10
1 1
9 12
14 7
2 3
```

## 예제 출력 1
```
107
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Platinum 5 | C++17 / 수정 | 3464 KB | 20 ms | 1819 B | 2년 전 |
