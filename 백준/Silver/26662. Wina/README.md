# [26662. Wina](https://www.acmicpc.net/problem/26662)

## 문제
Mamy rok 2019. Kiedyś było lepiej, a przynajmniej tak uważa bajtocki podczaszy Bajtosław. Przecież im starsze wino, tym lepsze, więc widocznie kiedyś produkowano zacniejsze trunki.


Bajtosław ma teraz nowy powód do narzekania. Wino zawsze składował w wielkich drewnianych beczkach, ale najnowsze trendy winiarskie nakazują używać jedynie szklanych butelek. Jednak przechowywanie wielu butelek w królewskiej piwniczce okazało się niemałym problemem dla podczaszego. Stojaki na wino tanie nie są, a jedyną sensowną alternatywą jest ułożenie butelek w piramidę pod ścianą: n butelek w najniższym rzędzie, na nich n − 1 kolejnych butelek, potem n − 2 itd. aż do jednej butelki w najwyższym rzędzie. Daje to łącznie n · (n + 1)/2 butelek. Taka piramida jest stabilna, bo każda butelka leży na podłodze lub na dwóch innych butelkach.


Bajtosław ułożył już butelki i na każdą nakleił etykietę z rokiem produkcji wina znajdującego się w butelce. Wtem do piwniczki wpadł zdyszany posłaniec i oznajmił, że król wydał właśnie spontaniczną ucztę i natychmiast potrzebuje k butelek wina. Bajtosław k razy poda posłańcowi jakąś butelkę z piramidy, a jedną z podanych butelek oznaczy jako najprzedniejszy trunek dla samego króla. Podczaszy musi tak wybierać butelki, by piramida w każdym momencie była stabilna, a król dostał jak najstarsze wino. Jaki to będzie rocznik?

## 예제 입력 1
```
5 7
1999
2019 2010
850 1500 1600
900 900 710 900
1000 800 600 800 1000
```

## 예제 출력 1
```
710
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Silver 3 | C++17 / 수정 | 33776 KB | 172 ms | 462 B | 1년 전 |
