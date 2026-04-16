# [34747. Maximal Color Rectangle](https://www.acmicpc.net/problem/34747)

## 문제
You are given an $N \times N$ grid $A$ where each cell contains an integer color ID $A_{ij}$. Your task is to find the largest axis-aligned rectangle whose cells all have the same color, and report its area.




In this figure, the maximal area satisfying the problem’s conditions is $6$. Note that 
rectangle must be axis-aligned and contiguous 
in rows and columns.

## 예제 입력 1
```
4
1 0 0 0
1 0 1 0
1 1 0 0
0 1 1 0
```

## 예제 출력 1
```
4
```

## 예제 입력 2
```
4
1 2 2 2
1 2 2 2
1 2 2 2
3 3 0 -1
```

## 예제 출력 2
```
9
```

## 예제 입력 3
```
6
1 1 2 2 2 4
1 1 1 2 2 4
3 1 1 2 2 2
3 3 3 3 3 2
4 4 4 4 4 5
5 5 5 5 1 1
```

## 예제 출력 3
```
6
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Platinum 3 | Java 15 / 수정 | 310072 KB | 1336 ms | 1983 B | 3일 전 |
