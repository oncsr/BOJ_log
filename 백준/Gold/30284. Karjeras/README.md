# [30284. Karjeras](https://www.acmicpc.net/problem/30284)

## 문제
Sklype atrasta naudingųjų iškasenų. Planuojama sklype sumontuoti naują automatinę kasimo sistemą, ją naudoti ir sklypą paversti naudingųjų iškasenų karjeru.


Ši sistema gali vienu metu iškasti viso karjero pločio duobę, kurios pradžia yra S
i
, pabaiga – E
i
 metrų nuo karjero pradžios, o gylis – H
i
 metrų.


Sklypą (karjerą) galima pavaizduoti kaip dvimatį brėžinį, kuris vaizduoja karjero aukštį virš jūros lygio išilgai karjero, tiek pradiniu momentu, tiek vėliau, pradėjus naudingųjų iškasenų kasimą.


Automatinė kasimo sistema dirba vykdydama kasimo komandas. Kiekviena komanda sumažins karjero aukštį H
i
 metrų nurodytame intervale. 1 pav. parodyta, kaip keičiasi karjero aukštis įvykdžius dvi komandas, kurių pirma kasa intervale [0; 2], antra – [1; 3], abi iškasa 1 metro gylio duobes. Komandų iškasami plotai atitinkamai pažymėti žaliai (atspausdintoje nespalvotoje sąlygoje – šviesiai pilkai) ir mėlynai (nespalvotoje sąlygoje – pilkai).




1 pav.


Karjero savininkas žino, kokias kasimo komandas duos šiai sistemai, bet prieš pradėdamas nori sužinoti, kaip atrodys karjeras įvykdžius visas komandas.


Suraskite karjero aukštį įvykdžius visas kasimo komandas.

## 예제 입력 1
```
5 2
3 4 3 2 1
0 2 1
1 3 1
```

## 예제 출력 1
```
2 2 1 1 1
```

## 예제 입력 2
```
4 2
4 -2 4 0
0 3 3
0 2 1
```

## 예제 출력 2
```
0 -6 0 -3
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 5 | C++17 / 수정 | 3852 KB | 108 ms | 419 B | 2년 전 |
