# [8689. Gra](https://www.acmicpc.net/problem/8689)

## 문제
Kolejny deszczowy dzień. Paweł i Gaweł znów byli zmuszeni do pozostania w domu. W związku z brakiem zajęć postanowili wymyślić jakąś grę.


Paweł wpadł na genialny pomysł. Na kartce papieru narysował 
n
 pól. Na każdym polu znajdowały się dwie liczby - pierwsza z nich była numerem pola (liczba naturalna od 1 do 
n
, pola miały parami różne numery), a druga jego wartością (liczba całkowita od -1 000 do 1 000). Na polu numer 1 umieścił pionek. Zadaniem gracza było wykonywanie kolejnych ruchów, polegających na rzucie sześcienna kostką (z numerami od 1 do 6 napisanymi na ściankach) oraz przesuwaniu pionka o wskazaną liczbę oczek. Gra kończyła się, kiedy pionek stanął na pole o numerze 
n
. Wynikiem, jaki uzyskał gracz, była suma wartości pól na jakich stał pionek.


Po rozegraniu kilku partii Paweł i Gaweł otrzymali kilka różnych wyników, jednak nie wiedzieli czy któryś z nich był największym możliwym do uzyskania. Zadzwonili więc do Ciebie, utalentowanego informatyka, abyś napisał program, który dla danej planszy obliczy maksymalny możliwy do uzyskania wynik.

## 예제 입력 1
```
4
1 2 -1 1
```

## 예제 출력 1
```
4
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Silver 3 | C++17 / 수정 | 5804 KB | 92 ms | 317 B | 2년 전 |
