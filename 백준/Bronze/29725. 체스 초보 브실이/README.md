# [29725. 체스 초보 브실이](https://www.acmicpc.net/problem/29725)

## 문제
브실이는 이제 막 체스에 입문한 체스 초보이다. 브실이는 아직 초보이기 때문에 체스판의 기물 점수 계산을 잘하지 못한다.


체스판의 기물 점수는 백의 기물 점수 합에서 흑의 기물 점수 합을 뺀 값이고, 기물에 해당하는 킹, 폰, 나이트, 비숍, 룩, 퀸의 기물 점수는 각각 $0$, $1$, $3$, $3$, $5$, $9$점이다. 


체스 초보 브실이를 위해 체스판의 기물 점수 계산을 도와주자!

## 예제 입력 1
```
rnbqkbnk
pppppppp
........
........
........
........
PPPPPPPP
RNBQKBNK
```

## 예제 출력 1
```
0
```

## 예제 입력 2
```
RRRRRRRR
RRRRRRRR
RRRRRRRR
RRRRRRRR
rrrrrrrr
rrrrrrrr
rrrrrrrr
rrrrrrrk
```

## 예제 출력 2
```
5
```

## 예제 입력 3
```
rrrrrrrr
rrrrrrrr
rrrrrrrr
rrrrrrrr
rrrrrrrr
rrrrrrrr
rrrrrrrr
rrrrrrrr
```

## 예제 출력 3
```
-320
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Bronze 4 | C++17 / 수정 | 2024 KB | 0 ms | 399 B | 2년 전 |
