# [29738. Goodbye, Code Jam](https://www.acmicpc.net/problem/29738)

## 문제
매년 4~5월은 Google Code Jam이 열리는 기간이다. 슬프게도 Google은 2023년부터 Code Jam, Kick Start, Hash Code 등 다양한 형태로 운영해 왔던 Google Coding Competition을 종료하기로 했다. 더 이상 티셔츠를 받을 수 없다는 사실에 절망한 브실이는 Google Code Jam을 기억하는 문제를 만들기로 했다.


Google Code Jam은 Qualification Round, Round 1, Round 2, Round 3, World Finals의 순서로 진행된다. 30점 이상을 획득하면 다음 라운드로 진출하는 Qualification Round와 더 이상 다음 라운드가 없는 
World Finals
을 제외한 라운드는 다음 라운드에 진출하기 위해선 정해진 순위 안에 들어야 한다. 각각 
Round 1
은 상위 $4\,500$등, 
Round 2
는 상위 $1\,000$등, 
Round 3
은 상위 $25$등 안에 들어야 다음 라운드에 진출할 수 있다.


입력으로 Google Code Jam 참가자가 가장 마지막으로 참가한 라운드의 등수 $N$이 주어진다. 해당 참가자가 가장 마지막으로 참가한 라운드를 출력하라. 단 문제에서 주어지는 참가자는 Qualification Round는 모두 통과했다고 가정하므로 출력해야 할 라운드는 
Round 1
, 
Round 2
, 
Round 3
, 
World Finals
 중 하나이다. 모든 참가자는 Google Code Jam에 참가하기만을 손꼽아 기다려 왔기 때문에 참가자가 등수 미달로 탈락하는 경우가 아닌 이상 중도 포기를 하는 경우는 없다.

## 예제 입력 1
```
4
10000
1234
567
8
```

## 예제 출력 1
```
Case #1: Round 1
Case #2: Round 2
Case #3: Round 3
Case #4: World Finals
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Bronze 4 | C++17 / 수정 | 2020 KB | 0 ms | 356 B | 2년 전 |
