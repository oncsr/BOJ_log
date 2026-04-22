# [28346. XOR Necklace](https://www.acmicpc.net/problem/28346)

## 문제
Frograms, Inc. has been busy developing necklaces with brand-new design and feature. Every programmer working at Frograms now wears this necklace. A necklace consists of multiple beads stringed by a thread, as seen below. Each bead is given a number between $0$ to $10^9$ (inclusive).




Most of the programmers have left for their summer vacation, and there is only a few programmers in the office today. So they decided to play a game using their own necklace to decide who will buy lunch for everyone. The rule is simple: for each pair of consecutive beads in the necklace, we take sum of their numbers. A programmer’s score is defined as the XOR(denoted as $\oplus$) of all those sums. The programmer with the lowest score loses! More formally, if there are $N$ beads and their value is denoted by $A_1$, $A_2$, $\cdots$, $A_N$ in the order they are stringed together, then the score is:


$$(A_1 \oplus A_2) + (A_2 \oplus A_3) + \dots + (A_{N-1} \oplus A_N) +(A_N \oplus A_1)$$


However, you, the most talented programmer in Frograms, Inc., is going to cheat the game by removing zero or more beads to maximize the score. What is the maximum score if you are allowed to remove some of the beads in a given necklace? Note that you cannot reorder the beads, nor leave one or less beads in a necklace.

## 예제 입력 1
```
1
6
2 31 23 27 10 20
```

## 예제 출력 1
```
118
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 4 | C++17 / 수정 | 2020 KB | 4 ms | 329 B | 2년 전 |
