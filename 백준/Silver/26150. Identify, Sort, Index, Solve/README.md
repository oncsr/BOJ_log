# [26150. Identify, Sort, Index, Solve](https://www.acmicpc.net/problem/26150)

## 문제
ISIS Puzzle은 "Identify, Sort, Index, Solve"의 절차로 푸는 퍼즐을 통칭한다.


퍼즐을 좋아하는 하이비는 HCPC에 아래와 같은 ISIS 퍼즐 문제를 내기로 했다.




$ N $개의 문자열 $ S_1, S_2, \ldots, S_N $이 주어진다.


Identify: 각 문자열과 대응되는 문제의 제목을 알아낸 뒤, 그 문제의 번호 $ I_i $와 난이도 $ D_i $를 알아낸다.


Sort: 문제들을 번호 $ I_i $의 오름차순으로 정렬한다.


Index: 각 문제 이름 $ S_i $에서 $ D_i $번째의 글자를 추출한다. 
이때 추출된 글자가 소문자라면 대문자로 변환한다.


Solve: Index 단계에서 추출한 글자들을 Sort 단계에서 정렬한 순서대로 나열한다.




하지만 Identify는 구현이 어려울 것이라고 생각해, Identify까지 완료된 자료를 주기로 했다.


Identify가 완료된 자료가 주어질 때, Sort, Index, Solve까지 완료한 뒤 나오는 문자열을 출력해보자.

## 예제 입력 1
```
8
Ep2ascii 7 3
Xtreme2s 5 7
AndAHalf 1 5
May2Year 8 4
PCMaudio 3 1
Logicism 2 5
Electric 4 8
2048Half 6 2
```

## 예제 출력 1
```
HCPC2022
```

## 예제 입력 2
```
10
BearAndThreeMusketeers 1661 9
GlebAndPizza 1441 7
LittleElephantAndInversions 2662 19
NewYearBookReading 1991 13
PalindromesColoring 2332 16
PashmakAndParmidasProblem 2442 15
SendingASequenceOverTheNetwork 3003 7
TextVolume 1221 10
TheHardWorkOfPaparazzi 2112 10
VotingForPhotos 808 9
```

## 예제 출력 2
```
REDHERRING
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Silver 5 | C++17 / 수정 | 2024 KB | 0 ms | 377 B | 3년 전 |
