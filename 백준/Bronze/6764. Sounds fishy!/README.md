# [6764. Sounds fishy!](https://www.acmicpc.net/problem/6764)

## 문제
A fish-finder is a device used by anglers to find fish in a lake. If the fish-finder finds a fish, it will sound an alarm. It uses depth readings to determine whether to sound an alarm. For our purposes, the fish-finder will decide that a fish is swimming past if:




there are four consecutive depth readings which form a strictly increasing sequence (such as 3 4 7 9) (which we will call “Fish Rising”), or


there are four consecutive depth readings which form a strictly decreasing sequence (such as 9 6 5 2) (which we will call “Fish Diving”), or


there are four consecutive depth readings which are identical (which we will call “Constant Depth”).




All other readings will be considered random noise or debris, which we will call “No Fish.”


Your task is to read a sequence of depth readings and determine if the alarm will sound.

## 예제 입력 1
```
1
10
12
13
```

## 예제 출력 1
```
Fish Rising
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Bronze 4 | C++17 / 수정 | 2020 KB | 0 ms | 349 B | 2년 전 |
