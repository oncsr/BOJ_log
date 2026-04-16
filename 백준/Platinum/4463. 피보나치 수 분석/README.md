# [4463. 피보나치 수 분석](https://www.acmicpc.net/problem/4463)

## 문제
어떤 피보나치 수는 좀비의 공격에 면역성이 있다. 그 이유는 소수는 분해할 수 없기 때문이다.


피보나치 수는 아래와 같이 재귀적으로 정의할 수 있다.




64비트 부호있는 정수로 표현할 수 있는 정수 범위가 주어진다. 이때, 그 구간에 포함되는 피보나치 수를 찾은 다음, 그 수의 밑이 2인 로그를 취한 값과 소인수 분해를 하는 프로그램을 작성하시오. 소인수는 오름 차순이며, 여러 번 등장하는 수는 그만큼 출력해야 한다. 만약, 그 구간에 해당하는 피보나치 수가 없는 경우에는 없다고 출력하면 된다.


0은 첫 번째 피보나치 수이지만, 0의 로그는 정의되지 않는다. 또, 0과 1은 소인수가 없다.

## 예제 입력 1
```
0x0 0x8
0x9 0xc
0x9 0x40
0x0 0x0
```

## 예제 출력 1
```
Range 0 to 8:
Fib(0) = 0, lg does not exist
No prime factors
Fib(1) = 1, lg is 0.000000
No prime factors
Fib(2) = 1, lg is 0.000000
No prime factors
Fib(3) = 2, lg is 1.000000
Prime factors: 2
Fib(4) = 3, lg is 1.584963
Prime factors: 3
Fib(5) = 5, lg is 2.321928
Prime factors: 5
Fib(6) = 8, lg is 3.000000
Prime factors: 2 2 2

Range 9 to 12:
No Fibonacci numbers in the range

Range 9 to 64:
Fib(7) = 13, lg is 3.700440
Prime factors: 13
Fib(8) = 21, lg is 4.392317
Prime factors: 3 7
Fib(9) = 34, lg is 5.087463
Prime factors: 2 17
Fib(10) = 55, lg is 5.781360
Prime factors: 5 11
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Platinum 5 | C++17 / 수정 | 2176 KB | 0 ms | 2744 B | 1년 전 |
