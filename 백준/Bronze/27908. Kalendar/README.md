# [27908. Kalendar](https://www.acmicpc.net/problem/27908)

## 문제
Magdalena likes calendars, and she makes her own calendar for each month.


Each day of the month is represented with exactly three characters:




If the day number is single-digit, then it is represented as '
..X
'. For example, the number $7$ is represented as '
..7
'


If the day number is double-digit, then it is represented as '
.XY
'. For example, the number $17$ is represented as '
.17
'.




Each row of the calendar represents a week, and each week consists of $7$ days. If the week doesn’t have all the $7$ days (because the month doesn’t start on Monday, or it doesn’t end on Sunday), then the missing days are replaced with '
...
'.


Magdalena also wants her calendar to be pretty. She will decorate it in the following way: she will fill the upper and lower sides with '
-
' (ASCII 45), the left and right sides with '
|
' (ASCII 124), and the corners with '
+
' (ASCII 43).


For example, the format of Magdalena’s calendar, when the month has 31 days and starts on Wednesday, is the following:



+–––––––––––––––––––––+
|........1..2..3..4..5|
|..6..7..8..9.10.11.12|
|.13.14.15.16.17.18.19|
|.20.21.22.23.24.25.26|
|.27.28.29.30.31......|
+–––––––––––––––––––––+


Your task is to determine the format of Magdalena’s calendar if it has $n$ days, and the first day of the month is the $x$-th day of the week. For example, if $x = 1$, the month starts on Monday, and if $x = 5$, it starts on Friday.


Note: We assume the first day of the week is Monday.

## 예제 입력 1
```
31 3
```

## 예제 출력 1
```
+---------------------+
|........1..2..3..4..5|
|..6..7..8..9.10.11.12|
|.13.14.15.16.17.18.19|
|.20.21.22.23.24.25.26|
|.27.28.29.30.31......|
+---------------------+
```

## 예제 입력 2
```
1 5
```

## 예제 출력 2
```
+---------------------+
|..............1......|
+---------------------+
```

## 예제 입력 3
```
28 7
```

## 예제 출력 3
```
+---------------------+
|....................1|
|..2..3..4..5..6..7..8|
|..9.10.11.12.13.14.15|
|.16.17.18.19.20.21.22|
|.23.24.25.26.27.28...|
+---------------------+
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Bronze 1 | C++17 / 수정 | 2020 KB | 0 ms | 696 B | 2년 전 |
