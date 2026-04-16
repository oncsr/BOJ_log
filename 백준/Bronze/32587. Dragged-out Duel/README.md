# [32587. Dragged-out Duel](https://www.acmicpc.net/problem/32587)

## 문제
Your friend Guile and you have decided to spend an afternoon playing the new Street Fighter game, but you both want to start on the left, because you have both only practiced all your combos starting from the left. You decide to determine who starts on the left like true men -- with an intense grueling, and exhausting duel of rock-paper-scissors.


The duel will be a best-of-$n$, consisting of $n$ single rounds of rock-paper-scissors (yes, you may have to play rock-paper-scissors 
ten thousand times
, truly a war of attrition), and whoever wins more rounds, gets to start on the left. If you both pick the same option in an individual game, it is not replayed. To keep track of who wins, you decide to write a program, that determines whether you beat Guile in this great duel.


As a reminder: rock beats scissors, scissors beats paper, paper beats rock. If you both make the same choice, the round is a draw.

## 예제 입력 1
```
5
RRSSP
SSSSS
```

## 예제 출력 1
```
victory
```

## 예제 입력 2
```
6
PRSRPS
PSSPPR
```

## 예제 출력 2
```
defeat
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Bronze 3 | C++17 / 수정 | 2168 KB | 0 ms | 440 B | 1년 전 |
