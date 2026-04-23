# [8145. Megalopolis](https://www.acmicpc.net/problem/8145)

## 문제
Byteotia has been eventually touched by globalisation, and so has Byteasar the Postman, who once roamed the country lanes amidst sleepy hamlets and who now dashes down the motorways. But it is those strolls in the days of yore that he reminisces about with a touch of tenderness.


In the olden days n Byteotian villages (numbered from 1 to n) were connected by bidirectional dirt roads in such a way, that one could reach the village number 1 (called Bitburg) from any other village in exactly one way. This unique route passed only through villages with number less or equal to that of the starting village. Furthermore, each road connected exactly two distinct villages without passing through any other village. The roads did not intersect outside the villages, but tunnels and viaducts were not unheard of.


Time passing by, successive roads were being transformed into motorways. Byteasar remembers distinctly, when each of the country roads so disappeared. Nowadays, there is not a single country lane left in Byteotia - all of them have been replaced with motorways, which connect the villages into Byteotian Megalopolis.


Byteasar recalls his trips with post to those villages. Each time he was beginning his journey with letters to some distinct village in Bitburg. He asks you to calculate, for each such journey (which took place in a specific moment of time and led from Bitburg to a specified village), how many country roads it led through.



Write a programme which:




reads from the standard input:
	


descriptions of roads that once connected Byteotian villages,


sequence of events: Byteasar's trips and the moments when respective roads were transformed into motorways,






for each trip, calculates how many country roads Byteasar has had to walk,


writes the outcome to the standard output.

## 예제 입력 1
```
5
1 2
1 3
1 4
4 5
4
W 5
A 1 4
W 5
A 4 5
W 5
W 2
A 1 2
A 1 3
```

## 예제 출력 1
```
2
1
0
1
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Platinum 2 | C++17 / 수정 | 37408 KB | 492 ms | 1883 B | 3년 전 |
