# [25458. M](https://www.acmicpc.net/problem/25458)

## 문제
M je kodno ime osobe koja obnaša jednu od ključnih funkcija britanske tajne službe (MI6). Jedna od glavnih zadaća na toj funkciji je analiza sigurnosnih svojstava neprijateljskih komunikacijskih mreža. Ovaj zadatak ocrtava jedan od tipičnih problema s kojima se M dnevno susreće.


Neprijateljska komunikacijska mreža sastoji se od $N$ (naizgled običnih) poštanskih ureda i $M$ dvosmjernih prometnica koje direktno povezuju neke parove poštanskih ureda. Radi jednostavnosti, poštanske urede ćemo označiti prirodnim brojevima od $1$ do $N$.


Kada neprijatelj želi poslati tajnu informaciju iz ureda s oznakom $a$ do ureda s oznakom $b$, tajni agent će sjesti u lažno vozilo pošte i provozati se nekim nizom prometnica koje tvore put između ta dva poštanska ureda. Par poštanskih ureda $(a, b)$ smatra se 
ranjivim
 ako postoji neka cesta po kojoj će tajni agent sigurno morati proći na svom putovanju od ureda $a$ do ureda $b$, ili ako uopće ne postoji put između ta dva ureda.


M se danas bavi analizom povijesne ranjivosti jedne takve mreže. Naime, M je prikupio informacije o povijesnom razvoju mreže, što znači da zna kojim su se redoslijedom gradile prometnice između poštanskih ureda. Sada ga za neke parove ureda zanima u kojem su trenutku (ako uopće) prestali biti ranjivi.

## 예제 입력 1
```
3 3
1 2
2 3
3 1
1
1 2
```

## 예제 출력 1
```
3
```

## 예제 입력 2
```
3 4
1 2
1 2
2 3
2 3
3
1 2
2 3
3 1
```

## 예제 출력 2
```
2
4
4
```

## 예제 입력 3
```
6 7
1 2
2 3
3 4
2 5
3 5
4 5
1 3
5
1 3
2 3
4 5
1 4
2 6
```

## 예제 출력 3
```
7
5
6
7
-1
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Diamond 5 | Java 11 / 수정 | 278580 KB | 2616 ms | 3522 B | 10달 전 |
