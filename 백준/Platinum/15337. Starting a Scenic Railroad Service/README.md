# [15337. Starting a Scenic Railroad Service](https://www.acmicpc.net/problem/15337)

## 문제
Jim, working for a railroad company, is responsible for planning a new tourist train service. He is sure that the train route along a scenic valley will arise a big boom, but not quite sure how big the boom will be.


A market survey was ordered and Jim has just received an estimated list of passengers’ travel sections. Based on the list, he’d like to estimate the minimum number of train seats that meets the demand.


Providing as many seats as all of the passengers may cost unreasonably high. Assigning the same seat to more than one passenger without overlapping travel sections may lead to a great cost cutback.


Two different policies are considered on seat assignments. As the views from the train windows depend on the seat positions, it would be better if passengers can choose a seat. One possible policy (named ‘policy-1’) is to allow the passengers to choose an arbitrary seat among all the remaining seats when they make their reservations. As the order of reservations is unknown, all the possible orders must be considered on counting the required number of seats.


The other policy (named ‘policy-2’) does not allow the passengers to choose their seats; the seat assignments are decided by the railroad operator, not by the passengers, after all the reservations are completed. This policy may reduce the number of the required seats considerably.


Your task is to let Jim know how different these two policies are by providing him a program that computes the numbers of seats required under the two seat reservation policies.


Let us consider a case where there are four stations, S1, S2, S3, and S4, and four expected passengers p1, p2, p3, and p4 with the travel list below.




The travel sections of p1 and p2 do not overlap, that of p3 overlaps those of p1 and p2, and that of p4 does not overlap those of any others.


Let’s check if two seats would suffice under the policy-1. If p1 books a seat first, either of the two seats can be chosen. If p2 books second, as the travel section does not overlap that of p1, the same seat can be booked, but the other seat may look more attractive to p2. If p2 reserves a seat different from that of p1, there will remain no available seats for p3 between S1 and S3 (Figure I.1).




Figure I.1. With two seats


With three seats, p3 can find a seat with any seat reservation combinations by p1 and p2. p4 can also book a seat for there are no other passengers between S3 and S4 (Figure I.2).




Figure I.2. With three seats


For this travel list, only three seats suffice considering all the possible reservation orders and seat preferences under the policy-1.


On the other hand, deciding the seat assignments after all the reservations are completed enables a tight assignment with only two seats under the policy-2 (Figure I.3).




Figure I.3. Tight assignment to two seats

## 예제 입력 1
```
4
1 3
1 3
3 6
3 6
```

## 예제 출력 1
```
2 2
```

## 예제 입력 2
```
4
1 2
2 3
1 3
3 4
```

## 예제 출력 2
```
3 2
```

## 예제 입력 3
```
10
84 302
275 327
364 538
26 364
29 386
545 955
715 965
404 415
903 942
150 402
```

## 예제 출력 3
```
6 5
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Platinum 3 | C++17 / 수정 | 35436 KB | 244 ms | 1950 B | 1년 전 |
