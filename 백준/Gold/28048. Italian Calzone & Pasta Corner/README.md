# [28048. Italian Calzone & Pasta Corner](https://www.acmicpc.net/problem/28048)

## 문제
The Italian Calzone & Pasta Corner restaurant designed its menu having its dishes in a $R \times C$ two-dimensional grid, keeping dishes that go well together nearby each other. To eat, you choose a starting cell, and then repeatedly move up, down, left, or right to any of the four adjacent cells, getting any dishes you move through. Moving into already visited cells is allowed, but you don’t get the same dish again.


One day, Pierre, a foreign customer, showed up really hungry, and with a very strict etiquette background. He has a very specific order in which the dishes must be eaten. For example an appetizer, then an entree, then a main dish, then a salad, etc. So he assigned a distinct integer from $1$ to $R \times C$ to each dish in the menu grid, indicating the order in which he would eat the whole menu. Now he wants to choose and eat dishes following his order. Since the restaurant’s rules might prevent him from choosing the whole menu, he is fine with skipping some of the steps given by his order. Can you help him choose a meal with as many dishes as possible?

## 예제 입력 1
```
1 5
5 3 2 1 4
```

## 예제 출력 1
```
5
```

## 예제 입력 2
```
1 5
1 5 4 3 2
```

## 예제 출력 2
```
4
```

## 예제 입력 3
```
3 3
4 1 3
8 5 9
7 2 6
```

## 예제 출력 3
```
6
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 3 | C++17 / 수정 | 2096 KB | 12 ms | 1011 B | 2년 전 |
