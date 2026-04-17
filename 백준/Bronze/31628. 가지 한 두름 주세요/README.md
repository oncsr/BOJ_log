# [31628. 가지 한 두름 주세요](https://www.acmicpc.net/problem/31628)

## 문제
$10 \times 10$ 격자의 각 칸에 가지가 한 개씩 들어 있습니다. 키위새는 가로로 연속한 $10$개의 칸 혹은 세로로 연속한 $10$개의 칸에 들어 있는 모든 가지를 단 한 번 줄줄이 연결할 수 있습니다. 가지 한 두름은 같은 색의 가지를 정확히 $10$개 연결한 것입니다. 각 칸에 들어 있는 가지의 색이 주어질 때, 키위새가 가지 한 두름을 만들 수 있는지 판단해 봅시다.


첫 행의 모든 가지로 가지 한 두름을 만든 모습

## 예제 입력 1
```
r r r r r r r r r r
g b g b g b g b g b
g b g b g b g b g b
g b g b g b g b g b
g b g b g b g b g b
g b g b g b g b g b
g b g b g b g b g b
g b g b g b g b g b
g b g b g b g b g b
g b g b g b g b g b
```

## 예제 출력 1
```
1
```

## 예제 입력 2
```
r b g b g b g b g b
r g b g b g b g b g
r b g b g b g b g b
r g b g b g b g b g
r b g b g b g b g b
r g b g b g b g b g
r b g b g b g b g b
r g b g b g b g b g
r b g b g b g b g b
r g b g b g b g b g
```

## 예제 출력 2
```
1
```

## 예제 입력 3
```
chipi chapa chipi chapa chipi chapa chipi chapa chipi chapa
chapa chipi chapa chipi chapa chipi chapa chipi chapa chipi
chipi chapa chipi chapa chipi chapa chipi chapa chipi chapa
chapa chipi chapa chipi chapa chipi chapa chipi chapa chipi
chipi chapa chipi chapa chipi chapa chipi chapa chipi chapa
chapa chipi chapa chipi chapa chipi chapa chipi chapa chipi
chipi chapa chipi chapa chipi chapa chipi chapa chipi chapa
chapa chipi chapa chipi chapa chipi chapa chipi chapa chipi
chipi chapa chipi chapa chipi chapa chipi chapa chipi chapa
chapa chipi chapa chipi chapa chipi chapa chipi chapa chipi
```

## 예제 출력 3
```
0
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Bronze 3 | C++17 / 수정 | 2024 KB | 0 ms | 559 B | 2년 전 |
