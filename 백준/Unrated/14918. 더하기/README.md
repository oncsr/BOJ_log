# [14918. 더하기](https://www.acmicpc.net/problem/14918)

## 문제
두 개의 정수 입력 a, b를 받아서 a+b를 출력하시오.


C 입출력 예제



#include <stdio.h>
…
scanf(“%d%d”, &a, &b);
printf(“%d\n”, a+b);


C++ 입출력 예제



#include <iostream>
…
cin >> a >> b;
cout << a+b << endl;


JAVA 입출력 예제



import java.util.Scanner;
Scanner sc = new Scanner(System.in);
a = sc.nextInt();
b = sc.nextInt();
System.out.println((a+b));

## 예제 입력 1
```
1 2
```

## 예제 출력 1
```
3
```

## 예제 입력 2
```
4 5
```

## 예제 출력 2
```
9
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Unrated | Java 11 / 수정 | 15884 KB | 120 ms | 1121 B | 10달 전 |
