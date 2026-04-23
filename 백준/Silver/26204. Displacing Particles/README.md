# [26204. Displacing Particles](https://www.acmicpc.net/problem/26204)

## 문제
A square has its vertices at the coordinates $(0, 0)$, $(0, 2^N)$, $(2^N , 2^N )$, $(2^N , 0)$. Each vertex has an attractor. A particle is placed initially at position $(2^{N-1} , 2^{N-1})$. Each attractor can be activated individually, any number of times. When an attractor at position $(i, j)$ is activated, if a particle is at position $(p, q)$, it will be moved to the midpoint between $(i, j)$ and $(p, q)$.


Given $N$ and a point $(x, y)$, calculate the least number of times you have to activate the attractors so that the particle ends up at position $(x, y)$.

## 예제 입력 1
```
1 1 1
```

## 예제 출력 1
```
0
```

## 예제 입력 2
```
4 12 4
```

## 예제 출력 2
```
1
```

## 예제 입력 3
```
4 3 1
```

## 예제 출력 3
```
3
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Silver 1 | C++17 / 수정 | 2020 KB | 0 ms | 339 B | 3년 전 |
