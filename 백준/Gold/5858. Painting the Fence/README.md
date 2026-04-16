# [5858. Painting the Fence](https://www.acmicpc.net/problem/5858)

## 문제
Farmer John has devised a brilliant method to paint the long fence next to his barn (think of the fence as a one-dimensional number line).  He simply attaches a paint brush to his favorite cow Bessie, and then retires to drink a cold glass of water as Bessie walks back and forth across the fence, applying paint to any segment of the fence that she walks past.
Bessie starts at position 0 on the fence and follows a sequence of N moves (1 <= N <= 100,000).  Example moves might be "10 L", meaning Bessie moves 10 units to the left, or "15 R", meaning Bessie moves 15 units to the right.  Given a list of all of Bessie's moves, FJ would like to know what area of the fence gets painted with at least two coats of paint (since areas painted with only one coat of paint may wash off during heavy rain). Bessie will move at most 1,000,000,000 units away from the origin during her walk.

## 예제 입력 1
```
6
2 R
6 L
1 R
8 L
1 R
2 R
```

## 예제 출력 1
```
6
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 3 | Java 11 / 수정 | 46376 KB | 520 ms | 1690 B | 1년 전 |
