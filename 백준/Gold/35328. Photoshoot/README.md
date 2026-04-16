# [35328. Photoshoot](https://www.acmicpc.net/problem/35328)

## 문제
Farmer John is looking at his cows in a magical field and wants to take pictures of subsets of his cows.


The field can be seen as a $N \times N$ grid $(1 \leq N \leq 500)$, with a single stationary cow at each location. Farmer John's camera is capable of taking a picture of any $K \times K$ square that is part of the field $(1 \leq K \leq \min(N, 25))$.


At all times, each cow has a beauty value between $0$ and $10^6$. The attractiveness index of a picture is the sum of the beauty values of the cows contained in the picture.


The beauty value for every cow starts out as $0$, so the attractiveness index of any picture in the beginning is $0$.


At $Q$ times $(1 \leq Q \leq 3\cdot 10^{4})$, the beauty of a single cow will increase by a positive integer due to eating the magical grass that is planted on Farmer John's field.


Farmer John wants to know the maximum attractiveness index of a picture he can take after each of the $Q$ updates.

## 예제 입력 1
```
4 2
3
2 2 11
3 4 3
3 1 100
```

## 예제 출력 1
```
11
11
111
```

## 예제 입력 2
```
3 1
3
2 2 3
2 2 5
2 2 7
```

## 예제 출력 2
```
3
5
7
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 4 | C++17 / 수정 | 3980 KB | 32 ms | 485 B | 1달 전 |
