# [21376. Rektangelmagi](https://www.acmicpc.net/problem/21376)

## 문제
En 
magisk sekvens
 av längd $n + 1$ är en sekvens av tal $a, a + d, a + 2d, ..., a + nd$ för två rationella tal $a$ och $d$, t.ex. $2, 5.5, 9, 12.5$ eller $5, 5, 5$ eller $2, 1, 0, -1, -2$.


En 
magisk rektangel
 av storlek $R \times C$ är en rektangel där varje rad och kolumn är en magisk sekvens.


Givet en rektangel av heltal där vissa av talen är bortsuddade, avgör om det går att fylla i dessa bortsuddade tal så att rektangeln är en magisk rektangel.

## 예제 입력 1
```
3 5
. . 3 . 5
. . . 5 .
. . . . 7
```

## 예제 출력 1
```
1 2 3 4 5
2 3 4 5 6
3 4 5 6 7
```

## 예제 입력 2
```
1 6
4 . . 0 . .
```

## 예제 출력 2
```
4 8/3 4/3 0 -4/3 -8/3
```

## 예제 입력 3
```
1 4
1 2 . 2
```

## 예제 출력 3
```
ej magisk
```

## 예제 입력 4
```
3 3
1 . .
. 2 .
. . 3
```

## 예제 출력 4
```
1 0 -1
3 2 1
5 4 3
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Unrated | C++17 / 수정 | 2036 KB | 0 ms | 11920 B | 2년 전 |
