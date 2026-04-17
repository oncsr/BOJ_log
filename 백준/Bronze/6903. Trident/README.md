# [6903. Trident](https://www.acmicpc.net/problem/6903)

## 문제
A 
trident
 is a fork with three tines (prongs). A simple picture of a trident can be made from asterisks and spaces:



*  *  *
*  *  *
*  *  *
*******
   *
   *
   *
   *



In this example, each tine is a vertical column of 3 asterisks. Each tine is separated by 2 spaces. The handle is a vertical column of 4 asterisks below the middle tine.


Tridents of various shapes can be drawn by varying three parameters: $t$, the height of the tines, $s$, the spacing between tines, and $h$, the length of the handle. For the example above we have $t = 3$, $s = 2$, and $h = 4$.


You are to write an interactive program to print a trident. Your program should accept as input the parameters $t$, $s$, and $h$, and print the appropriate trident. You can assume that $t$, $s$, $h$ are each at least 0 and not larger than 10.

## 예제 입력 1
```
4
3
2
```

## 예제 출력 1
```
*   *   *
*   *   *
*   *   *
*   *   *
*********
    *
    *
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Bronze 3 | C++17 / 수정 | 2020 KB | 0 ms | 469 B | 2년 전 |
