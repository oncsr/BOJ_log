# [27833. Anti-Blot System](https://www.acmicpc.net/problem/27833)

## 문제
Jimmy is a hard-working pupil in his second year at primary school. Recently he decided to convert all his notes into an electronic version. Sadly, he found that his math notes were full of ink blots.


He scanned the notes and sent them through his own OCR package (yes, he coded it all by himself at the age of 8). The OCR package replaced all ink blots by the string "
machula
".


You are given Jimmy's notes, processed by the OCR. They contain simple math exercises, which were used to practice addition on positive integers. Your task is to recover the damaged part of the notes.

## 예제 입력 1
```
3

23 + 47 = machula

3247 + 5machula2 = 3749

machula13 + 75425 = 77038
```

## 예제 출력 1
```
23 + 47 = 70
3247 + 502 = 3749
1613 + 75425 = 77038
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Silver 5 | Python 3 / 수정 | 31256 KB | 184 ms | 670 B | 2년 전 |
