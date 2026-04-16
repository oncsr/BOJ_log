# [28713. Vjeverice](https://www.acmicpc.net/problem/28713)

## 문제
Živopisan Lund, gradić na jugu Švedske, krasi predivan park Botaniska Trädgården, a u njemu stanuju - vjeverice!


U parku je $n$ stabala, a vjeverice između $m$ parova stabala imaju označen puteljak. Svake godine ih dočeka isti problem: dođe jesen, lišće počne padati, i zatrpa im puteljke. Tada vjeverica moraju ponovno kamenčićima označavati sve puteljke. Već su to toliko puta ponovile da za svaki puteljak znaju koliko im je kamenčića potrebno da ga ponovo označe, za $i$-ti puteljak, koji spaja $a_i$-to stablo i $b_i$-stablo, potrebno im je $c_i$ kamenčića.


Za ovu godinu osmislile su novi plan: odlučile su ne označiti sve puteljke, nego samo njih $n - 1$. Učiniti će to na način da su sva stabla povezana, tj. između svakog para stabala postoji uzastopan niz označenih puteljaka koji od jednog stabla vodi do drugog. Dodatno, puteljke će odabrati na način da ukupan broj kamenčića na puteljcima bude najmanji moguć.


Koliko kamenčića će im biti potrebno?


Taman kad su se bacile na izračun potrebnih kamenčića, javilo se $q$ vjeverica, $i$-ta od njih izrazila je svoju sumnju u broj kamenčića potrebnih za označavanje puteljaka:


Za označiti $x_i$-ti puteljak potrebno nam je $d_i$ kamenčića, a ne $c_i$!.


Koliko im je ukupno kamenčića potrebno za označavanje puteljaka po novom planu ako je izjava $i$-te vjeverica istinita, a izjave ostalih vjeverica lažno?

## 예제 입력 1
```
3 3
2 1 674
3 2 686
3 1 712
3
1 185
2 800
3 850
```

## 예제 출력 1
```
1360
871
1386
1360
```

## 예제 입력 2
```
5 8
2 1 636
3 1 650
4 1 505
5 2 711
2 3 556
3 4 434
5 1 469
5 3 654
4
8 264
2 884
4 273
8 702
```

## 예제 출력 2
```
1964
1723
1964
1681
1964
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Diamond 4 | Java 15 / 수정 | 184452 KB | 1712 ms | 5346 B | 3달 전 |
