# [13892. ACM Tax](https://www.acmicpc.net/problem/13892)

## 문제
Mr. Peter lives in the magical lands of ACM City. The city consists of N districts and N – 1 two-way roads. Each road connects a pair of districts, and for each road we know the length of the road. All districts are connected to each other, meaning Mr. Peter can always travel from any district A to any district B.


The ACM City has a very special rule for travelling. If anyone wants to travel from district A to district B, they must pay the tax equal to the median of the length of all roads from district A to district B. For example, this ACM City of 6 districts.




All circles represent districts and lines represent roads connecting two districts. Numbers inside the circles are the number of each district and numbers above the lines are the length of each road. If Mr. Peter travels from district 1 to district 3, the length of all roads would be 1, 5, and 9, therefore he must pay the tax of 5 dollars. However, if Mr. Peter travels from district 6 to district 4, he must pay 4.5 dollars, for the length of the roads are 1, 4, 5, and 7.


Mr. Peter is a very curious person. He wants to know the tax he needs to pay to travel from any two districts. However, Mr. Peter is too lazy to calculate the tax himself, so he asks you, the best programmer in the city, to calculate the tax Mr. Peter needs to pay from district A to district B.


Note: The ‘Median’ is the middle value of a sorted list of numbers. For example, the median of the list 1, 5, 7, 7, 9, 10, 16 is 7. If the amount of numbers in the list is even, the median is the sum of two middle numbers divided by 2. For example, the median of the list 1, 5, 7, 9, 10, 17, 28, 30 is (9+10)/2, which is 9.5.


Given the ACM City of N districts, for each question, find the median of the length of all path from district A to district B.

## 예제 입력 1
```
1
6
1 2 9
2 5 5
2 4 7
3 5 1
3 6 4
3
1 3
4 6
2 6
```

## 예제 출력 1
```
5.0
4.5
4.0
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Diamond 5 | Java 15 / 수정 | 358048 KB | 6692 ms | 6987 B | 1달 전 |
