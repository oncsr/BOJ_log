# [20840. Volleybollmatchen](https://www.acmicpc.net/problem/20840)

## 문제
Du har blivit inhyrd av PO-Volley (Påhittade Organisationen för Volleyboll), för att hålla koll på poängen i en volleybollmatch mellan de två lagen Algoritmikerna och Bäverbusarna.


I volleyboll spelar man bäst av $3$ set, det vill säga det laget som först vunnit $2$ set vinner matchen. I de två första setten gäller först till $25$, och ifall det blir ett tredje set spelar man då först till $15$. Man måste vinna med $2$ poäng, så det är alltså det lag som först har minst $25$ resp $15$ poäng, och som dessutom har $2$ poäng mer än motståndaren som vinner det settet. Givet vilket lag som vinner varje boll, skriv ut resultatet av matchen.

## 예제 입력 1
```
65
AAAAAAAAAAAAAAAAAAAAAAAAABBBBBBBBBBBBBBBBBBBBBBBBBAAAAAAAAAAAAAAA
```

## 예제 출력 1
```
2 1
```

## 예제 입력 2
```
104
BABABABABABABABABABABABABABABABABABABABABABABABABABBBABABABABABABABABABABABABABABABABABABABABABABABABABB
```

## 예제 출력 2
```
0 2
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Bronze 1 | C++17 / 수정 | 2024 KB | 0 ms | 820 B | 3년 전 |
