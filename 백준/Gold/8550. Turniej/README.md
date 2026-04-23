# [8550. Turniej](https://www.acmicpc.net/problem/8550)

## 문제
W Bajtocji rozegrano turniej, w którym wzięło udział 
n
 zawodników. Zawodnikom przydzielono numery od 1 do 
n
, w kolejności zgłoszeń. Planowano rozegranie pojedynków w każdej parze zawodników, jednak ze względu na silny wiatr turniej został przerwany po rozegraniu jedynie części z nich. Niestety ze względu na zaplanowaną obecność króla Bajtazara na ceremonii wręczenia nagród, zakończenie nie mogło zostać przesunięte. Jury stanęło więc przed problemem przydzielenia miejsc. Problem jest tym większy, iż w Bajtocji nie uznaje się miejsc równorzędnych. Aby przydzielić miejsca Sędzia Główny ustalił następującą regułę:




Każdy zawodnik musi zajmować wyższą pozycję w rankingu niż wszyscy zawodnicy, których pokonał w bezpośrednich pojedynkach.




Członkowie Jury przystąpili ochoczo do tworzenia rankingów. Szybko okazało się jednak, że prawie wszyscy zaproponowali inny przydział miejsc. Sędzia główny ustalił więc sposób porównywania rankingów:




Ranking A jest lepszy od innego rankingu, jeśli na najwyższej rozróżniającej je pozycji ranking A posiada zawodnika, który zgłosił się wcześniej.




Twoje zadanie polega na sporządzeniu najlepszego rankingu. Szczęśliwie okazało się, że wyniki dotychczas rozgrywanych pojedynków gwarantują istnitnie takiego rankingu.

## 예제 입력 1
```
10 5
9 5
3 2
9 10
10 7
4 7
```

## 예제 출력 1
```
1
3
2
4
6
8
9
5
10
7
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 2 | C++17 / 수정 | 7444 KB | 48 ms | 601 B | 3년 전 |
