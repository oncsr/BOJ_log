# [32578. Pray Mink](https://www.acmicpc.net/problem/32578)

## 문제
Aaron, the mink, has two loves: biscuits and prime numbers. Growing up on our farm, he developed a special fondness for both. In the kitchen, he has cookie cutters shaped like the digits $0$ through $9$. He fills them with dough, bakes the digits, and arranges them in a row on a tray to form a whole positive number.


Recently, Aaron managed to bake and arrange a prime number. After admiring it, he got hungry and ate one of the digit-biscuits. Without rearranging the remaining digits, he simply shifted them left or right to fill the gap. To his delight, the new number was still prime!


Now, Aaron is curious to see how many prime numbers he can find in a row through this process. Each time, he eats a digit, shifts the remaining ones, and checks if the new number is prime. If leading zeros appear after eating a digit, he happily eats those as well right away. However, if at any point the resulting number is not prime, the process ends immediately.


Today, Aaron baked a new set of digits and formed a new number, not necessarily prime. Aaron’s goal is to see the maximum number of prime numbers in a row, starting with the initial number and continuing for as long as possible.


Your task is to compute the maximum possible number of occurrences of prime numbers in this process.

## 예제 입력 1
```
773
```

## 예제 출력 1
```
3
```

## 예제 입력 2
```
300007
```

## 예제 출력 2
```
2
```

## 예제 입력 3
```
11
```

## 예제 출력 3
```
1
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Silver 2 | C++17 / 수정 | 2020 KB | 0 ms | 574 B | 1년 전 |
