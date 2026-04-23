# [26732. Agar.io](https://www.acmicpc.net/problem/26732)

## 문제
Gra agar.io (swego czasu dość popularna w sieci) jest rozgrywana w przeglądarce internetowej. Każdy z obecnych na serwerze graczy steruje pojedynczą komórką o pewnej masie. Kiedy spotyka komórkę o masie mniejszej niż swoja, wchłania ją, powiększając swoją masę o masę drugiej komórki. Kiedy jednak spotka komórkę o masie większej lub równej swojej, natychmiast przegrywa.


Bajtek połączył się właśnie z serwerem gry i jego komórka ma niezbyt imponującą masę 2. Bardzo chciałby jednak wygrać, czyli zostać najwiekszą komórką na tym serwerze. Dzięki niebywałym umiejętnościom hakerskim udało mu się zablokować możliwość poruszania się innych graczy – czyli jest w stanie swobodnie wybierać kolejne ofiary do wchłonięcia, a inni gracze nie mogą uniknąć spotkania.


Ta miła sytuacja nie potrwa jednak długo i administratorzy serwera niebawem cofną blokady Bajtka. Bajtek jest w stanie wchłonąć swoją komórką inną komórkę w czasie jednej sekundy. Ile sekund będzie potrzebował, aby stać się największą komórką na serwerze? Bajtek zadowoli się ewentualnym remisem z innymi największymi komórkami. Napisz program, który na podstawie masy komórek kontrolowanych przez przeciwników Bajtka na serwerze gry, wyznaczy minimalny czas potrzebny Bajtkowi aby stać się największą komórką w grze. Przypominamy, że komórka Bajtka zaczyna z masą równą 2.

## 예제 입력 1
```
7
1 2 2 10 5 12 1
```

## 예제 출력 1
```
4
```

## 예제 입력 2
```
7
3 4 5 3 6 4 3
```

## 예제 출력 2
```
NIE
```

## 예제 입력 3
```
8
1 2 4 8 16 32 64 128
```

## 예제 출력 3
```
7
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 5 | C++17 / 수정 | 8296 KB | 76 ms | 682 B | 3년 전 |
