# [26997. Finding Bovine Roots](https://www.acmicpc.net/problem/26997)

## 문제
The cows are trying to find their roots. They are not so smart as humans when they find square roots, the cows lose the integer portion of their square root calculation. Thus, instead of calculating the square root of 2 to be 1.4142135623730950488016887242096980785696, they deduce that it is 0.4142135623730950488016887242096980785696. The square root of 16 is calculated to be 0 (obviously an error).


The erroneous ciphering does, however, lead to an interesting question. Given a string of digits of length L (1 ≤ L ≤ 9), what is the smallest integer whose bovine square root decimal part begins with those digits?


By way of example, consider the string "123". The square root of 17 is approximately 4.1231056256176605498214098559740770251472 so the bovine square root is: 0.1231056256176605498214098559740770251472 whose decimal part (just after the period) starts with 123. It turns out that 17 is the smallest integer with this property.

## 예제 입력 1
```
3
123
```

## 예제 출력 1
```
17
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 1 | Python 3 / 수정 | 36616 KB | 1004 ms | 847 B | 3년 전 |
