# [26753. OIJ](https://www.acmicpc.net/problem/26753)

## 문제
Szkoła Bajtka i Bitosi organizuje wielki festyn z okazji rozpoczęcia Olimpiady Informatycznej Juniorów. W ramach przygotowań, rodzeństwo podjęło się sporządzenia jak największej liczby transparentów z napisem 
oij
 (w Bajtocji używa się wyłącznie małych liter alfabetu angielskiego).


W piwnicy swojego domu Bajtek i Bitosia znaleźli stary, wielki i bardzo starannie wykonany transparent, pochodzący z czasów młodości ich rodziców, zawierający długi napis w dziwnym języku (rodzice nie chcą niestety przyznać się, do czego im służył). Bajtek zauważył, że można spróbować zamalować na transparencie niektóre znaki tak, aby pozostały tylko trzy literki: 
o
, 
i
 oraz 
j
, w tej kolejności. Bitosia jeszcze poprawiła ten plan – transparent zostanie najpierw pocięty na kilka fragmentów tak, aby z każdego z nich dało się uzyskać napis 
oij
 metodą Bajtka.


Na przykład, transparent głoszący 
koligacjeomijaj
 można podzielić na dwa takie kawałki:


koligacjeomijaj
 → 
koligacje|omijaj
 → 
▪️o▪️i▪️▪️▪️j▪️|o▪️ij▪️▪️
.


Na ile najwięcej fragmentów można podzielić napis na starym transparencie, aby z każdego dało się uzyskać 
oij
?

## 예제 입력 1
```
oaiobjibojicj
```

## 예제 출력 1
```
2
```

## 예제 입력 2
```
jio
```

## 예제 출력 2
```
NIE
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Silver 5 | C++17 / 수정 | 3680 KB | 12 ms | 337 B | 2년 전 |
