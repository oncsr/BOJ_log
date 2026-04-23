# [10184. Coupon2](https://www.acmicpc.net/problem/10184)

## 문제
When you go shopping and have coupons, you can only get discounts on the items you actually purchased. Before UPC codes and scanners, it was up to the cashier to check for purchases and to verify if the coupons were for valid purchases. Here is some information on UPC codes:




(http://cdn.vouchercodes.ca/wp-content/uploads/2012/05/anatomy-of-a-upc.jpg)


In this program, you will have a receipt showing the UPC codes and prices. Then you will be given a list of coupons with UPC code and discount. Apply the discount to valid purchases. The UPC codes will be a 12 digit numeric sequence and the price will have no dollar sign on input.

## 예제 입력 1
```
3
1 1
000000123456 19.99
000000123456 0.10
5 2
000000123456 19.99
000000123457 10.00
000000123458 20.00
000000123459 30.00
000000123460 40.00
000000123456 0.10
000000123459 0.20
5 2
000000123456 19.99
000000123457 10.00
000000123458 20.00
000000123459 30.00
000000123460 40.00
000000123456 0.10
000000999999 0.20
```

## 예제 출력 1
```
17.99
111.99
117.99
INVALID COUPONS
000000999999
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Silver 4 | C++17 / 수정 | 2032 KB | 0 ms | 578 B | 3년 전 |
