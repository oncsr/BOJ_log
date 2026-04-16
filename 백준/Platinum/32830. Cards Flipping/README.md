# [32830. Cards Flipping](https://www.acmicpc.net/problem/32830)

## 문제
The magician $B$ has $n$ cards in a row on a desk. Each card has two sides with colors. The top side of a card is the side facing upwards. The bottom side of a card is the side facing downwards. Each side of a card has one color. We want to find the maximum number of distinct colors on the top sides. In the following example, we are given $5$ cards in a row on a desk. The colors of the top sides of the cards are violet, red, violet, violet, and red from the left to the right as shown in the following figure. The colors of the bottom sides of the cards are red, violet, blue, yellow, and red from the left to the right.




If we flip a card, then the top side and the bottom side of the card are exchanged. If we flip the $3$
rd
 and the $4$
th
 card from the left, then the colors of the cards on the top sides become like the following.




The number of distinct colors on the top sides becomes $4$ which is the maximum for the example.


Given $n$ cards placed in a row on a desk and the colors on the sides of cards, write a program to output the maximum number of distinct colors on the top sides.

## 예제 입력 1
```
5
0 1 0 0 1
1 0 2 3 1
```

## 예제 출력 1
```
4
```

## 예제 입력 2
```
2
3 5
5 1
```

## 예제 출력 2
```
2
```

## 예제 입력 3
```
3
0 1 0
1 0 2
```

## 예제 출력 3
```
3
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Platinum 5 | Java 11 / 수정 | 106776 KB | 936 ms | 1953 B | 1년 전 |
