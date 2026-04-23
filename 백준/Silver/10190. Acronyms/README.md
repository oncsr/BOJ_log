# [10190. Acronyms](https://www.acmicpc.net/problem/10190)

## 문제
There are many acronyms that have the same letters with different meanings. For example, ISS could mean International Space Station, In School Suspension, Interstate Sporadic Squabbles, but it could not be Institutional Saliva Tester (IST, not ISS) nor could it be Intermural Sports Situational Comedies (ISSC not ISS).


Determine whether or not phrases fit the acronym, with the correct number of words and beginning letters. All words will begin with capital letters.

## 예제 입력 1
```
4
ABC 4
American Broadcasting Company
Another Boring Computer Program
Alpha Beta Gamma
Another Brilliant Csteacher
UIL 3
Union Leaders Invitation
University Interscholastic League
Upstanding Important Leaders
CIA 4
Central Intelligence Agency
Computer Image Advertising
Coming In After Christmas
Clubbing Intelligent Aardvarks
TBBT 7
The Big Bang Theory
The Big Bama Tide
Two Boolean Byte TreeMaps
Thing Without An Important Name
Tuning Big Brass Tubas
This Bytes Big Boogies Totally
Disk Operating System
```

## 예제 출력 1
```
ABC
American Broadcasting Company
Another Brilliant Csteacher
UIL
University Interscholastic League
Upstanding Important Leaders
CIA 
Central Intelligence Agency
Computer Image Advertising
Clubbing Intelligent Aardvarks
TBBT
The Big Bang Theory
The Big Bama Tide
Two Boolean Byte TreeMaps
Tuning Big Brass Tubas
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Silver 5 | C++17 / 수정 | 2024 KB | 0 ms | 473 B | 3년 전 |
