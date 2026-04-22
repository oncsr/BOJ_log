# [14991. Disastrous Doubling](https://www.acmicpc.net/problem/14991)

## 문제
A scientist, E. Collie, is going to do some experiments with bacteria. Right now, she has one bacterium. She already knows that this species of bacteria doubles itself every hour. Hence, after one hour there will be 2 bacteria. E.


E. Collie will do one experiment every hour, for n consecutive hours. She starts the first experiment exactly one hour after the first bacterium starts growing. In experiment i she will need b
i
 bacteria.


How many bacteria will be left directly after starting the last experiment? If at any point there are not enough bacteria to do the experiment, print “error”.


Since the answer may be very large, please print it modulo 10
9
 + 7.

## 예제 입력 1
```
3
0 0 0
```

## 예제 출력 1
```
8
```

## 예제 입력 2
```
5
1 1 1 1 1
```

## 예제 출력 2
```
1
```

## 예제 입력 3
```
5
0 2 2 4 0
```

## 예제 출력 3
```
0
```

## 예제 입력 4
```
5
0 2 2 4 1
```

## 예제 출력 4
```
error
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Bronze 2 | Python 3 / 수정 | 44224 KB | 416 ms | 243 B | 3년 전 |
