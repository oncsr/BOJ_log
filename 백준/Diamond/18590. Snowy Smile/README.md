# [18590. Snowy Smile](https://www.acmicpc.net/problem/18590)

## 문제
There are n pirate chests buried in Byteland, labeled by 1, 2, . . . , n. The i-th chest is located at point (x
i
, y
i
) on the plane, and its value is w
i
. Note that w
i
 can be negative since the pirate can put some poisonous gases into the chest. When you open the i-th pirate chest, you will get wi value.


You want to make money from these pirate chests. You can select a rectangle such that its sides are all parallel to the coordinate axes, and then open all the chests inside this rectangle or on its border. Note that you must open all the chests within that range regardless of whether their values are positive or negative. But you can choose a rectangle with nothing in it to get a zero sum.


Please write a program to find the maximum total value of a rectangle.

## 예제 입력 1
```
2
4
1 1 50
2 1 50
1 2 50
2 2 -500
2
-1 1 5
-1 1 1
```

## 예제 출력 1
```
100
6
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Diamond 5 | C++17 / 수정 | 2576 KB | 1476 ms | 2139 B | 3년 전 |
