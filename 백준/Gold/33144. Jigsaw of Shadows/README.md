# [33144. Jigsaw of Shadows](https://www.acmicpc.net/problem/33144)

## 문제
They finally did it! The flat-earthers managed to teleport themselves to an idealized flat world where no one can make fun of them anymore.


In this world, there is a perfectly straight, infinite road that runs along the $x$-axis. Instead of a sun, they have something more illuminating: a gigantic flashlight elevated above the road, positioned infinitely far away to the west (negative $x$-axis). This flashlight beams light at a precise angle with respect to the ground, illuminating the entire road.


There are $N$ flatlanders standing proudly at distinct positions along the road. As the light strikes each of them, it casts a shadow extending eastward (toward the positive $x$-axis).




Eager to show off their flat-world knowledge, the citizens want to calculate how much of the road is covered by their shadows. However, with shadows potentially overlapping, they need your help to figure it out. Given the positions of the flatlanders and their heights, can you calculate the total length of the road covered by their shadows?

## 예제 입력 1
```
45 3
50 150
0 100
100 200
```

## 예제 출력 1
```
300
```

## 예제 입력 2
```
60 3
50 150
0 100
100 200
```

## 예제 출력 2
```
215.47
```

## 예제 입력 3
```
30 3
50 150
0 100
100 200
```

## 예제 출력 3
```
446.41016
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 4 | C++17 / 수정 | 2924 KB | 24 ms | 523 B | 1년 전 |
