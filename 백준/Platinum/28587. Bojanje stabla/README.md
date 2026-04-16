# [28587. Bojanje stabla](https://www.acmicpc.net/problem/28587)

## 문제
Zadano je stablo od $N$ čvorova označenih prirodnim brojevima od $1$ do $N$. Svaki čvor ima pridruženu neku vrijednost. Na početku su vrijednosti svih čvorova jednake nuli. Mirko je odlučio nekoliko puta promijeniti vrijednosti nekih čvorova. Preciznije, u i-tom mijenjanju, postavit će vrijednosti svih čvorova na putu od $a_i$ do $b_i$ na $i$. Njegov znatiželjni prijatelj Slavko će ga povremeno upitati koja je trenutno vrijednost pridružena određenom čvoru. Pomozi Mirku odgovoriti na Slavkova pitanja.

## 예제 입력 1
```
5
1 2
1 3
2 4
4 5
8
1 3 4
1 5 1
1 3 5
2 3
2 2
1 1 3
1 3 2
2 3
```

## 예제 출력 1
```
3
3
5
```

## 예제 입력 2
```
6
1 2
1 3
2 4
4 5
5 6
8
1 6 2
2 4
2 1
1 3 3
2 3
2 6
2 4
1 5 2
```

## 예제 출력 2
```
1
0
2
1
1
```

## 예제 입력 3
```
5
1 2
1 3
3 4
3 5
8
2 5
2 5
2 3
1 2 3
2 2
1 3 4
2 3
2 1
```

## 예제 출력 3
```
0
0
0
1
2
1
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Platinum 1 | C++17 / 수정 | 22160 KB | 128 ms | 2175 B | 1년 전 |
