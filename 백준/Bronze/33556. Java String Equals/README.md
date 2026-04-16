# [33556. Java String Equals](https://www.acmicpc.net/problem/33556)

## 문제
Java에서 두 문자열을 비교하는 경우 대소문자를 구분해서 비교하는 
equals()
와 대소문자를 구분하지 않고 비교하는 
equalsIgnoreCase()
를 사용한다. 
"a".equals("a")
의 경우 
true
, 
"a".equals("A")
의 경우 
false
를 반환하지만, 
"a".equalsIgnoreCase("A")
의 경우 
true
를 반환한다.


한편, Java에서는 값이 존재하지 않는 상황을 나타내기 위해 객체 
null
을 사용한다. $A$를 기준 문자열, $B$를 비교 문자열이라고 할 때, 
A.equals(B)
와 
A.equalsIgnoreCase(B)
에서 $A$가 객체 
null
인 경우에는 
NullPointerException이 발생한다.
 그러나 $A$가 객체 
null
이 아니고, $B$가 객체 
null
인 경우에는 NullPointerException이 발생하지 않는다.


두 문자열 $A$와 $B$가 주어졌을 때, 
A.equals(B)
와 
A.equalsIgnoreCase(B)
의 결과를 출력해 보자. 단, 주어진 문자열이 "
null
"인 경우 
객체 null이 주어진 것으로 인식한다.

## 예제 입력 1
```
lms0806
lms0806
```

## 예제 출력 1
```
true
true
```

## 예제 입력 2
```
lms0806
Ims0806
```

## 예제 출력 2
```
false
false
```

## 예제 입력 3
```
lms0806
Lms0806
```

## 예제 출력 3
```
false
true
```

## 예제 입력 4
```
null
lms0806
```

## 예제 출력 4
```
NullPointerException
NullPointerException
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Bronze 1 | Java 11 / 수정 | 14260 KB | 104 ms | 1137 B | 1년 전 |
