# [31422. AND, OR, XOR 2](https://www.acmicpc.net/problem/31422)

## 문제
음이 아닌 정수로 이루어진 길이 $N$의 수열 $A_1, A_2, \cdots, A_N$이 주어진다.


$\land, \lor, \oplus$를 각각 Bitwise AND, OR, XOR 연산자로 정의하자. 다음 세 값을 $998\,244\,353$으로 나눈 나머지를 각각 구하여라. $998\,244\,353$은 소수이다.


\[\sum_{i=1}^{N} \sum_{j=i}^{N} \left(A_i \land A_{i+1} \land \cdots \land A_j\right), \qquad \sum_{i=1}^{N} \sum_{j=i}^{N} \left(A_i \lor A_{i+1} \lor \cdots \lor A_j\right), \qquad \sum_{i=1}^{N} \sum_{j=i}^{N} \left(A_i \oplus A_{i+1} \oplus \cdots \oplus A_j\right)\]

## 예제 입력 1
```
3
1 2 3
```

## 예제 출력 1
```
8 15 10
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Platinum 5 | Java 11 / 수정 | 64324 KB | 704 ms | 2579 B | 7달 전 |
