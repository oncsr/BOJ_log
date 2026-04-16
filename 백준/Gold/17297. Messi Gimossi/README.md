# [17297. Messi Gimossi](https://www.acmicpc.net/problem/17297)

## 문제
메시
는 축구 선수이다. 메시는 기분이 좋다.


messi(1): 
Messi


messi(2)​​: 
Messi Gimossi


messi(3)​​​​​​: 
Messi Gimossi Messi


messi(4): 
Messi Gimossi Messi Messi Gimossi


messi(5): 
Messi Gimossi Messi Messi Gimossi
 
Messi Gimossi Messi


메시의 외침은 피보나치 수열과 유사하게 정의된다. messi(N)은 messi(N-1), 공백, messi(N-2)을 차례로 이어붙여서 만든 문자열이다.


욱제는 N이 충분히 클 때, messi(N)의 M번째 글자가 뭔지 궁금해졌다.

## 예제 입력 1
```
1
```

## 예제 출력 1
```
M
```

## 예제 입력 2
```
20
```

## 예제 출력 2
```
Messi Messi Gimossi
```

## 예제 입력 3
```
1073741823
```

## 예제 출력 3
```
G
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 4 | Java 15 / 수정 | 14332 KB | 108 ms | 1221 B | 3달 전 |
