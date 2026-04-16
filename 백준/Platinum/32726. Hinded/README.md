# [32726. Hinded](https://www.acmicpc.net/problem/32726)

## 문제
Juku on koolis teinud hulga kontrolltöid, mida hinnati $0 \ldots 100$ punktiga.


Juku vanaisa annab talle hinnete eest taskuraha. Vanaisa loeb tulemused üle $50$ punkti headeks hinneteks ja tulemused alla $50$ punkti halbadeks hinneteks. Täpsemalt liidab ta hinnete $50$ punkti ületavad osad Juku taskurahale ning lahutab $50$ punkti alla jäävad osad sealt maha. Näiteks hinnete $35$, $42$, $81$ ja $100$ eest saaks Juku kokku $(35-50)+(42-50)+(81-50)+(100-50) = -15-8+31+50 = 58$ eurot. (Täpselt $50$ punktiga hinnatud tööd seega taskuraha ei mõjuta.)


Õpetaja hoiab Juku hindeid $N$ rea ja $N$ veeruga Exceli tabelis. Kokku on Jukul seega $N^2$ hinnet. Juku pääseb tabelile korraks ligi ja tal on võimalus oma hindeid "parandada" sel viisil, et ta märgib tabelis ühe ristkülikukujulise alamosa (mis võib olla ka tühi, s.t. sisaldada null elementi) ja kustutab sealt kõik hinded.


Leida, mis on maksimaalne hulk taskuraha, mille Juku võiks sellise kustutamise järel saada.

## 예제 입력 1
```
3
80 90 90
100 5 60
90 60 10
```

## 예제 출력 1
```
200
```

## 예제 입력 2
```
4
100 100 100 100
100 2 2 100
100 90 90 100
100 2 2 100
```

## 예제 출력 2
```
500
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Platinum 5 | C++17 / 수정 | 2256 KB | 16 ms | 605 B | 1년 전 |
