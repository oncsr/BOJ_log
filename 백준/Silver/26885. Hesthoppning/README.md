# [26885. Hesthoppning](https://www.acmicpc.net/problem/26885)

## 문제
De snela hestarna Hsara och Pascal bor tillsammans i en tvådimensionell hage av storlek $N$ rader och $M$ kolumner. Hagen är omgiven av ett stort stängsel, men innanför det så finns det rutor där hestarna kan hoppa fritt. De vill dock båda undvika att hoppa på rutor där det ligger stora stenar.


För de som spelat schack så är det välkänt att ett hopp går till genom att ta två steg i en riktning och ett steg i en riktning vinkelrät mot den första. Det är möjligt att hoppa över stenar, men rutan som man landar i måste vara fri. Givet hur hagen ser ut, och var hestarna befinner sig från början, så vill de veta om det är möjligt för dem att träffas. De kan träffas om det finns något sätt de kan hoppa på så att de hamnar på samma ruta. Hjälp dem att ta reda på det.

## 예제 입력 1
```
2 2
H.
.H
```

## 예제 출력 1
```
NEJ
```

## 예제 입력 2
```
3 3
H.H
...
.#.
```

## 예제 출력 2
```
JA
```

## 예제 입력 3
```
3 3
H#H
...
.#.
```

## 예제 출력 3
```
NEJ
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Silver 1 | C++17 / 수정 | 3260 KB | 12 ms | 1362 B | 3년 전 |
