# [24201. Tankeläsning](https://www.acmicpc.net/problem/24201)

## 문제
Ett vanligt magitrick går till på följande vis:


Tänk på ett tal. Subtrahera 1 från talet du tänkte på. Multiplicera resultatet med 3 och lägg till 9. Dela svaret med 3. Addera 5. Subtrahera talet du tänkte på från början. Talet du har kvar är 7.


Självklart är ingen verklig tankeläsning involverad. Om vi kallar det ursprungliga talet för $x$ får vi genom att utföra operationerna uttrycken


\[\begin{array}{rcl} (x) - 1 & = & x - 1 \\ (x - 1) * 3 & = & 3x - 3 \\ (3x - 3) + 9 & = & 3x + 6 \\ (3x + 6)\ /\ 3 & = & x + 2 \\ (x + 2) + 5 & = & x + 7 \\ (x + 7) - x & = & 7 \end{array}\]


Alltså kommer vi alltid få talet 7 på slutet!


Johan vill imponera på sina kompisar genom att utföra en liknande tankeläsning. Tyvärr är han inte så bra på matte, så han behöver hjälp att ta reda på om hans eget magitrick faktiskt fungerar.

## 예제 입력 1
```
6
- 1
* 3
+ 9
/ 3
+ 5
- x
```

## 예제 출력 1
```
7
```

## 예제 입력 2
```
6
- 1
* 3
+ 9
/ 2
+ 5
- x
```

## 예제 출력 2
```
Nej
```

## 예제 입력 3
```
6
+ 2
- x
* x
/ 2
+ 3
- x
```

## 예제 출력 3
```
3
```

## 예제 입력 4
```
5
+ 7
* x
* 0
* x
- 7
```

## 예제 출력 4
```
-7
```

## 예제 입력 5
```
1
* x
```

## 예제 출력 5
```
Nej
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 5 | C++17 / 수정 | 2020 KB | 0 ms | 817 B | 2년 전 |
