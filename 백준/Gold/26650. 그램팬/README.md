# [26650. 그램팬](https://www.acmicpc.net/problem/26650)

## 문제
팬그램(pangram)이란 알파벳의 모든 문자가 최소 한 번씩 등장하는 문자열을 말한다. 팬그램의 예시로는 "The quick brown fox jumps over the lazy dog", "The five boxing wizards jump quickly"등이 있다. 팬그램은 그 자체로 충분히 아름다운 문자열이지만, 래오는 팬그램 중에서도 모든 알파벳이 순서대로 나열된 팬그램만이 아름답다고 생각해 이를 
그램팬
이라 부르기로 했다.


예를 들어 "ABBCDEFGGHIJKLMNOPQRSSTUVWXYZ"는 그램팬이며,  "BABCDEFGHIJKLMNOPQRSTUVWXYZ", "ABCADEFGHIJKLMNOPQRSTUVWXYZ"은 팬그램이지만 그램팬은 아니다.


어느 날 북과고 컴퓨터실 구석에서 문자열 $S$를 발견한 래오는 $S$의 부분 문자열 중 그램팬인 것의 개수가 궁금해졌다. 래오를 위해 이를 계산하는 프로그램을 작성해보자.


문자열 $S$의 부분 문자열이란, 문자열의 연속된 일부를 의미한다. 부분 문자열 중 같은 것이 있더라도 기존 문자열에서의 위치가 다르다면 다른 것으로 센다.

## 예제 입력 1
```
ABCDEFGHIJKLMNOPQRSTUVWXYZ
```

## 예제 출력 1
```
1
```

## 예제 입력 2
```
ABCDEFGHIJKLMNOPQRSTUVWXYYYZZZ
```

## 예제 출력 2
```
3
```

## 예제 입력 3
```
THEQUICKBROWNFOXJUMPSOVERTHELAZYDOG
```

## 예제 출력 3
```
0
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 5 | C++17 / 수정 | 2300 KB | 0 ms | 460 B | 1년 전 |
