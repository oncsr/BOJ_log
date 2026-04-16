# [7432. 디스크 트리](https://www.acmicpc.net/problem/7432)

## 문제
갑자기 맥북이 상근이의 손에서 떨어졌고, 화면이 켜지지 않았다. AS센터에 문의해보니 수리비가 97만원이 나왔고, 상근이는 큰 혼란에 빠졌다. 돈도 중요하지만, 상근이는 그 속에 들어있는 파일이 걱정되기 시작했다. 다행히 상근이는 저장되어 있는 중요한 디렉토리의 전체 경로를 텍스트 파일로 따로 저장하고 있었다. 예를 들면, WINNT\SYSTEM32\CERTSRV\CERTCO~1\X86. 


상근이의 중요한 디렉토리의 전체 경로가 모두 주어졌을 때, 디렉토리 구조를 구해 보기 좋게 출력하는 프로그램을 작성하시오.

## 예제 입력 1
```
7
WINNT\SYSTEM32\CONFIG
GAMES
WINNT\DRIVERS
HOME
WIN\SOFT
GAMES\DRIVERS
WINNT\SYSTEM32\CERTSRV\CERTCO~1\X86
```

## 예제 출력 1
```
GAMES
 DRIVERS
HOME
WIN
 SOFT
WINNT
 DRIVERS
 SYSTEM32
  CERTSRV
   CERTCO~1
    X86
  CONFIG
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 3 | Java 11 / 수정 | 24872 KB | 252 ms | 1713 B | 1년 전 |
