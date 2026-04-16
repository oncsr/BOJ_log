# [16402. 제국](https://www.acmicpc.net/problem/16402)

## 문제
배성일력 73년, 대륙을 주름잡던 성일 제국은 무리한 정복 전쟁 끝에 멸망하게 되었다. 기회를 노리던 반란군들은 혼란을 틈타 제각각 왕국을 선포했고, 왕국들은 제국의 자리를 차지하기 위해 수많은 전쟁을 치르게 되었다.


전쟁은 다음과 같은 방식으로 진행된다.


다른 왕국의 속국이 아닌 왕국은 자신의 속국이 아닌 다른 왕국을 공격하여 전쟁을 벌일 수 있다. 만약 전쟁에서 승리한다면 그 왕국과 그 왕국의 속국들을 전부 자신의 속국으로 삼게 된다. 때로는 다른 왕국의 속국을 공격하는 경우도 있는데, 이 경우 그 왕국의 종주국(그 왕국을 거느린 왕국)은 그 왕국을 지키기 위해 지원을 아끼지 않는다. 따라서 여기서 승리한다면 빈털터리가 된 종주국과 그 속국들까지도 전부 자신의 속국으로 삼을 수 있다. 그러나 전쟁에서 패배한다면 자신과 자신의 속국들이 전부 상대 왕국(만약 다른 왕국의 속국이라면 그 종주국)의 속국으로 넘어가게 된다.


속국은 기본적으로 다른 왕국을 공격할 수 없지만, 한 가지 예외가 있다. 바로 자신의 종주국을 공격하는 것이다. 만약 이 전쟁에서 속국이 승리한다면 속국 신세에서 벗어나 종주국이었던 왕국과 그 속국들을 속국으로 삼게 된다. 그러나 종주국이 승리한다면 아쉽게도 아무 일도 일어나지 않는다.


왕국들의 이름과 두 왕국의 전쟁 결과들이 주어질 때, 모든 전쟁이 끝난 후 속국이 아닌 왕국들의 수와 속국이 아닌 각 왕국의 이름을 출력하라.

## 예제 입력 1
```
5 2
Kingdom of A
Kingdom of B
Kingdom of C
Kingdom of D
Kingdom of E
Kingdom of A,Kingdom of B,1
Kingdom of C,Kingdom of D,2
```

## 예제 출력 1
```
3
Kingdom of A
Kingdom of D
Kingdom of E
```

## 예제 입력 2
```
5 5
Kingdom of A
Kingdom of B
Kingdom of C
Kingdom of D
Kingdom of E
Kingdom of A,Kingdom of B,2
Kingdom of C,Kingdom of D,1
Kingdom of E,Kingdom of C,2
Kingdom of C,Kingdom of D,2
Kingdom of D,Kingdom of E,2
```

## 예제 출력 2
```
2
Kingdom of B
Kingdom of E
```

## 예제 입력 3
```
5 4
Kingdom of A
Kingdom of B
Kingdom of C
Kingdom of D
Kingdom of E
Kingdom of A,Kingdom of B,2
Kingdom of C,Kingdom of D,1
Kingdom of E,Kingdom of C,2
Kingdom of A,Kingdom of C,1
```

## 예제 출력 3
```
1
Kingdom of B
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 2 | C++17 / 수정 | 2176 KB | 4 ms | 1185 B | 1년 전 |
