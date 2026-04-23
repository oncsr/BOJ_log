# [26084. DPS](https://www.acmicpc.net/problem/26084)

## 문제
ICPC는 세 명이 한 팀을 이뤄 참가하는 국제 대학생 프로그래밍 대회이다. ICPC에 참가하는 각 팀의 이름은 세 팀원의 핸들 첫 글자를 임의의 순서로 이어 붙인 것이다. 핸들이란 Baekjoon Online Judge와 같은 온라인 채점 사이트에서 사용하는 고유한 ID이다.


예를 들어 핸들이 각각 DONGGAS, PICASSO, SEMTEO인 세 명으로 이루어진 팀의 이름은 DPS, DSP, PDS, PSD, SDP, SPD 중 하나이다. 또, 핸들이 각각 RAARARAARA, WBCHO, WEASEL인 세 명으로 이루어진 팀의 이름은 RWW, WRW, WWR 중 하나이다.


팀 이름 $S$와 $N$명의 핸들이 주어지면, $N$명으로 팀 $S$를 구성하는 모든 경우의 수를 구해보자.

## 예제 입력 1
```
DPS
7
DONGGAS
PICASSO
SEMTEO
DJS
WBCHO
RAARARAARA
WEASEL
```

## 예제 출력 1
```
2
```

## 예제 입력 2
```
DDD
4
DONGGAS
DJS
DURAM
DART
```

## 예제 출력 2
```
4
```

## 예제 입력 3
```
SGS
4
GUMGOOD
SHIFTPSH
SHANDY
SANGPIL
```

## 예제 출력 3
```
3
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Silver 2 | C++17 / 수정 | 2024 KB | 4 ms | 647 B | 3년 전 |
