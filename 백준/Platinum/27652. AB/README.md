# [27652. AB](https://www.acmicpc.net/problem/27652)

## 문제
집합 $A, B$와 문자열 $S$에 대하여, 다음 쿼리를 수행하는 프로그램을 작성하시오.




add A
 $S$: $A$에 $S$를 추가한다.


delete A
 $S$: $A$에서 $S$를 제거한다.


add B
 $S$: $B$에 $S$를 추가한다.


delete B
 $S$: $B$에서 $S$를 제거한다.


find
 $S$: $A$의 원소의 
접두사
와 $B$의 원소의 
접미사
를 이어 붙여 $S$가 되는 경우의 수를 출력한다. 원소가 다르거나 접두사(접미사)가 다르면 다른 경우로 센다. 빈 접두사(접미사)는 고려하지 않는다.




초기에 $A, B$는 비어있으며, 이미 존재하는 원소를 추가하거나 존재하지 않는 원소를 제거하는 쿼리는 주어지지 않는다.

## 예제 입력 1
```
7
add A aba
add A a
add A ab
add B bab
add B b
add B ab
find abab
```

## 예제 출력 1
```
10
```

## 예제 입력 2
```
8
add A a
add B bcd
add A ab
add B cd
find abcd
delete A a
delete B bcd
find abcd
```

## 예제 출력 2
```
4
1
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Platinum 5 | C++17 / 수정 | 584152 KB | 1100 ms | 1093 B | 5달 전 |
