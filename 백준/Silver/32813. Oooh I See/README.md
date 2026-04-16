# [32813. Oooh I See](https://www.acmicpc.net/problem/32813)

## 문제
Captain O'Capten has hidden some treasure and created a map to mark where it is buried. Rather than using 'X' to mark the spot, he has decided to obfuscate the location by using a grid of uppercase 
O
 (the letter 
O
) characters and 
0
 (the number 
0
) characters. The treasure's position is given by the location of a 
0
 character surrounded on all sides by $8$ 
O
 characters. That is, a 
0
 character with an 
O
 immediately above, below, to the left, to the right, diagonally above to the left, diagonally above to the right, diagonally below to the left, and diagonally below to the right.


Captain O'Capten wants to recover the location of his treasure but he is finding his map hard to read (huh, go figure). Help Captain O'Capten find the location of his treasure, or exclaim 
Oh no!
 if such a location is not marked on the map or there is more than one such location.

## 예제 입력 1
```
3 6
OO0OOO
00OO0O
0O0OOO
```

## 예제 출력 1
```
2 5
```

## 예제 입력 2
```
5 3
OOO
O0O
OOO
O0O
OOO
```

## 예제 출력 2
```
Oh no! 2 locations
```

## 예제 입력 3
```
4 4
OOO0
0O0O
OOO0
0O0O
```

## 예제 출력 3
```
Oh no!
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Silver 5 | C++17 / 수정 | 2020 KB | 0 ms | 692 B | 1년 전 |
