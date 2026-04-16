# [32551. Composed Rhythms](https://www.acmicpc.net/problem/32551)

## 문제
Rhythm is an important part of music and it is crucial for aspiring musicians to gain understanding of it. As the skill of the musician advances, more complex rhythms are introduced to them. To ease the learning of musical passages, a method of simplifying rhythms can be helpful. One method is to reduce the rhythm into groups of twos and threes.


A rhythm is composed of multiple beats. A single beat does not make up a rhythm, as the beats depend on each other. The rhythm can be subdivided into smaller components. For example, a rhythm of $7$ beats can be subdivided into $4$ beats and $3$ beats, or alternatively into $2$, $3$, and $2$ beats. However, a rhythm of $7$ beats cannot be subdivided into $1$, $3$, and  $3$ beats, since one of the components does not form a rhythm.


This leaves $2$ as the smallest group size of beats we can use to decompose a rhythm, but if we only use groups of size $2$ then we cannot have an odd number of beats. Adding $3$ as a group size allows us to decompose any rhythm, even if it has an odd number of beats.


Given the number of beats in a rhythm, provide one decomposition of the rhythm into groups of sizes $2$ and $3$.

## 예제 입력 1
```
25
```

## 예제 출력 1
```
9
3 3 3 3 3 3 2 2 3
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Bronze 2 | C++17 / 수정 | 2020 KB | 12 ms | 208 B | 1년 전 |
